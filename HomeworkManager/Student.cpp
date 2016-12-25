#include"stdafx.h"
#include"Student.h"
#include<io.h>

using namespace std;
void Student::SetStudentID(int a)
{
	int_ID = a;
}
void Student::SetStudentNumber(CString a)
{
	str_Number = a;
}

void Student::SetStudentName(CString a)
{
	str_Name = a;
}

void Student::SetStudentFile(CString a)
{
	str_File = a;
}

void Student::SetStudentPath(CString a)
{
	str_Path = a;
}

void Student::SetStudentCheck()
{
	CString temp = str_Path + str_File;
	if (_access(temp, 0) == 0)
	{
		bol_Check = true;
	}
	else
	{
		bol_Check = false;
	}

}

void Student::SetStudentCheck(bool a)
{
	bol_Check = a;
}
void Student::SetStudentExist(bool a)
{
	bol_Check = a;
}
int Student::GetStudentID()
{
	return int_ID;
}

int Student::GetStudentNumberInt()
{
	int i = _ttoi(str_Number);
	int_Number = i;
	return i;
}
CString Student::GetStudentNumber()
{
	return str_Number;
}

CString Student::GetStudentName()
{
	return str_Name;
}

CString Student::GetStudentFile()
{
	return str_File;
}

CString Student::GetStudentPath()
{
	return str_Path;
}

bool Student::GetStudentCheck_bool()
{
	return bol_Check;
}

CString Student::GetStudentCheck_str()
{
	if (bol_Check == true) return"ÒÑ½»";
	if (bol_Check == false) return"Î´½»";
}
bool Student::GetStudentExist()
{
	return bol_Exist;
}
