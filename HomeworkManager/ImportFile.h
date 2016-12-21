#pragma once
#include<io.h>
#include<iostream>
#include "afxdialogex.h"
#include "stdafx.h"
#include<stdlib.h>
#include "HomeworkManager.h"
#include "HomeworkManagerDlg.h"
using namespace std;
class ImportFile
{
public:
	/*ImportFile(CListCtrl *_list)
	{
		list=_list;
		//list->InsertItem(0, "123");	
	}*/
	void Initlistctrl(CListCtrl *_list)
	{
		_list->DeleteAllItems();
	}
	void GetFirstFile(CString file, CListCtrl *_list,int i=0)
	{
		//Initlistctrl(_list);
		CString _file=file + "\\*.txt";
		handle = _findfirst(_file, &fileinfo);		
		if (handle != -1)
		{
			_list->InsertItem(i, fileinfo.name);
			_list->SetItemText(i, 3, file);
		}
	}
	void GetAllFile(CString file, CListCtrl *_list, int i = 0)
	{
		GetFirstFile(file,_list);
		if (handle != -1)
		{
			while (!_findnext(handle, &fileinfo))               //循环查找其他符合的文件，知道找不到其他的为止
			{
				_list->InsertItem(i, fileinfo.name);
				_list->SetItemText(i, 3, file);
			}
		}
		_findclose(handle);
		_list=NULL;

	}
private:
	intptr_t handle=-1;
	struct _finddata_t fileinfo;
	CListCtrl *list;
};

