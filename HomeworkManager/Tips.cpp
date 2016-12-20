// Tips.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "Tips.h"
#include "afxdialogex.h"


// Tips 对话框

IMPLEMENT_DYNAMIC(Tips, CDialogEx)

Tips::Tips(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_PathInvalid, pParent)
{
	
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	

}

Tips::~Tips()
{
}

void Tips::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tips, CDialogEx)
	ON_BN_CLICKED(btn_OK, &Tips::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC3, &Tips::OnStnClickedStatic3)
END_MESSAGE_MAP()


// Tips 消息处理程序


void Tips::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}


void Tips::OnStnClickedStatic3()
{
	// TODO: 在此添加控件通知处理程序代码
}
