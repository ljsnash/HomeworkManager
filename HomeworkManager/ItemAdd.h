#pragma once


// ItemAdd �Ի���

class ItemAdd : public CDialogEx
{
	DECLARE_DYNAMIC(ItemAdd)

public:
	ItemAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ItemAdd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_ItemAdd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddbrowse();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
