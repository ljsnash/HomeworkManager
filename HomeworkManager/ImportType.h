#pragma once


// ImportType �Ի���

class ImportType : public CDialogEx
{
	DECLARE_DYNAMIC(ImportType)

public:
	ImportType(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ImportType();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = dlg_ImportType };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStatic2();
	afx_msg void OnBnClickedCover();
	afx_msg void OnBnClickedCombine();
};
