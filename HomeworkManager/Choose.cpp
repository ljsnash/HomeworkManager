// Choose.cpp : 实现文件
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


// Choose 对话框

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


// Choose 消息处理程序


void Choose::OnStnClickedStatic4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Choose::OnBnClickeddocx()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Choose::OnBnClickeddoc()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Choose::OnBnClickedtxt()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Choose::OnBnClickedChoosecancel()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void Choose::OnBnClickedChooseok()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Choose::OnStnClickedStatic5()
{
	// TODO: 在此添加控件通知处理程序代码
}
