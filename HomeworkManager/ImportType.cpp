// ImportType.cpp : 实现文件
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "ImportType.h"
#include "afxdialogex.h"


// ImportType 对话框

IMPLEMENT_DYNAMIC(ImportType, CDialogEx)

ImportType::ImportType(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlg_ImportType, pParent)
{

}

ImportType::~ImportType()
{
}

void ImportType::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImportType, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC2, &ImportType::OnStnClickedStatic2)
	ON_BN_CLICKED(btn_Cover, &ImportType::OnBnClickedCover)
	ON_BN_CLICKED(btn_Combine, &ImportType::OnBnClickedCombine)
END_MESSAGE_MAP()


// ImportType 消息处理程序


void ImportType::OnStnClickedStatic2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void ImportType::OnBnClickedCover()
{
	// TODO: 在此添加控件通知处理程序代码
	bol_Importtype = true;
	CDialogEx::OnOK();
}




void ImportType::OnBnClickedCombine()
{
	// TODO: 在此添加控件通知处理程序代码
	bol_Importtype = false;
	CDialogEx::OnOK();
}
