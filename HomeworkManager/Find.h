#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Find 对话框

class Find : public CDialogEx
{
	DECLARE_DYNAMIC(Find)

public:
	Find(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Find();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_Search };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFindnormal();
	CButton m_radio_FindNormal;
	afx_msg void OnBnClickedFindexact();
	CButton m_radio_FindExact;
	afx_msg void OnBnClickedFindok();
	afx_msg void OnEnChangeFindname();
	afx_msg void OnCbnSelchangeFind();
	afx_msg void OnBnClickedFindbrowse();
	afx_msg void OnLvnItemchangedFind(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list_Find;
	CString str_File="";
	CString temp[4];
	bool bol_Find=true;
	afx_msg void OnStnClickedStatic1();
	afx_msg void OnEnChangeFindnumber();
	afx_msg void OnEnChangeKeyword();
	afx_msg void OnStnClickedStatic6();
	CButton* radio;
};
