#pragma once


// ItemChange �Ի���

class ItemChange : public CDialogEx
{
	DECLARE_DYNAMIC(ItemChange)

public:
	ItemChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ItemChange();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_ItemChange };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeItemchange();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedChangereplace();
	afx_msg void OnBnClickedChangeadd();
	CButton* radio;
	bool bol_temp;
};
