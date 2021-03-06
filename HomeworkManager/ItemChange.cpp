// ItemChange.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "ItemChange.h"
#include "afxdialogex.h"


// ItemChange 对话框

IMPLEMENT_DYNAMIC(ItemChange, CDialogEx)

ItemChange::ItemChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_ItemChange, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

ItemChange::~ItemChange()
{
}

void ItemChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	radio = (CButton*)GetDlgItem(rad_ChangeReplace);
	radio->SetCheck(1);
	radio = (CButton*)GetDlgItem(rad_ChangeAdd);
	radio->SetCheck(0);
}


BEGIN_MESSAGE_MAP(ItemChange, CDialogEx)
	ON_EN_CHANGE(edit_ItemChange, &ItemChange::OnEnChangeItemchange)
	ON_BN_CLICKED(IDOK, &ItemChange::OnBnClickedOk)
	ON_BN_CLICKED(rad_ChangeReplace, &ItemChange::OnBnClickedChangereplace)
	ON_BN_CLICKED(rad_ChangeAdd, &ItemChange::OnBnClickedChangeadd)
END_MESSAGE_MAP()


// ItemChange 消息处理程序


void ItemChange::OnEnChangeItemchange()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ItemChange::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(edit_ItemChange, str_ItemChange);
	bol_RadioChoose = bol_temp;
	CDialogEx::OnOK();
}


void ItemChange::OnBnClickedChangereplace()
{
	// TODO: 在此添加控件通知处理程序代码
	radio = (CButton*)GetDlgItem(rad_ChangeReplace);
	radio->SetCheck(1);
	radio = (CButton*)GetDlgItem(rad_ChangeAdd);
	radio->SetCheck(0);
	bol_temp = true;
}


void ItemChange::OnBnClickedChangeadd()
{
	// TODO: 在此添加控件通知处理程序代码
	radio = (CButton*)GetDlgItem(rad_ChangeReplace);
	radio->SetCheck(0);
	radio = (CButton*)GetDlgItem(rad_ChangeAdd);
	radio->SetCheck(1);
	bol_temp = false;
}
