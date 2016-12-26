#pragma once
#include "afxcmn.h"


// NameList 对话框

class NameList : public CDialogEx
{
	DECLARE_DYNAMIC(NameList)

public:
	NameList(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~NameList();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_NameList };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedNamelist(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list_NameList;
	afx_msg void OnBnClickedImportnamelist();
};
