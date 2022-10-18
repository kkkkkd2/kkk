#include "manager_view_impl.h"
#include "manager_ctrl_impl.h"
#include "service_view_impl.h"


ManagerViewImpl::ManagerViewImpl(void)
{
	init_id();
	mgrCtrl=new ManagerCtrlImpl;
	srcView=new ServiceViewImpl;
}

ManagerViewImpl::~ManagerViewImpl(void)
{
	delete srcView;
	delete mgrCtrl;
}

void ManagerViewImpl::loginManager(void)
{
	char id[20]={},pwd[20]={};
	cout<<"请输入超级管理员ID：";
	get_str(id,sizeof(id));
	cout<<"请输入密码：";
	get_pass(pwd,sizeof(pwd));
	
	if(0==strcmp(id,"zzxx")&&0==strcmp(pwd,"123456"))
	{
		menuMgr();
		return;
	}
	cout<<"用户名或密码出错，请检查！"<<endl;
	sleep(1);
}

void ManagerViewImpl::loginService(void)
{
	char pwd[20]={};
	char id[10]={};
	cout<<"请输入业务管理员ID：";
	get_str(id,10);
	cout<<"请输入密码：";
	get_pass(pwd,sizeof(pwd));
	
	vector<Manager>& mgrArr=mgrCtrl->listMgr();
	for(unsigned int i=0;i<mgrArr.size();i++)
	{
		if(atoi(id)==mgrArr[i].getId() && 0==strcmp(pwd,mgrArr[i].getPwd()))
		{
			srcView->menuSrc();
			return;
		}
	}
	cout<<"业务管理员ID或密码出错，登录失败"<<endl;
	sleep(1);
}

void ManagerViewImpl::menuMgr(void)
{
	while(true)
	{
		system("clear");
		cout<<"***欢迎进入超级管理员子系统***"<<endl;
		cout<<"1、添加管理员用户"<<endl;
		cout<<"2、删除管理员用户"<<endl;
		cout<<"3、列出所有管理员"<<endl;
		cout<<"4、退出子系统"<<endl;
		switch(get_cmd('1','4'))
		{
			case '1':addMgr();break;
			case '2':delMgr();break;
			case '3':listMgr();break;
			case '4':return;
		}
	}
}

void ManagerViewImpl::addMgr(void)
{
	char name[20]={},pwd[20]={},repwd[20]={};
	cout<<"请输入新管理员姓名：";
	get_str(name,sizeof(name));
	cout<<"请输入新管理员密码：";
	get_pass(pwd,sizeof(pwd));
	cout<<"请再次输入密码：";
	get_pass(repwd,sizeof(repwd));
	if(strcmp(pwd,repwd))
	{
		cout<<"两次密码不相同，添加失败！"<<endl;
		sleep(1);
		return;
	}
	Manager mgr(name,pwd);
	if(mgrCtrl->addMgr(mgr))
	{
		cout<<"添加管理员成功"<<endl;
		sleep(1);
		return;
	}
	cout<<"用户名重复，添加管理员失败！"<<endl;
	sleep(1);
}

void ManagerViewImpl::delMgr(void)
{
	int id=0;
	cout<<"请输入要删除的管理员ID：";
	cin>>id;
	if(mgrCtrl->delMgr(id))
	{
		cout<<"删除管理员成功！"<<endl;
		sleep(1);
		return;
	}
	cout<<"管理员ID有误，删除失败！"<<endl;
	sleep(1);
}

void ManagerViewImpl::listMgr(void)
{
	vector<Manager>& mgrArr=mgrCtrl->listMgr();
	for(unsigned int i=0;i<mgrArr.size();i++)
	{
		cout<<mgrArr[i]<<endl;
	}
	anykey_continue();
}

