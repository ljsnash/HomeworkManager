
// HomeworkManager.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include"Student.h"

// CHomeworkManagerApp: 
// �йش����ʵ�֣������ HomeworkManager.cpp
//

class CHomeworkManagerApp : public CWinApp
{
public:
	CHomeworkManagerApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHomeworkManagerApp theApp;
extern bool bol_Importtype;
extern int int_ChkNumber[3];
struct Node {
	int data;
	CString type;
};
extern Node Check[3];
extern CString str_Othertypes;
extern Student stu[10000];
extern int int_Total;
extern int int_Total2;
extern void quickSort(Student s[], int l, int r);
extern CString str_Sheet;
extern bool bol_List;
extern CString str_ItemChange;
extern bool bol_RadioChoose;
extern CString  str_SheetChooseName;
extern CString  str_SheetChooseNumber;
extern CString  str_ItemPath;
extern CString  str_ItemName;
extern CString  str_SheetAddName;
extern CString  str_SheetAddNumber;