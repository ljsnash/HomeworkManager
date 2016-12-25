#pragma once
#include "afxcmn.h"
#include"stdafx.h"

class Student
{
public:
	void SetStudentID(int a);
	void SetStudentNumber(CString a);
	void SetStudentName(CString a);
	void SetStudentFile(CString a);
	void SetStudentPath(CString a);
	void SetStudentCheck();
	void SetStudentCheck(bool a);
	int GetStudentID();
	int GetStudentNumberInt();
	CString GetStudentName();
	CString GetStudentNumber();
	CString GetStudentFile();
	CString GetStudentPath();
	bool GetStudentCheck();

private:
	int int_ID;
	int int_Number;
	CString str_Number;
	CString str_Name;
	CString str_File;
	CString str_Path;
	bool bol_Check;
};