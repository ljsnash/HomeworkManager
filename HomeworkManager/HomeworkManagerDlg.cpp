
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
#include"Choose.h"
#include"Student.h"
#include <fstream>
#include<string>
#include<iostream>
#include"Find.h"
#include"NameList.h"
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
public:
	afx_msg void Ondelete();
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
	DDX_Control(pDX, list_InformationSheet, m_list_InformationSheet);
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
	ON_BN_CLICKED(btn_ChooseOK, &CHomeworkManagerDlg::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, list_HomeworkFilename, &CHomeworkManagerDlg::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, list_HomeworkFilename, &CHomeworkManagerDlg::OnDblclkListHomeworkfilename)
	ON_NOTIFY(LVN_ITEMCHANGED, list_InformationSheet, &CHomeworkManagerDlg::OnLvnItemchangedInformationsheet)
	ON_BN_CLICKED(btn_SyncHomework, &CHomeworkManagerDlg::OnBnClickedSynchomework)
	ON_BN_CLICKED(btn_ExportFile, &CHomeworkManagerDlg::OnBnClickedExportfile)
	ON_BN_CLICKED(btn_ImportFile, &CHomeworkManagerDlg::OnBnClickedImportfile)
	ON_NOTIFY(LVN_COLUMNCLICK, list_HomeworkFilename, &CHomeworkManagerDlg::OnLvnColumnclickHomeworkfilename)
	ON_BN_CLICKED(btn_SortUp, &CHomeworkManagerDlg::OnBnClickedSortup)
	ON_BN_CLICKED(btn_SortDown, &CHomeworkManagerDlg::OnBnClickedSortdown)
	ON_BN_CLICKED(btn_Find, &CHomeworkManagerDlg::OnBnClickedFind)
	ON_BN_CLICKED(btn_AddFile, &CHomeworkManagerDlg::OnBnClickedAddfile)
	ON_BN_CLICKED(btn_Statistics, &CHomeworkManagerDlg::OnBnClickedStatistics)
	ON_NOTIFY(NM_RCLICK, list_HomeworkFilename, &CHomeworkManagerDlg::OnNMRClickHomeworkfilename)
	ON_COMMAND(_delete, &CHomeworkManagerDlg::Ondelete)
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
	m_list_InformationSheet.DeleteAllItems();
	CHeaderCtrl* pHeaderCtrl = m_list_InformationSheet.GetHeaderCtrl();
	if (pHeaderCtrl != NULL)
	{
		int  nColumnCount = pHeaderCtrl->GetItemCount();
		for (int i = 0; i<nColumnCount; i++)
		{
			m_list_InformationSheet.DeleteColumn(0);
		}
	}
	CString str_FileName;
	GetDlgItemText(edit_PathSheet, str_FileName);
	IllusionExcelFile xlsx_StuInformation;//ʵ��������
	bool bol_Inti=xlsx_StuInformation.InitExcel();//��ʼ��
	bool bol_FileOpen = xlsx_StuInformation.OpenExcelFile(str_FileName);//���ļ�
	CString str_SheetName = xlsx_StuInformation.GetSheetName(1);
	bool bol_Load = xlsx_StuInformation.LoadSheet(str_SheetName);//Ԥ����
	int int_Row = xlsx_StuInformation.GetRowCount()-1;//��
	int_Total = int_Row;
	int int_Col = xlsx_StuInformation.GetColumnCount();//��
	CString str_Value;
	m_list_InformationSheet.InsertColumn(int_Col, "��ҵ�ύ���", 100, 120);
	for (int i = 0; i < int_Row; i++)
	{
		m_list_InformationSheet.InsertItem(i,"");
	}
	for (int i = 0; i < int_Col; i++)
	{
		str_Value = xlsx_StuInformation.GetCellString(1, i+1);
		m_list_InformationSheet.InsertColumn(i, str_Value, 100, 80);
		for (int j = 0; j < int_Row; j++)
		{
			str_Value = xlsx_StuInformation.GetCellString(j+2, i + 1);
			//m_list_InformationSheet.SetItemText(j, i, str_Value);
			if (j != stu[j].GetStudentID())
			{
				stu[j].SetStudentID(j);
				stu[j].SetStudentExist(true);
			}
			if (i == 0)
			{
				stu[j].SetStudentNumber(str_Value);
			}
			if (i == 1)
			{
				stu[j].SetStudentName(str_Value);
			}
		}
	}
	quickSort(stu, 0, int_Total-1);
	for (int j = 0; j < int_Row; j++)
	{
		m_list_InformationSheet.SetItemText(j, 0, stu[j].GetStudentNumber());
		m_list_InformationSheet.SetItemText(j, 1, stu[j].GetStudentName());
		stu[j].SetStudentID(j);
	}
	

	xlsx_StuInformation.CloseExcelFile(false);//�ر��ļ�
	xlsx_StuInformation.ReleaseExcel();//�ͷ��ڴ�	
}



