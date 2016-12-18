
// HomeworkManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "HomeworkManagerDlg.h"
#include "afxdialogex.h"
#include"IllusionExcelFile.h"
#include"FolderPath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHomeworkManagerDlg 对话框



CHomeworkManagerDlg::CHomeworkManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HOMEWORKMANAGER_DIALOG, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHomeworkManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHomeworkManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_ImportInformation, &CHomeworkManagerDlg::OnBnClickedImportinformation)
	ON_BN_CLICKED(btn_RegulateFilename, &CHomeworkManagerDlg::OnBnClickedRegulatefilename)
END_MESSAGE_MAP()


// CHomeworkManagerDlg 消息处理程序

BOOL CHomeworkManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CHomeworkManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHomeworkManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHomeworkManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHomeworkManagerDlg::OnBnClickedImportinformation()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog *FileDialog=new CFileDialog(TRUE,".xlsx","学生信息表.xlsx",NULL, "Excel 工作簿|*.xlsx|Excel 97-2003工作簿|*.xls|所有文件|*.*||");//设置打开文件对话框格式
	FileDialog->DoModal();//打开读取文件对话框
	CString str_FileName = FileDialog->GetPathName();//存储文件名
	SetDlgItemText(btn_RegulateFilename, str_FileName);
	delete FileDialog;//释放内存
	IllusionExcelFile xlsx_StuInformation;//实例化对象
	xlsx_StuInformation.InitExcel();//初始化
	bool bol_FileOpen=xlsx_StuInformation.OpenExcelFile(str_FileName);//打开文件
	CString str_SheetName = xlsx_StuInformation.GetSheetName(1);	
	SetDlgItemText(btn_RegulateFilename, str_SheetName);
	xlsx_StuInformation.CloseExcelFile();//关闭文件
	xlsx_StuInformation.ReleaseExcel();//释放内存
	SetDlgItemText(btn_RegulateFilename, "Excel已关闭");
	
}



void CHomeworkManagerDlg::OnBnClickedRegulatefilename()
{
	// TODO: 在此添加控件通知处理程序代码
	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	FolderPath *path=new FolderPath("请选择学生作业所在文件夹");
	CString str_FolderPath = path->setFolderPath();
	delete path;
	SetDlgItemText(btn_ImportInformation, str_FolderPath);
		
}
