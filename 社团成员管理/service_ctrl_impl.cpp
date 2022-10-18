#include "service_ctrl_impl.h"
#include "service_mode_impl.h"
#include "tools.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode=new ServiceModeImpl;
	srcMode->load(deptArr);
}

ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(deptArr);
	delete srcMode;
}

bool ServiceCtrlImpl::addDept(Department& d)
{
	for(unsigned int i=0;i<deptArr.size();i++)
	{
		if(!strcmp(deptArr[i].getName(),d.getName()))
		{
			return false;
		}
	}
	d.setId(get_depid());
	deptArr.push_back(d);
	return true;
}

int ServiceCtrlImpl::delDept(int id)
{
	for(vector<Department>::iterator it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(id==it->getId())
		{
			deptArr.erase(it);
			return 1;
		}
	}
	return 0;
}

vector<Department>& ServiceCtrlImpl::listDept(void)
{
	return deptArr;
}

bool ServiceCtrlImpl::addEmp(int dept_id,Employee& e)
{	
	for(vector<Department>::iterator it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(dept_id==it->getId())
		{	
			e.setId(get_empid());
			it->empArr.push_back(e);
			return true;
		}
	}
	return false;
}

bool ServiceCtrlImpl::delEmp(int id)
{
	for(vector<Department>::iterator it=deptArr.begin();it!=deptArr.end();it++)
	{
		for(vector<Employee>::iterator it1=it->empArr.begin();it1!=it->empArr.end();it1++)
		{
			if(id==it1->getId())
			{
				it->empArr.erase(it1);
				return true;
			}
		}
	}
	return false;
}

bool ServiceCtrlImpl::modEmp(int id,Employee& emp)
{	
	for(vector<Department>::iterator it=deptArr.begin();it!=deptArr.end();it++)
	{
		for(vector<Employee>::iterator it1=it->empArr.begin();it1!=it->empArr.end();it1++)
		{
			if(id==it1->getId())
			{
				it->empArr.erase(it1);
				it->empArr.push_back(emp);
				return true;
			}
		}
	}
	return false;
}

Department* ServiceCtrlImpl::listEmp(int id)
{
	for(vector<Department>::iterator it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(id==it->getId())
		{
			return &(*it);
		}
	}
	return NULL;
}

vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
	return deptArr;
}