void CHomeworkManagerDlg::OnBnClickedRegulatefilename()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_list_HomeworkFilename.SetItemText(0, 1, "123");
	int int_NumRow = m_list_HomeworkFilename.GetItemCount();
	int_Total2 = 0;
	for (int i = 0; i <int_NumRow; i++)
	{
		CString str_temp;
		str_temp =m_list_HomeworkFilename.GetItemText(i, 0) ;
		if (str_temp == "StudentFile.txt") continue;
		int temp_length = str_temp.GetLength();
		CString str_Path = m_list_HomeworkFilename.GetItemText(i, 3);
		CString str_Number="";
		CString str_Name= _T("");
		CString str_Tail="";
		CString str_New1="";
		CString str_New2 = "";
		CString str_Old= str_Path + "\\" + str_temp ;
		for (int j = 0; j<temp_length; j++)
		{
			if (str_temp.GetAt(j) == '.')
			{
				str_Tail = str_temp.Mid(j);
				break;
			}
			if (str_temp.GetAt(j) >= '0' && str_temp.GetAt(j) <= '9')
			{
				str_Number += str_temp.GetAt(j);
			}
			else
			{
				if ((UCHAR)str_temp.GetAt(j)<128) continue;
				str_Name += str_temp.Mid(j++, 2);
			}
		}
	//		m_list_HomeworkFilename.SetItemText(j, 1, stu[j].GetStudentName());
		
		int temp_Number = int_Total;
		int	temp_Name= int_Total;

		bool temp_check = false;

		for (int j = 0; j <int_Total; j++)
		{
			
			if (stu[j].GetStudentNumber() == str_Number)
			{
				temp_Number = j;
				if (stu[temp_Number].GetStudentName() == str_Name)
				{
					temp_Name = temp_Number;
				}
				else
				{
					for (int k = 0; k < int_Total; k++)
					{
						if (stu[k].GetStudentName() == str_Name)
						{
							temp_Name = k;
						}
					}
				}
			}
			else if (stu[j].GetStudentName() == str_Name)
			{
				temp_Name = j;
				if (stu[temp_Name].GetStudentNumber() == str_Number)
				{
					temp_Number = temp_Name;
				}
				else
				{
					for (int k = 0; k < int_Total; k++)
					{
						if (stu[k].GetStudentNumber() == str_Number)
						{
							temp_Number = k;
						}
					}
				}

			}

			if (temp_Number != temp_Name)
			{
				if  (temp_Name == int_Total)
				{
					if (stu[temp_Number].GetStudentExist() == true)
					{
						temp_Name = temp_Number;
						str_Name = stu[temp_Number].GetStudentName();
						//stu[stu[temp_Number].GetStudentID()].SetStudentCheck(true);
						temp_check = true;
					}
				}

				
				if (temp_Number  == int_Total)
				{
					if (stu[temp_Name].GetStudentExist() == true)
					{
						temp_Number = temp_Name;
						str_Number = stu[temp_Name].GetStudentNumber();
						//stu[stu[temp_Name].GetStudentID()].SetStudentCheck(true);
						temp_check = true;
					}					
				}
			}
			if ((temp_Number == temp_Name)&&(temp_Number!= int_Total)&&(int_Total!= temp_Name))
			{
				temp_check = true;
				stu[stu[temp_Number].GetStudentID()].SetStudentCheck(true);
				//m_list_InformationSheet.SetItemText(j, 2, stu[stu[temp_Number].GetStudentID()].GetStudentName());
			}	
		}
		if (temp_check == true)
		{
			str_New1 = str_Path + "\\" + str_Number + str_Name + str_Tail;
			str_New2 = str_Number + str_Name + str_Tail;
			rename(str_Old, str_New1);
			m_list_HomeworkFilename.SetItemText(i, 1, str_Name);
			m_list_HomeworkFilename.SetItemText(i, 2, str_Number);
			m_list_HomeworkFilename.SetItemText(i, 0, str_New2);
			stu[stu[temp_Number].GetStudentID()].SetStudentFile(str_New2);
			stu[stu[temp_Number].GetStudentID()].SetStudentPath(str_Path);
			int_Total2++;
		}
		if (temp_check == false)
		{
			str_New1 = str_Path + "\\" + "unnamed.txt";
			if (m_list_HomeworkFilename.GetItemText(i, 3) != m_list_HomeworkFilename.GetItemText(i - 1, 3))
			{
				ofstream fout(str_New1,ios::trunc);
				fout.close();
			}
			ofstream fout(str_New1, ios::app);
			fout << str_temp << endl;
			fout.close();
		}
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

		ShellExecute(NULL, NULL, str_FileName, NULL, NULL, SW_HIDE);
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

void CHomeworkManagerDlg::_ImportFile(CString str_FolderPath,ImportFile file)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (Check[i].data == 1)
		{
			file.GetAllFile(str_FolderPath, &m_list_HomeworkFilename, Check[i].type, 0,"unnamed.txt","StudentFile.txt");
		}
	}
	CString temp,str;
	str= str_Othertypes + ";";
	i = str.Find(";");
	SetDlgItemText(edit_PathSheet, temp);
	while ((i != -1) && (i != 0))
	{
		temp = str.Left(i);
		str = str.Mid(i + 1);
		file.GetAllFile(str_FolderPath, &m_list_HomeworkFilename, temp,0, "unnamed.txt", "StudentFile.txt");
		i = str.Find(";");
	};
}

