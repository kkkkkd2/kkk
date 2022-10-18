#include "manager.h"

Manager::Manager(const char* name,const char* pwd)
{
	strcpy(m_strName,name);
	strcpy(m_strPwd,pwd);
}

int Manager::getId(void)const
{
	return m_iId;
}

const char* Manager::getName(void)const
{
	return m_strName;
}

const char* Manager::getPwd(void)const
{
	return m_strPwd;
}

void Manager::setId(int id)
{
	m_iId=id;
}

void Manager::setName(const char* name)
{
	strcpy(m_strName,name);
}

void Manager::setPwd(const char* pwd)
{
	strcpy(m_strPwd,pwd);
}

ostream& operator<<(ostream& os,const Manager& mgr)
{
	return os<<mgr.m_iId<<" "<<mgr.m_strName<<" "<<mgr.m_strPwd;
}

istream& operator>>(istream& is,Manager& mgr)
{
	return is>>mgr.m_iId>>mgr.m_strName>>mgr.m_strPwd;
}

