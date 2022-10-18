#include "manager_mode_impl.h"

void ManagerModeImpl::load(vector<Manager>& mgrArr)
{
	ifstream ifs(DATA_MGR_PATH,ios::binary|ios::in);
	if(!ifs)
	{
		return;
	}
	while(true)
	{
		Manager mgr;
		ifs.read((char*)&mgr,sizeof(mgr));
		if(!ifs.good()) break;
		mgrArr.push_back(mgr);
	}
	ifs.close();
}

void ManagerModeImpl::save(const vector<Manager>& mgrArr)
{
	ofstream ofs(DATA_MGR_PATH,ios::out|ios::binary);
	if(!ofs)
	{
		return;
	}
	for(unsigned int i=0;i<mgrArr.size();i++)
	{
		ofs.write((const char*)&mgrArr[i],sizeof(mgrArr[i]));
	}
	ofs.close();
}

