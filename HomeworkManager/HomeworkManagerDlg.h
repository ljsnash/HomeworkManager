
// HomeworkManagerDlg.h : ͷ�ļ�
//

#pragma once


// CHomeworkManagerDlg �Ի���
class CHomeworkManagerDlg : public CDialogEx
{
// ����
public:
	CHomeworkManagerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOMEWORKMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImportinformation();
	afx_msg void OnBnClickedRegulatefilename();
	afx_msg void OnBnClickedBrowsesheet();
	afx_msg void OnEnChangePathsheet();
	afx_msg void OnBnClickedOpensheet();
	afx_msg void OnBnClickedBrowsefolder();
	afx_msg void OnBnClickedImportfolder();
	afx_msg void OnBnClickedOpenfolder();
	afx_msg void OnEnChangeEdit2();
};
