#include "hotel.h"

int main(int argc,const char* argv[])
{
	if(argc!=2)
	{
		cout<<"User: ./HMS <path>"<<endl;
		return 0;
	}
	Hotel& hotel=Hotel::getHotel();
	hotel.load(argv[1]);
	hotel.start();
}
