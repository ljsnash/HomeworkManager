
// HomeworkManager.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


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