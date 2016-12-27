#pragma once


// SheetChange 对话框

class SheetChange : public CDialogEx
{
	DECLARE_DYNAMIC(SheetChange)

public:
	SheetChange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SheetChange();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_SheetChange };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeSheetchangenumber();
	afx_msg void OnEnChangeSheetchangename();
};
