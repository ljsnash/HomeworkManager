#pragma once
#include "afxcmn.h"


// NameList �Ի���

class NameList : public CDialogEx
{
	DECLARE_DYNAMIC(NameList)

public:
	NameList(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~NameList();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_NameList };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedNamelist(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list_NameList;
	afx_msg void OnBnClickedImportnamelist();
};
