// Choose.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "Choose.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include<iostream>
#include<sstream>
#include<string>
#include"ImportFile.h"
#include"HomeworkManagerDlg.h"
#include"FolderPath.h"
#include"PathInvalid.h"
using namespace std;
//using namespace CHomeworkManagerDlg;


// Choose �Ի���

IMPLEMENT_DYNAMIC(Choose, CDialogEx)

Choose::Choose(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_Choose, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

Choose::~Choose()
{
}

void Choose::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Choose, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC4, &Choose::OnStnClickedStatic4)
	ON_BN_CLICKED(chk_docx, &Choose::OnBnClickeddocx)
	ON_BN_CLICKED(chk_doc, &Choose::OnBnClickeddoc)
	ON_BN_CLICKED(chk_txt, &Choose::OnBnClickedtxt)
	ON_BN_CLICKED(btn_ChooseOK, &Choose::OnBnClickedChooseok)
	ON_BN_CLICKED(btn_ChooseCancel, &Choose::OnBnClickedChoosecancel)
	ON_BN_CLICKED(btn_ChooseOK, &Choose::OnBnClickedChooseok)
	ON_EN_CHANGE(edit_OtherTypes, &Choose::OnEnChangeOthertypes)
	ON_STN_CLICKED(IDC_STATIC5, &Choose::OnStnClickedStatic5)
END_MESSAGE_MAP()


// Choose ��Ϣ�������


void Choose::OnStnClickedStatic4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Choose::OnBnClickeddocx()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Choose::OnBnClickeddoc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Choose::OnBnClickedtxt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Choose::OnBnClickedChoosecancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void Choose::OnBnClickedChooseok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ImportFile file;
	CString str_FolderPath,str,temp;
	//Node *Head=new Node;
	//Node *Check = new Node;
	//Node *p = new Node;
	//CHomeworkManagerDlg::m_list_HomeworkFilename;
	GetDlgItemText(edit_OtherTypes, str_Othertypes);
	CButton    *pButton = (CButton    *)GetDlgItem(chk_docx);
	Check[0].data = pButton->GetCheck();
	Check[0].type = "docx";
	pButton = (CButton    *)GetDlgItem(chk_doc);
	Check[1].data = pButton->GetCheck();
	Check[1].type = "doc";
	pButton = (CButton    *)GetDlgItem(chk_txt);
	Check[2].data = pButton->GetCheck();
	Check[2].type = "txt";
	CDialogEx::OnOK();
	

	


}


void Choose::OnEnChangeOthertypes()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Choose::OnStnClickedStatic5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
