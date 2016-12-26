// NameList.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "NameList.h"
#include "afxdialogex.h"
#include<iostream>
#include<fstream>
using namespace std;


// NameList 对话框

IMPLEMENT_DYNAMIC(NameList, CDialogEx)

NameList::NameList(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_NameList, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

NameList::~NameList()
{
}

void NameList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, list_Namelist, m_list_NameList);
	m_list_NameList.InsertColumn(0, "已交", 100, 86);
	m_list_NameList.InsertColumn(1, "未交", 100, 85);
	int int_true = 0, int_false = 0;
	for (int i = 0; i < int_Total; i++)
	{
		m_list_NameList.InsertItem(i, "");
		if (stu[i].GetStudentCheck_bool() == true)
		{
			m_list_NameList.SetItemText(int_true, 0, stu[i].GetStudentName());
			int_true++;
		}
		if (stu[i].GetStudentCheck_bool() == false)
		{
			m_list_NameList.SetItemText(int_false, 1, stu[i].GetStudentName());
			int_false++;
		}
	}
}


BEGIN_MESSAGE_MAP(NameList, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, list_Namelist, &NameList::OnLvnItemchangedNamelist)
	ON_BN_CLICKED(btn_ImportNamelist, &NameList::OnBnClickedImportnamelist)
END_MESSAGE_MAP()


// NameList 消息处理程序


void NameList::OnLvnItemchangedNamelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void NameList::OnBnClickedImportnamelist()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog *FileDialog = new CFileDialog(FALSE, ".txt", "作业提交信息表.txt", NULL, "文本文档|*.txt||");//设置打开文件对话框格式
	FileDialog->DoModal();//打开读取文件对话框
	CString str_FileName = FileDialog->GetPathName();//存储文件名
	delete FileDialog;//释放内存
	ofstream fout(str_FileName, ios::trunc);
	fout << " 已交 |" << " 未交 "<< endl;
	for (int i = 0; i < m_list_NameList.GetItemCount(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			CString temp = m_list_NameList.GetItemText(i, j);
			if (temp == "") temp = "------|";
			fout << temp << " ";
		}
		fout << endl;
	}
	fout.close();
}
