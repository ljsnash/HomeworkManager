// ItemChange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "ItemChange.h"
#include "afxdialogex.h"


// ItemChange �Ի���

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
}


BEGIN_MESSAGE_MAP(ItemChange, CDialogEx)
	ON_EN_CHANGE(edit_ItemChange, &ItemChange::OnEnChangeItemchange)
	ON_BN_CLICKED(IDOK, &ItemChange::OnBnClickedOk)
END_MESSAGE_MAP()


// ItemChange ��Ϣ�������


void ItemChange::OnEnChangeItemchange()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void ItemChange::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(edit_ItemChange, str_ItemChange);
	CDialogEx::OnOK();
}
