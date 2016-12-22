#pragma once
#include<io.h>
#include<iostream>
#include "afxdialogex.h"
#include "stdafx.h"
#include<stdlib.h>
#include "HomeworkManager.h"
#include "HomeworkManagerDlg.h"
using namespace std;

class Open
{
public:
	CString IntiOpen(CString _path)
	{
		int position=_path.ReverseFind(*ch1)+1;
		CString temp1 = _path.Left(position);
		CString temp2 = _path.Mid(position);
		return temp1 + ch2 + temp2 + ch2;
	}
	BOOL OpenFile(CString _path)
	{
		system(IntiOpen(_path));
	}
private:
	char *ch1 = "\\";
	CString ch2 = "\"";
}

/*CString str_FileName;
GetDlgItemText(edit_PathSheet, str_FileName);
int position;
char *ch = "\\";

position = str_FileName.ReverseFind(*ch);
CString temp1 = str_FileName.Left(position + 1);
CString temp2 = str_FileName.Mid(position + 1);
if (_access(str_FileName, 0) == 0)
{
	SetDlgItemText(edit_PathFolder, temp1 + "\"" + temp2 + "\"");
	system(str_FileName);
}
else
{
	Tips tip;
	tip.DoModal();
}

}*/