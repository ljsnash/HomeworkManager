#pragma once


// SheetChange �Ի���

class SheetChange : public CDialogEx
{
	DECLARE_DYNAMIC(SheetChange)

public:
	SheetChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SheetChange();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_SheetChange };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeSheetchangenumber();
	afx_msg void OnEnChangeSheetchangename();
};
