
// HomeworkManager.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include"Student.h"

// CHomeworkManagerApp: 
// 有关此类的实现，请参阅 HomeworkManager.cpp
//

class CHomeworkManagerApp : public CWinApp
{
public:
	CHomeworkManagerApp();

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

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