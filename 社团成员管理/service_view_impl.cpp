#include "service_view_impl.h"
#include "service_ctrl_impl.h"
#include "tools.h"

ServiceViewImpl::ServiceViewImpl(void)
{
	srcCtrl=new ServiceCtrlImpl;
}

ServiceViewImpl::~ServiceViewImpl(void)
{
	delete srcCtrl;
}

void ServiceViewImpl::menuSrc(void)
{
	for(;;)
	{
		system("clear");
		cout<<"************************"<<endl;
		cout<<"1.添加部门    2.删除部门"<<endl;
		cout<<"3.显示部门 "<<endl;
		cout<<"4.添加员工    5.删除员工"<<endl;
		cout<<"6.修改员工    7.显示员工"<<endl;
		cout<<"8.所有员工    9.退出"<<endl;
		cout<<"************************"<<endl;
		switch(get_cmd('1','9'))
		{
			case '1':addDept();  break;
			case '2':delDept();  break;
			case '3':listDept(); break;
			case '4':addEmp();	break;
			case '5':delEmp();  break;
			case '6':modEmp();  break;
			case '7':listEmp(); break;
			case '8':listAllEmp(); break;
			case '9':return;
		}
	}
}

void ServiceViewImpl::addDept(void)
{
	char name[20]={};
	cout<<"请输入部门名：";
	get_str(name,sizeof(name));
	Department d(name);
	
	if(srcCtrl->addDept(d)) cout<<"添加成功！"<<endl;
	else cout<<"添加失败！"<<endl;
}

void ServiceViewImpl::delDept(void)
{
	int id;
	cout<<"请输入要删除部门的id:";
	cin>>id;
	if(srcCtrl->delDept(id)) cout<<"删除成功！"<<endl;
	else cout<<"删除失败！"<<endl;
}

void ServiceViewImpl::listDept(void)
{
	vector<Department>& deptArr=srcCtrl->listDept();
	for(vector<Department>::iterator it=deptArr.begin();it!=deptArr.end();it++)
	{
		cout<<*it<<endl;
		for(vector<Employee>::iterator it1=it->empArr.begin();it1!=it->empArr.end();it1++)
		{
			cout<<*it1<<endl;
		}
	}
}

void ServiceViewImpl::addEmp(void)
{
	char name[20]={};
	cout<<"请输入姓名：";
	get_str(name,sizeof(name));
	char sex;
	int age,id;
	cout<<"请输入性别、年龄、部门编号：";
	cin>>sex>>age>>id;
	Employee e(name,sex,age);

	if(srcCtrl->addEmp(id,e)) cout<<"添加成功！"<<endl;
	else cout<<"添加失败！"<<endl;
}

void ServiceViewImpl::delEmp(void)
{
	int id;
	cout<<"请输入要删除员工的id:";
	cin>>id;
	if(srcCtrl->delEmp(id)) cout<<"删除成功！"<<endl;
	else cout<<"删除失败！"<<endl;
}

void ServiceViewImpl::modEmp(void)
{
	int id;
	cout<<"请输入要修改员工的id:";
	cin>>id;
	char sex;
	int age;
	char name[20]={};
	cout<<"请输入新的姓名：";
	get_str(name,sizeof(name));
	cout<<"请输入新的性别、年龄：";
	cin>>sex>>age;
	Employee e(name,sex,age);
	e.setId(id);
	if(srcCtrl->modEmp(id,e)) cout<<"修改成功！"<<endl;
	else cout<<"修改失败！"<<endl;
}

void ServiceViewImpl::listEmp(void)
{
	int id;
	cout<<"请输入要查看部门的id:";
	cin>>id;
	Department* dept=srcCtrl->listEmp(id);
	if(dept==NULL)
		cout<<"暂无该部门信息"<<endl;
	for(unsigned int i=0;i<dept->empArr.size();i++)
	{
		cout<<dept->empArr[i]<<endl;
	}
}

void ServiceViewImpl::listAllEmp(void)
{
	vector<Department>& deptArr=srcCtrl->listAllEmp();
	for(vector<Department>::iterator it=deptArr.begin();it!=deptArr.end();it++)
	{
		cout<<*it<<endl;
		for(vector<Employee>::iterator it1=it->empArr.begin();it1!=it->empArr.end();it1++)
		{
			cout<<*it1<<endl;
		}
	}
}