void CHomeworkManagerDlg::OnBnClickedImportfolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str_FolderPath,str_ImportFirst;
	GetDlgItemText(edit_PathFolder, str_FolderPath);
	CString temp;
	GetDlgItemText(edit_PathSheet, temp);
	str_ImportFirst=m_list_HomeworkFilename.GetItemText(0, 0);
	ImportFile file;
	if (str_ImportFirst == "")
	{
		//file.GetAllFile(str_FolderPath, &m_list_HomeworkFilename,"txt");
		Choose choose;
		choose.DoModal();
		_ImportFile(str_FolderPath,file);
		
		/*while (Check != NULL)
		{

		}
		delete Head;*/
	}
	else
	{
		ImportType tip;
		if (tip.DoModal() == IDOK)
		{
			Choose choose;
			if (choose.DoModal() == IDOK)
			{
				if (bol_Importtype == true)
				{
					file.Initlistctrl(&m_list_HomeworkFilename);
					for (int i = 0; i < int_Total; i++)
					{
						stu[i].SetStudentCheck(false);
					}
					//_ImportFile(str_FolderPath, file);
				}
				_ImportFile(str_FolderPath, file);
			}
		}
	}
	//str_FileName = str_FolderPath + "\\*.txt";
	SetDlgItemText(edit_PathSheet, temp);

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
		ShellExecute(NULL, NULL, str_FileName, NULL, NULL, SW_SHOWNORMAL);
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
	NM_LISTVIEW *pNMListCtrl = (NM_LISTVIEW *)pNMHDR;  
	if (pNMListCtrl->iItem != -1) 
	{
		CString str_FileName;
		str_FileName = "\""+m_list_HomeworkFilename.GetItemText(pNMListCtrl->iItem, 3)+ "\\"+m_list_HomeworkFilename.GetItemText(pNMListCtrl->iItem, 0)+"\"";
		//system("call \"" + str_FileName + "\"");
		//SetDlgItemText(edit_PathSheet, str_FileName);
		ShellExecute(NULL, NULL, str_FileName, NULL, NULL,SW_SHOWNORMAL);
	}
}


