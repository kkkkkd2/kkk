#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "tools.h"

class Employee
{
	int m_iId;
	int m_iAge;
	char m_strName[20];
	char m_cSex;
public:
	Employee(const char* name="",char sex='w',int age=0);
	void setId(int id);
	void setAge(int age);
	void setName(const char* name);
	void setSex(char sex);
	int getId(void);
	int getAge(void);
	char* getName(void);
	char getSex(void);
	friend ostream& operator<<(ostream& os,const Employee& Emp);
	friend istream& operator>>(istream& is,Employee& Emp);	
};

#endif//EMPLOYEE_H
