#include "service_mode_impl.h"
#include "tools.h"

void ServiceModeImpl::load(vector<Department>& dept)
{	
	ifstream fin(DATA_SRC_PATH);
	if(!fin)
	{
		cout << "文件打开失败" << endl;	
		return;
	}
	fin.seekg(ios::beg);
	
	while(true)
	{
		Department d;
		int cnt=0;
		fin>>d>>cnt;
		stdin->_IO_read_ptr=stdin->_IO_read_end;
		for(int i=0;i<cnt;i++)
		{
			Employee emp;
			fin>>emp;
			//cout<<emp;
			d.empArr.push_back(emp);
			if(!fin.good()) break;
		}
		dept.push_back(d);
		if(!fin.good()) break;
	}
	fin.close();
}

void ServiceModeImpl::save(vector<Department>& dept)
{
	ofstream fout(DATA_SRC_PATH);
	if(!fout)
	{	
		return;
	}
	fout.seekp(ios::beg);
	
	for(vector<Department>::iterator it=dept.begin();it!=dept.end();it++)
	{
		fout<<*it<<" "<< it->empArr.size()<<endl;
		for(vector<Employee>::iterator it1=it->empArr.begin();it1!=it->empArr.end();it1++)
		{
			fout<<*it1<<endl;
		}
	}
	fout.close();
}