void CHomeworkManagerDlg::OnLvnItemchangedInformationsheet(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CHomeworkManagerDlg::OnBnClickedSynchomework()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    for (int i = 0; i < int_Total; i++)
	{
		int id = stu[i].GetStudentID();
		m_list_InformationSheet.SetItemText(id, 2,stu[id].GetStudentCheck_str());
	}
}


void CHomeworkManagerDlg::OnBnClickedExportfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str_Path;
	GetDlgItemText(edit_PathFolder,str_Path);
	CString str_New1 = str_Path + "\\" + "StudentFile.txt";
	ofstream fout(str_New1, ios::trunc);
	fout << "ѧ�� | " << "���� | " << "��ҵ�ύ��� | " << "��ҵ�ļ� |" << endl;
	for (int i = 0; i < int_Total; i++)
	{
		fout << stu[i].GetStudentNumber() << " | " << stu[i].GetStudentName() << " |��" << stu[i].GetStudentCheck_str() << " ��" << stu[i].GetStudentFullFilePath() << endl;
	}
	fout.close();
	
}


void CHomeworkManagerDlg::OnBnClickedImportfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list_HomeworkFilename.DeleteAllItems();
	CFileDialog *FileDialog = new CFileDialog(TRUE, ".txt", "StudentFile.txt", NULL, "�ı��ĵ�|*.txt|�����ļ�|*.*||");//���ô��ļ��Ի����ʽ
	FileDialog->DoModal();//�򿪶�ȡ�ļ��Ի���
	CString str_FileName = FileDialog->GetPathName();//�洢�ļ���
	delete FileDialog;//�ͷ��ڴ�
	fstream fin(str_FileName);
	char *ch = "\\";
	//for (int i = 2; i < int_Total + 1; i++)
	{
		string _temp;
		int i = 0;
		if (fin) // �и��ļ�  
		{
			while (getline(fin, _temp)) // line�в�����ÿ�еĻ��з�  
			{
				if (i == 0)
				{
					i++;
					continue;
				}
				CString temp = _temp.c_str();
				int first = temp.Find("\\");
				int last = temp.ReverseFind(*ch);
				int length = temp.GetLength();
				if (length == last+1) continue;
				CString File = temp.Mid(last + 1);
				CString Path = temp.Mid(first - 2);
				last = Path.ReverseFind(*ch);
				Path = Path.Left(last);
				m_list_HomeworkFilename.InsertItem(i-1,File);
				m_list_HomeworkFilename.SetItemText(i-1, 3, Path);
				i++;
				
			}
		}
	}
}


void CHomeworkManagerDlg::OnLvnColumnclickHomeworkfilename(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int sort= pNMLV->iSubItem;

	*pResult = 0;
}


void CHomeworkManagerDlg::OnBnClickedSortup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < int_Total; i++)
	{
		m_list_InformationSheet.SetItemText(i, 0, stu[i].GetStudentNumber());
		m_list_InformationSheet.SetItemText(i, 1, stu[i].GetStudentName());
		m_list_InformationSheet.SetItemText(i, 2, stu[i].GetStudentCheck_str());
	}
	for (int i = 0; i < m_list_HomeworkFilename.GetItemCount(); i++)
	{
		if (m_list_HomeworkFilename.GetItemText(i, 1) != "")
		{
			m_list_HomeworkFilename.DeleteItem(i);
			i--;
		}
	}
	int j = 0;
	for (int i = 0; i <int_Total; i++)
	{
		if (stu[i].GetStudentCheck_bool() == true)
		{
			m_list_HomeworkFilename.InsertItem(i - j, stu[i].GetStudentFile());
			m_list_HomeworkFilename.SetItemText(i - j, 1, stu[i].GetStudentName());
			m_list_HomeworkFilename.SetItemText(i - j, 2, stu[i].GetStudentNumber());
			m_list_HomeworkFilename.SetItemText(i - j, 3, stu[i].GetStudentPath());
		}
		else
		{
			j++;
		}
	}
}


