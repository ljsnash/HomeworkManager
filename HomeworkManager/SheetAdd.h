#pragma once


// SheetAdd �Ի���

class SheetAdd : public CDialogEx
{
	DECLARE_DYNAMIC(SheetAdd)

public:
	SheetAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SheetAdd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_SheetAdd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeSheetaddnumber();
	afx_msg void OnBnClickedOk();
};
