#ifndef __DUMMYESC_H__
#define __DUMMYESC_H__

#include "Module.h"
#include "Globals.h"
#include "conio.h"

class ModuleDummyESC : public Module
{
	bool Init()
	{
		LOG("\nDummyESC Init!");
		return true;
	}

	int Update(){
		if (_kbhit()){
			return UPDATE_STOP;
		}
	}

	bool CleanUp()
	{
		LOG("\nDummyESC CleanUp!");
		return true;
	}
};

#endif // __DUMMYESC_H__