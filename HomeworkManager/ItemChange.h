#pragma once


// ItemChange 对话框

class ItemChange : public CDialogEx
{
	DECLARE_DYNAMIC(ItemChange)

public:
	ItemChange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ItemChange();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_ItemChange };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeItemchange();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedChangereplace();
	afx_msg void OnBnClickedChangeadd();
	CButton* radio;
	bool bol_temp;
};