void CHomeworkManagerDlg::OnBnClickedSortdown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	for (int i = int_Total-1; i >=0; i--)
	{
		m_list_InformationSheet.SetItemText(int_Total-1-i, 0, stu[i].GetStudentNumber());
		m_list_InformationSheet.SetItemText(int_Total-1-i, 1, stu[i].GetStudentName());
		m_list_InformationSheet.SetItemText(int_Total - 1-i, 2, stu[i].GetStudentCheck_str());
	}
	for (int i = 0; i < m_list_HomeworkFilename.GetItemCount(); i++)
	{
		if (m_list_HomeworkFilename.GetItemText(i, 1) != "")
		{
			m_list_HomeworkFilename.DeleteItem(i);
			i--;
		}
	}
	int j = 0;
	for (int i = int_Total-1; i >=0; i--)
	{
		if (stu[i].GetStudentCheck_bool() == true)
		{
			m_list_HomeworkFilename.InsertItem(int_Total - 1-i - j, stu[i].GetStudentFile());
			m_list_HomeworkFilename.SetItemText(int_Total - 1 - i - j, 1, stu[i].GetStudentName());
			m_list_HomeworkFilename.SetItemText(int_Total - 1 - i - j, 2, stu[i].GetStudentNumber());
			m_list_HomeworkFilename.SetItemText(int_Total - 1 - i - j, 3, stu[i].GetStudentPath());
		}
		else
		{
			j++;
		}
	}

	
	
}


void CHomeworkManagerDlg::OnBnClickedFind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Find find;
	find.DoModal();	
}


void CHomeworkManagerDlg::OnBnClickedAddfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog *FileDialog = new CFileDialog(TRUE, "", "", NULL, "�����ļ�|*.*||");//���ô��ļ��Ի����ʽ
	FileDialog->DoModal();//�򿪶�ȡ�ļ��Ի���
	CString str_FullFilePath = FileDialog->GetPathName();//�洢�ļ���
	CString str_Filename = FileDialog->GetFileName();
	delete FileDialog;//�ͷ��ڴ�
	char *ch = "\\";
	int num = str_FullFilePath.ReverseFind(*ch);
	CString str_Filepath = str_FullFilePath.Left(num);
	num = m_list_HomeworkFilename.GetItemCount();
	m_list_HomeworkFilename.InsertItem(num, str_Filename);
	m_list_HomeworkFilename.SetItemText(num, 3, str_Filepath);

}


void CHomeworkManagerDlg::OnBnClickedStatistics()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int k=0;
	for (int i = 0; i < m_list_InformationSheet.GetItemCount(); i++)
	{
		k++;
		if (k == m_list_InformationSheet.GetItemCount())break;
		if (m_list_InformationSheet.GetItemText(i, 2) == "δ��")
		{
			int j = m_list_InformationSheet.GetItemCount();
			m_list_InformationSheet.InsertItem(j, m_list_InformationSheet.GetItemText(i, 0));
			m_list_InformationSheet.SetItemText(j, 1, m_list_InformationSheet.GetItemText(i, 1));
			m_list_InformationSheet.SetItemText(j, 2, "δ��");
			m_list_InformationSheet.DeleteItem(i);
			i--;
		}
	}
	NameList namelist;
	namelist.DoModal();

}


void CHomeworkManagerDlg::OnNMRClickHomeworkfilename(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_list_HomeworkFilename.GetSelectedCount() <= 0)
	{
		return;
	}
	*pResult = 0;
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	//�������δ���, ��������Ӧ��ListCtrl  
	DWORD dwPos = GetMessagePos();
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));
	CMenu menu;
	//����̲߳���  
	VERIFY(menu.LoadMenu(menu_Delete));           //������������1�ж����MENU���ļ�����  
	CMenu *popup = menu.GetSubMenu(0);
	//ASSERT(popup != NULL);
	popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}






void CHomeworkManagerDlg::Ondelete()
{
	// TODO: �ڴ���������������
	int int_Item = m_list_HomeworkFilename.GetSelectionMark();
	CString str_File = m_list_HomeworkFilename.GetItemText(int_Item, 0);
	CString str_Path = m_list_HomeworkFilename.GetItemText(int_Item, 3);
	CString str_Full = str_Path + "\\" + str_File;
	remove(str_Full);
	m_list_HomeworkFilename.DeleteItem(int_Item);
}
