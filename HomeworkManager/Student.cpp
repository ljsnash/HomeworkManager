#include"stdafx.h"
#include"Student.h"
#include<io.h>

using namespace std;
Student::Student()
{
	int_ID = 10001;
	bol_Check = false;
	bol_Exist = false;
    int_Number=0;
	str_Number="";
	str_Name="";
	str_File="";
	str_Path="";
}

Student::~Student()
{

}

void Student::Delete()
{
	Student();
}
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
	bol_Exist = a;
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

CString Student::GetStudentFullFilePath()
{
	return str_Path + "\\" + str_File;
}

CString Student::GetStudentAll()
{
	return str_Number + " " + str_Name + " " + GetStudentCheck_str() + " " + GetStudentFullFilePath();
}
bool Student::GetStudentExist()
{
	return bol_Exist;
}
