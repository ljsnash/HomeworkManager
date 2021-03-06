
// HomeworkManagerDlg.h : 头文件
//

#pragma once
#include"ImportFile.h"
#include "D:\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.24728\atlmfc\include\afxcmn.h"
#include "afxcmn.h"
#include "afxwin.h"

using namespace std;

// CHomeworkManagerDlg 对话框
class CHomeworkManagerDlg : public CDialogEx
{
// 构造
	
public:
	CHomeworkManagerDlg(CWnd* pParent = NULL);	// 标准构造函数
	friend class Choose;
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
	void _ImportFile(CString str_FolderPath,ImportFile file);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list_HomeworkFilename;
	afx_msg void OnDblclkListHomeworkfilename(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedInformationsheet(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list_InformationSheet;
	afx_msg void OnBnClickedSynchomework();
	afx_msg void OnBnClickedExportfile();
	afx_msg void OnBnClickedImportfile();
	afx_msg void OnLvnColumnclickHomeworkfilename(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedSortup();
	afx_msg void OnBnClickedSortdown();
	afx_msg void OnBnClickedFind();
	afx_msg void OnBnClickedAddfile();
	afx_msg void OnBnClickedStatistics();
	afx_msg void OnNMRClickHomeworkfilename(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void Ondelete();
	afx_msg void OnBnClickedSynctosheet();
	afx_msg void OnChange();
	afx_msg void OnEnChangeTemp();
	CEdit m_EditTemp;
	CString m_CString_EditTemp;
	afx_msg void OnNMRClickInformationsheet(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAdd();
	void ExportFile(CString _str);
	afx_msg void OnBnClickedOpenunnamed();
	afx_msg void OnBnClickedOpenstudentfile();
};

