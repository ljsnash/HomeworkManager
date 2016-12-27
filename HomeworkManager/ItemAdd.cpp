// ItemAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "ItemAdd.h"
#include "afxdialogex.h"
#include "FolderPath.h"





// ItemAdd �Ի���

IMPLEMENT_DYNAMIC(ItemAdd, CDialogEx)

ItemAdd::ItemAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_ItemAdd, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

ItemAdd::~ItemAdd()
{
}

void ItemAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	SetDlgItemText(edit_AddPath, str_ItemPath);
}


BEGIN_MESSAGE_MAP(ItemAdd, CDialogEx)
	ON_BN_CLICKED(btn_AddBrowse, &ItemAdd::OnBnClickedAddbrowse)
	ON_BN_CLICKED(IDOK, &ItemAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ItemAdd::OnBnClickedCancel)
END_MESSAGE_MAP()


// ItemAdd ��Ϣ�������


void ItemAdd::OnBnClickedAddbrowse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FolderPath *path = new FolderPath("��ѡ������ļ���");
	CString str_FolderPath = path->setFolderPath();
	delete path;
	SetDlgItemText(edit_AddPath, str_FolderPath);
}


void ItemAdd::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(edit_AddFileName, str_ItemName);
	if (str_ItemName != "")
	{
		GetDlgItemText(edit_AddPath, str_ItemPath);
		CString str_FileFull= str_ItemPath +"\\"+ str_ItemName;
		HANDLE hOpenFile = (HANDLE)CreateFile(str_FileFull, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, NULL, NULL);
		hOpenFile = NULL;
	}
	CDialogEx::OnOK();
}


void ItemAdd::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
