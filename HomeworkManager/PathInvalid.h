#pragma once
#include<iostream>
#include<string>
#include<afxwin.h>
#include"Tips.h"
#include "stdafx.h"
#include<io.h>
using namespace std;
class PathJudgement 
{
public:
	void Judge(CString str_FileName)
	{
		if (_access(str_FileName, 0) == 0)
		{
			system(str_FileName);
		}
		else
		{
			Tips tip;
			tip.DoModal();
		}
	}

};