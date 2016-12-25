#pragma once
#include "afxcmn.h"
#include"stdafx.h"

class Student
{
public:
	Student();
	void SetStudentID(int a);
	void SetStudentNumber(CString a);
	void SetStudentName(CString a);
	void SetStudentFile(CString a);
	void SetStudentPath(CString a);
	void SetStudentCheck();
	void SetStudentCheck(bool a);
	void SetStudentExist(bool a);
	int GetStudentID();
	int GetStudentNumberInt();
	CString GetStudentName();
	CString GetStudentNumber();
	CString GetStudentFile();
	CString GetStudentPath();
	CString GetStudentCheck_str();
	bool GetStudentCheck_bool();
	bool GetStudentExist();

private:
	int int_ID=10001;
	int int_Number;
	CString str_Number;
	CString str_Name;
	CString str_File;
	CString str_Path;
	bool bol_Check = false;
	bool bol_Exist = false;
};