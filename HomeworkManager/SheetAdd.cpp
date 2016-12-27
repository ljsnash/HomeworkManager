// SheetAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "SheetAdd.h"
#include "afxdialogex.h"


// SheetAdd 对话框

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
	SetDlgItemText(edit_SheetAddName, "张三");
	SetDlgItemText(edit_SheetAddNumber, "0");
}


BEGIN_MESSAGE_MAP(SheetAdd, CDialogEx)
	ON_EN_CHANGE(edit_SheetAddNumber, &SheetAdd::OnEnChangeSheetaddnumber)
	ON_BN_CLICKED(IDOK, &SheetAdd::OnBnClickedOk)
END_MESSAGE_MAP()


// SheetAdd 消息处理程序


void SheetAdd::OnEnChangeSheetaddnumber()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void SheetAdd::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(edit_SheetAddName, str_SheetAddName);
	GetDlgItemText(edit_SheetAddNumber, str_SheetAddNumber);
	CDialogEx::OnOK();

}
