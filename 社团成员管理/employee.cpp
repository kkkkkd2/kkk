#include "employee.h"


Employee::Employee(const char* name,char sex,int age)
{
	strcpy(m_strName,name);
	m_cSex=sex;
	m_iAge=age;
}

void Employee::setId(int id)
{
	m_iId=id;
}

void Employee::setAge(int age)
{
	m_iAge=age;
}

void Employee::setName(const char* name)
{
	strcpy(m_strName,name);
}

void Employee::setSex(char sex)
{
	m_cSex=sex;
}

int Employee::getId(void)
{
	return m_iId;
}

int Employee::getAge(void)
{
	return m_iAge;
}

char* Employee::getName(void)
{
	return m_strName;
}

char Employee::getSex(void)
{
	return m_cSex;
}

ostream& operator<<(ostream& os,const Employee& Emp)
{
	return os<<Emp.m_iId<<" "<<Emp.m_strName<<" "<<Emp.m_cSex<<" "<<Emp.m_iAge;
}

istream& operator>>(istream& is,Employee& Emp)
{
	return is>>Emp.m_iId>>Emp.m_strName>>Emp.m_cSex>>Emp.m_iAge;
}

