
// HomeworkManagerDlg.cpp : ʵ���ļ�
//
#include "afxdialogex.h"
#include "stdafx.h"
#include "HomeworkManager.h"
#include "HomeworkManagerDlg.h"
#include"IllusionExcelFile.h"
#include"FolderPath.h"
#include<io.h>
#include"Tips.h"
#include"PathInvalid.h"
#include"ImportFile.h"
#include"ImportType.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CHomeworkManagerDlg �Ի���



CHomeworkManagerDlg::CHomeworkManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_Index, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHomeworkManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, list_HomeworkFilename, m_list_HomeworkFilename);
}

BEGIN_MESSAGE_MAP(CHomeworkManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_ImportInformation, &CHomeworkManagerDlg::OnBnClickedImportinformation)
	ON_BN_CLICKED(btn_RegulateFilename, &CHomeworkManagerDlg::OnBnClickedRegulatefilename)
	ON_BN_CLICKED(btn_BrowseSheet, &CHomeworkManagerDlg::OnBnClickedBrowsesheet)
	ON_EN_CHANGE(edit_PathSheet, &CHomeworkManagerDlg::OnEnChangePathsheet)
	ON_BN_CLICKED(btn_OpenSheet, &CHomeworkManagerDlg::OnBnClickedOpensheet)
	ON_BN_CLICKED(btn_BrowseFolder, &CHomeworkManagerDlg::OnBnClickedBrowsefolder)
	ON_BN_CLICKED(btn_ImportFolder, &CHomeworkManagerDlg::OnBnClickedImportfolder)
	ON_BN_CLICKED(btn_OpenFolder, &CHomeworkManagerDlg::OnBnClickedOpenfolder)
	ON_EN_CHANGE(edit_PathFolder, &CHomeworkManagerDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &CHomeworkManagerDlg::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, list_HomeworkFilename, &CHomeworkManagerDlg::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, list_HomeworkFilename, &CHomeworkManagerDlg::OnDblclkListHomeworkfilename)
END_MESSAGE_MAP()


// CHomeworkManagerDlg ��Ϣ�������

BOOL CHomeworkManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//m_list_HomeworkFilename.setColumn
	m_list_HomeworkFilename.InsertColumn(0, "�ļ���", 100, 80);
	m_list_HomeworkFilename.InsertColumn(1, "ѧ������", 100,90);
	m_list_HomeworkFilename.InsertColumn(2, "ѧ��", 100, 100);
	m_list_HomeworkFilename.InsertColumn(3, "�ļ�·��", 100, 150);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHomeworkManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHomeworkManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHomeworkManagerDlg::OnBnClickedImportinformation()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str_FileName;
	GetDlgItemText(edit_PathSheet, str_FileName);
	IllusionExcelFile xlsx_StuInformation;//ʵ��������
	xlsx_StuInformation.InitExcel();//��ʼ��
	xlsx_StuInformation.ShowInExcel(true);
	bool bol_FileOpen = xlsx_StuInformation.OpenExcelFile(str_FileName);//���ļ�
	CString str_SheetName = xlsx_StuInformation.GetSheetName(1);	
	xlsx_StuInformation.CloseExcelFile(false);//�ر��ļ�
	xlsx_StuInformation.ReleaseExcel();//�ͷ��ڴ�
	
}



void CHomeworkManagerDlg::OnBnClickedRegulatefilename()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int intItemNum = m_list_HomeworkFilename.GetItemCount();
	for (int i = 0; i < intItemNum; i++)
	{
		m_list_HomeworkFilename.SetItemText(i,3, "1111");
	}
}


void CHomeworkManagerDlg::OnBnClickedBrowsesheet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog *FileDialog = new CFileDialog(TRUE, ".xlsx", "ѧ����Ϣ��.xlsx", NULL, "Excel ������|*.xlsx|Excel 97-2003������|*.xls|�����ļ�|*.*||");//���ô��ļ��Ի����ʽ
	FileDialog->DoModal();//�򿪶�ȡ�ļ��Ի���
	CString str_FileName = FileDialog->GetPathName();//�洢�ļ���
	SetDlgItemText(edit_PathSheet, str_FileName);
	delete FileDialog;//�ͷ��ڴ�
}


void CHomeworkManagerDlg::OnEnChangePathsheet()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CHomeworkManagerDlg::OnBnClickedOpensheet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str_FileName;
	GetDlgItemText(edit_PathSheet, str_FileName);
	if (_access(str_FileName, 0) == 0)
	{
		system("call \""+str_FileName+"\"");
	}
	else
	{
		Tips tip;
		tip.DoModal();
	}

}


void CHomeworkManagerDlg::OnBnClickedBrowsefolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FolderPath *path = new FolderPath("��ѡ��ѧ����ҵ�����ļ���");
	CString str_FolderPath = path->setFolderPath();
	delete path;
	SetDlgItemText(edit_PathFolder, str_FolderPath);
}


void CHomeworkManagerDlg::OnBnClickedImportfolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str_FolderPath,str_ImportFirst;
	GetDlgItemText(edit_PathFolder, str_FolderPath);
	str_ImportFirst=m_list_HomeworkFilename.GetItemText(0, 0);
	ImportFile file;
	if (str_ImportFirst == "")
	{
		file.GetAllFile(str_FolderPath, &m_list_HomeworkFilename);
	}
	else
	{
		ImportType tip;
		tip.DoModal();
		if (bol_Importtype == true)
		{
			file.Initlistctrl(&m_list_HomeworkFilename);
		}
		file.GetAllFile(str_FolderPath, &m_list_HomeworkFilename);
	}
	//str_FileName = str_FolderPath + "\\*.txt";
	

}


void CHomeworkManagerDlg::OnBnClickedOpenfolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str_FileName;
	GetDlgItemText(edit_PathFolder, str_FileName);
	PathJudgement path;
	if (_access(str_FileName, 0) ==0)
	{
		//str_FileName = "\"" + str_FileName+"\"";
		system("start "+str_FileName);
	}
	else
	{
		Tips tip;
		tip.DoModal();
	}
	
}


void CHomeworkManagerDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CHomeworkManagerDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CHomeworkManagerDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CHomeworkManagerDlg::OnDblclkListHomeworkfilename(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DWORD dwStyle = m_list_HomeworkFilename.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	dwStyle |= LVS_EX_UNDERLINEHOT;
	dwStyle |= LVS_EX_TWOCLICKACTIVATE;
	m_list_HomeworkFilename.SetExtendedStyle(dwStyle);
	*pResult = 0;
	NM_LISTVIEW *pNMListCtrl = (NM_LISTVIEW *)pNMHDR;  if (pNMListCtrl->iItem != -1) 
	{
		CString str;   
		str = m_list_HomeworkFilename.GetItemText(pNMListCtrl->iItem, 3)+ "\\"+m_list_HomeworkFilename.GetItemText(pNMListCtrl->iItem, 0);
		system("call \"" + str + "\"");
	}
}
