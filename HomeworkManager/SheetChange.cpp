// SheetChange.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "SheetChange.h"
#include "afxdialogex.h"


// SheetChange 对话框

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


// SheetChange 消息处理程序


void SheetChange::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(edit_SheetChangeName, str_SheetChooseName);
	GetDlgItemText(edit_SheetChangeNumber, str_SheetChooseNumber);
	CDialogEx::OnOK();
}


void SheetChange::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void SheetChange::OnEnChangeSheetchangenumber()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void SheetChange::OnEnChangeSheetchangename()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
