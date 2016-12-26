// NameList.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "NameList.h"
#include "afxdialogex.h"
#include<iostream>
#include<fstream>
using namespace std;


// NameList �Ի���

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
	m_list_NameList.InsertColumn(0, "�ѽ�", 100, 86);
	m_list_NameList.InsertColumn(1, "δ��", 100, 85);
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


// NameList ��Ϣ�������


void NameList::OnLvnItemchangedNamelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void NameList::OnBnClickedImportnamelist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog *FileDialog = new CFileDialog(FALSE, ".txt", "��ҵ�ύ��Ϣ��.txt", NULL, "�ı��ĵ�|*.txt||");//���ô��ļ��Ի����ʽ
	FileDialog->DoModal();//�򿪶�ȡ�ļ��Ի���
	CString str_FileName = FileDialog->GetPathName();//�洢�ļ���
	delete FileDialog;//�ͷ��ڴ�
	ofstream fout(str_FileName, ios::trunc);
	fout << " �ѽ� |" << " δ�� "<< endl;
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
