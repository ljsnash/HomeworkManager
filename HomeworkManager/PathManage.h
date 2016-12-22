#pragma once
#include<io.h>
#include<iostream>
#include "afxdialogex.h"
#include "stdafx.h"
#include<stdlib.h>
#include "HomeworkManager.h"
#include "HomeworkManagerDlg.h"
using namespace std;
class PathManage
{
public:
	CString Change(CString _path,int i=0)
	{
		CString path,temp1,temp2;
		int num1, num2;
		num1=_path.Find(ch1,i);
		num2 = _path.Find(ch1, num1);



	}
private:
	char* ch1 = "\\";
	char* ch2 = "\"";
};