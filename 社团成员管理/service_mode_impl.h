#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"

class ServiceModeImpl:public ServiceMode
{
	void load(vector<Department>& dept);
	void save(vector<Department>& dept);
};

#endif//SERVICE_MODE_IMPL_H
