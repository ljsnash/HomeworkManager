#pragma once


// Choose �Ի���

class Choose : public CDialogEx
{
	DECLARE_DYNAMIC(Choose);

	friend class  CHomeworkManagerDlg;
public:
	Choose(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Choose();
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_Choose };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStatic4();
	afx_msg void OnBnClickeddocx();
	afx_msg void OnBnClickeddoc();
	afx_msg void OnBnClickedtxt();
	afx_msg void OnBnClickedChoosecancel();
	afx_msg void OnBnClickedChooseok();
	CString str;
	afx_msg void OnEnChangeOthertypes();
	afx_msg void OnStnClickedStatic5();
};
