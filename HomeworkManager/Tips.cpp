// Tips.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "Tips.h"
#include "afxdialogex.h"


// Tips �Ի���

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


// Tips ��Ϣ�������


void Tips::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnOK();
}


void Tips::OnStnClickedStatic3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
