// Find.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "Find.h"
#include "afxdialogex.h"
#include<io.h>
#include<iostream>
#include <fstream>
using namespace std;

// Find �Ի���

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
	m_list_Find.InsertColumn(0, "ѧ��", 100, 100);
	m_list_Find.InsertColumn(1, "ѧ������", 100, 130);
	m_list_Find.InsertColumn(2, "��ҵ�ύ���", 100, 120);
	m_list_Find.InsertColumn(3, "��ҵ�ļ�", 100, 300);
	str_File = "";
	radio = (CButton*)GetDlgItem(rad_FindExact);
	radio->SetCheck(1);
	radio = (CButton*)GetDlgItem(rad_FindNormal);
	radio->SetCheck(0);

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
	ON_BN_CLICKED(btn_FindExport, &Find::OnBnClickedFindexport)
	ON_NOTIFY(NM_DBLCLK, list_Find, &Find::OnNMDblclkFind)
END_MESSAGE_MAP()


// Find ��Ϣ�������


void Find::OnBnClickedFindnormal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	radio = (CButton*)GetDlgItem(rad_FindExact);
	radio->SetCheck(0);
	radio = (CButton*)GetDlgItem(rad_FindNormal);
	radio->SetCheck(1);
}


void Find::OnBnClickedFindexact()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	radio = (CButton*)GetDlgItem(rad_FindExact);
	radio->SetCheck(1);
	radio = (CButton*)GetDlgItem(rad_FindNormal);
	radio->SetCheck(0);
}


void Find::OnBnClickedFindok()
{
	m_list_Find.DeleteAllItems();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (bol_Find == true)
	{
		for (int i = 0; i < 4; i++)
		{
			temp[i] = "";
		}

		GetDlgItemText(edit_FindName, temp[1]);
		GetDlgItemText(edit_FindNumber, temp[0]);
		GetDlgItemText(com_Find, temp[2]);
		if (temp[2] == "����") temp[2] = "";
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
					if ((j == 3) && (temp[j] == stu[i].GetStudentFullFilePath()))
					{
						bol_temp = true;
					}
					if (bol_temp == true)
					{
						m_list_Find.InsertItem(0, stu[i].GetStudentNumber());
						m_list_Find.SetItemText(0, 1, stu[i].GetStudentName());
						m_list_Find.SetItemText(0, 2, stu[i].GetStudentCheck_str());
						m_list_Find.SetItemText(0, 3, stu[i].GetStudentFullFilePath());
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
		for (int i = 0; i < int_Total; i++)
		{
			CString str;
			str=stu[i].GetStudentAll();
			int _temp = str.Find(temp);
			if (_temp != -1)
			{
				m_list_Find.InsertItem(0, stu[i].GetStudentNumber());
				m_list_Find.SetItemText(0, 1, stu[i].GetStudentName());
				m_list_Find.SetItemText(0, 2, stu[i].GetStudentCheck_str());
				m_list_Find.SetItemText(0, 3, stu[i].GetStudentFullFilePath());
			}
		}
	}
}


void Find::OnEnChangeFindname()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Find::OnCbnSelchangeFind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Find::OnBnClickedFindbrowse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog *FileDialog = new CFileDialog(TRUE,"","",NULL,"�����ļ�|*.*|");//���ô��ļ��Ի����ʽ
	FileDialog->DoModal();//�򿪶�ȡ�ļ��Ի���
	str_File = FileDialog->GetPathName();//�洢�ļ���
	delete FileDialog;
	OnBnClickedFindok();
}


void Find::OnLvnItemchangedFind(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void Find::OnStnClickedStatic1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Find::OnEnChangeFindnumber()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Find::OnEnChangeKeyword()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Find::OnStnClickedStatic6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Find::OnBnClickedFindexport()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog *FileDialog = new CFileDialog(FALSE, ".txt", "��ѯ.txt", NULL, "�ı��ĵ�|*.txt||");//���ô��ļ��Ի����ʽ
	FileDialog->DoModal();//�򿪶�ȡ�ļ��Ի���
	CString str_FileName = FileDialog->GetPathName();//�洢�ļ���
	delete FileDialog;//�ͷ��ڴ�
	ofstream fout (str_FileName, ios::trunc);
	fout << "ѧ�� " << "���� " << "��ҵ�ύ��� " << "��ҵ�ļ� " << endl;
	for (int i = 0; i < m_list_Find.GetItemCount(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fout << m_list_Find.GetItemText(i, j)<<" ";
		}
		fout << endl;
	}
	fout.close();
}


void Find::OnNMDblclkFind(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DWORD dwStyle = m_list_Find.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	dwStyle |= LVS_EX_UNDERLINEHOT;
	dwStyle |= LVS_EX_TWOCLICKACTIVATE;
	m_list_Find.SetExtendedStyle(dwStyle);
	*pResult = 0;
	NM_LISTVIEW *pNMListCtrl = (NM_LISTVIEW *)pNMHDR;
	if (pNMListCtrl->iItem != -1)
	{
		ShellExecute(NULL, NULL, m_list_Find.GetItemText(pNMItemActivate->iItem, 3), NULL, NULL, SW_SHOWNORMAL);
	}
}
