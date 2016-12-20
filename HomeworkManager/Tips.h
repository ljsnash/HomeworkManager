#pragma once


// Tips 对话框

class Tips : public CDialogEx
{
	DECLARE_DYNAMIC(Tips)

public:
	Tips(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Tips();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_PathInvalid };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStatic3();
};
