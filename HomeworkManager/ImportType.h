#pragma once


// ImportType 对话框

class ImportType : public CDialogEx
{
	DECLARE_DYNAMIC(ImportType)

public:
	ImportType(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ImportType();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_ImportType };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStatic2();
	afx_msg void OnBnClickedCover();
	afx_msg void OnBnClickedCombine();
};
