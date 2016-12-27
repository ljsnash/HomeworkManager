// SheetAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "SheetAdd.h"
#include "afxdialogex.h"


// SheetAdd �Ի���

IMPLEMENT_DYNAMIC(SheetAdd, CDialogEx)

SheetAdd::SheetAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_SheetAdd, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

SheetAdd::~SheetAdd()
{
}

void SheetAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	SetDlgItemText(edit_SheetAddName, "����");
	SetDlgItemText(edit_SheetAddNumber, "0");
}


BEGIN_MESSAGE_MAP(SheetAdd, CDialogEx)
	ON_EN_CHANGE(edit_SheetAddNumber, &SheetAdd::OnEnChangeSheetaddnumber)
	ON_BN_CLICKED(IDOK, &SheetAdd::OnBnClickedOk)
END_MESSAGE_MAP()


// SheetAdd ��Ϣ�������


void SheetAdd::OnEnChangeSheetaddnumber()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void SheetAdd::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(edit_SheetAddName, str_SheetAddName);
	GetDlgItemText(edit_SheetAddNumber, str_SheetAddNumber);
	CDialogEx::OnOK();

}
