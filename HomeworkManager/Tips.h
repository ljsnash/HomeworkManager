#pragma once


// Tips �Ի���

class Tips : public CDialogEx
{
	DECLARE_DYNAMIC(Tips)

public:
	Tips(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Tips();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_PathInvalid };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStatic3();
};
