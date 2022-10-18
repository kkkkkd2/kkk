#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager_mode.h"

class ManagerModeImpl:public ManagerMode
{
public:
	void load(vector<Manager>& mgrArr);
	void save(const vector<Manager>& mgrArr);
};

#endif//MANAGER_MODE_IMPL_H
