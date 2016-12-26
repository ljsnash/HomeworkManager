// Find.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "Find.h"
#include "afxdialogex.h"


// Find 对话框

IMPLEMENT_DYNAMIC(Find, CDialogEx)

Find::Find(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_Search, pParent)
{

}

Find::~Find()
{
}

void Find::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, rad_FindNormal, m_radio_FindNormal);
	DDX_Control(pDX, rad_FindExact, m_radio_FindExact);
	DDX_Control(pDX, list_Find, m_list_Find);
	m_list_Find.InsertColumn(0, "学号", 100, 100);
	m_list_Find.InsertColumn(1, "学生姓名", 100, 130);
	m_list_Find.InsertColumn(2, "作业提交情况", 100, 120);
	m_list_Find.InsertColumn(3, "作业文件", 100, 300);
	str_File = "";

}


BEGIN_MESSAGE_MAP(Find, CDialogEx)
	ON_BN_CLICKED(rad_FindNormal, &Find::OnBnClickedFindnormal)
	ON_BN_CLICKED(rad_FindExact, &Find::OnBnClickedFindexact)
	ON_BN_CLICKED(btn_FindOK, &Find::OnBnClickedFindok)
	ON_EN_CHANGE(edit_FindName, &Find::OnEnChangeFindname)
	ON_CBN_SELCHANGE(com_Find, &Find::OnCbnSelchangeFind)
	ON_BN_CLICKED(btn_FindBrowse, &Find::OnBnClickedFindbrowse)
	ON_NOTIFY(LVN_ITEMCHANGED, list_Find, &Find::OnLvnItemchangedFind)
	ON_STN_CLICKED(IDC_STATIC1, &Find::OnStnClickedStatic1)
	ON_EN_CHANGE(edit_FindNumber, &Find::OnEnChangeFindnumber)
	ON_EN_CHANGE(edit_Keyword, &Find::OnEnChangeKeyword)
	ON_STN_CLICKED(IDC_STATIC6, &Find::OnStnClickedStatic6)
END_MESSAGE_MAP()


// Find 消息处理程序


void Find::OnBnClickedFindnormal()
{
	// TODO: 在此添加控件通知处理程序代码
	bol_Find = false;
	CEdit *edit = (CEdit*)GetDlgItem(IDC_STATIC1);
	edit->ShowWindow(false);
    edit = (CEdit*)GetDlgItem(IDC_STATIC2);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(IDC_STATIC3);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(IDC_STATIC4);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(edit_FindName);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(edit_FindNumber);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(com_Find);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(btn_FindBrowse);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(IDC_STATIC6);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(edit_Keyword);
	edit->ShowWindow(true);
}


void Find::OnBnClickedFindexact()
{
	// TODO: 在此添加控件通知处理程序代码
	bol_Find = true;
	CEdit *edit = (CEdit*)GetDlgItem(IDC_STATIC1);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(IDC_STATIC2);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(IDC_STATIC3);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(IDC_STATIC4);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(edit_FindName);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(edit_FindNumber);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(com_Find);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(btn_FindBrowse);
	edit->ShowWindow(true);
	edit = (CEdit*)GetDlgItem(IDC_STATIC6);
	edit->ShowWindow(false);
	edit = (CEdit*)GetDlgItem(edit_Keyword);
	edit->ShowWindow(false);
}


void Find::OnBnClickedFindok()
{
	m_list_Find.DeleteAllItems();
	// TODO: 在此添加控件通知处理程序代码
	if (bol_Find == true)
	{
		for (int i = 0; i < 4; i++)
		{
			temp[i] = "";
		}

		GetDlgItemText(edit_FindName, temp[1]);
		GetDlgItemText(edit_FindNumber, temp[0]);
		GetDlgItemText(com_Find, temp[2]);
		if (temp[2] == "不限") temp[2] = "";
		temp[3] = str_File;
		int _temp[4];
		for (int j = 0; j < 4; j++)
		{
			if (temp[j] != "")
			{
				for (int i = 0; i < int_Total; i++)
				{
					bool bol_temp = false;
					if ((j == 0)&&(temp[j]==stu[i].GetStudentNumber()))
					{
						bol_temp = true;
						if ((temp[1] != "") && (temp[1] != stu[i].GetStudentName())) bol_temp = false;
						if ((temp[2] != "") && (temp[2] != stu[i].GetStudentCheck_str())) bol_temp = false;
						if ((temp[3] != "") && (temp[3] != stu[i].GetStudentFullFilePath())) bol_temp = false;
					}
					if ((j == 1) && (temp[j] == stu[i].GetStudentName()))
					{
						bol_temp = true;
						if ((temp[2] != "") && (temp[2] != stu[i].GetStudentCheck_str())) bol_temp = false;
						if ((temp[3] != "") && (temp[3] != stu[i].GetStudentFullFilePath())) bol_temp = false;
					}
					if ((j == 2) && (temp[j] == stu[i].GetStudentCheck_str()))
					{
						bol_temp = true;
						if ((temp[3] != "") && (temp[3] != stu[i].GetStudentFullFilePath())) bol_temp = false;
					}
					if ((j == 3) && (temp[j] == stu[i].GetStudentCheck_str()))
					{
						bol_temp = true;
					}
					if (bol_temp == true)
					{
						m_list_Find.InsertItem(0, stu[i].GetStudentNumber());
						m_list_Find.SetItemText(0, 1, stu[i].GetStudentName());
					}
				}
				break;
			}
		}

	}
	if (bol_Find == false)
	{
		CString temp;
		GetDlgItemText(edit_Keyword, temp);

	}
}


void Find::OnEnChangeFindname()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Find::OnCbnSelchangeFind()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Find::OnBnClickedFindbrowse()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog *FileDialog = new CFileDialog(TRUE,"","",NULL,"所有文件|*.*|");//设置打开文件对话框格式
	FileDialog->DoModal();//打开读取文件对话框
	str_File = FileDialog->GetPathName();//存储文件名
	delete FileDialog;
}


void Find::OnLvnItemchangedFind(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Find::OnStnClickedStatic1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Find::OnEnChangeFindnumber()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Find::OnEnChangeKeyword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Find::OnStnClickedStatic6()
{
	// TODO: 在此添加控件通知处理程序代码
}
