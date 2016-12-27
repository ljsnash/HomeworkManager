#pragma once


// ItemAdd 对话框

class ItemAdd : public CDialogEx
{
	DECLARE_DYNAMIC(ItemAdd)

public:
	ItemAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ItemAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_ItemAdd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddbrowse();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
