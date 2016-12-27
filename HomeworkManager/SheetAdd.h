#pragma once


// SheetAdd 对话框

class SheetAdd : public CDialogEx
{
	DECLARE_DYNAMIC(SheetAdd)

public:
	SheetAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SheetAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_SheetAdd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeSheetaddnumber();
	afx_msg void OnBnClickedOk();
};
