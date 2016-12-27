// SheetChange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "SheetChange.h"
#include "afxdialogex.h"


// SheetChange �Ի���

IMPLEMENT_DYNAMIC(SheetChange, CDialogEx)

SheetChange::SheetChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_SheetChange, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

SheetChange::~SheetChange()
{
}

void SheetChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	SetDlgItemText(edit_SheetChangeName, str_SheetChooseName);
	SetDlgItemText(edit_SheetChangeNumber, str_SheetChooseNumber);
}


BEGIN_MESSAGE_MAP(SheetChange, CDialogEx)
	ON_BN_CLICKED(IDOK, &SheetChange::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SheetChange::OnBnClickedCancel)
	ON_EN_CHANGE(edit_SheetChangeNumber, &SheetChange::OnEnChangeSheetchangenumber)
	ON_EN_CHANGE(edit_SheetChangeName, &SheetChange::OnEnChangeSheetchangename)
END_MESSAGE_MAP()


// SheetChange ��Ϣ�������


void SheetChange::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(edit_SheetChangeName, str_SheetChooseName);
	GetDlgItemText(edit_SheetChangeNumber, str_SheetChooseNumber);
	CDialogEx::OnOK();
}


void SheetChange::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void SheetChange::OnEnChangeSheetchangenumber()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void SheetChange::OnEnChangeSheetchangename()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
