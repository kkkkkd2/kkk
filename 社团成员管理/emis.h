#ifndef EMIS_H
#define EMIS_H

#include "manager_view.h"

class Emis
{
	ManagerView* mgrView;
	static Emis emis;
	Emis(void);
	Emis(const Emis& that) {}
public:
	
	~Emis(void);
	static Emis& getEmis(void);
	void start(void);
};

#endif//EMIS_H
