
// HomeworkManagerDlg.h : 头文件
//

#pragma once
#include "D:\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.24629\atlmfc\include\afxcmn.h"


// CHomeworkManagerDlg 对话框
class CHomeworkManagerDlg : public CDialogEx
{
// 构造
public:
	CHomeworkManagerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_Index };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImportinformation();
	afx_msg void OnBnClickedRegulatefilename();
	afx_msg void OnBnClickedBrowsesheet();
	afx_msg void OnEnChangePathsheet();
	afx_msg void OnBnClickedOpensheet();
	afx_msg void OnBnClickedBrowsefolder();
	afx_msg void OnBnClickedImportfolder();
	afx_msg void OnBnClickedOpenfolder();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list_HomeworkFilename;
};
