// ImportType.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HomeworkManager.h"
#include "ImportType.h"
#include "afxdialogex.h"


// ImportType �Ի���

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


// ImportType ��Ϣ�������


void ImportType::OnStnClickedStatic2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ImportType::OnBnClickedCover()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bol_Importtype = true;
	CDialogEx::OnOK();
}




void ImportType::OnBnClickedCombine()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bol_Importtype = false;
	CDialogEx::OnOK();
}
