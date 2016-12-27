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
	bol_RadioChoose = bol_temp;
	CDialogEx::OnOK();
}


void ItemChange::OnBnClickedChangereplace()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	radio = (CButton*)GetDlgItem(rad_ChangeReplace);
	radio->SetCheck(1);
	radio = (CButton*)GetDlgItem(rad_ChangeAdd);
	radio->SetCheck(0);
	bol_temp = true;
}


void ItemChange::OnBnClickedChangeadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	radio = (CButton*)GetDlgItem(rad_ChangeReplace);
	radio->SetCheck(0);
	radio = (CButton*)GetDlgItem(rad_ChangeAdd);
	radio->SetCheck(1);
	bol_temp = false;
}
