#ifndef __DUMMYESC_H__
#define __DUMMYESC_H__

#include "Module.h"
#include "Globals.h"
#include "conio.h"
#include <iostream>

class ModuleDummyESC : public Module
{
	bool Init()
	{
		LOG("\nDummyESC Init!");
		return true;
	}

	int Update(){
		if (_kbhit() != 0){
			char key = _getch();
			if (key == 27){ // 27 = ESC key
				return UPDATE_STOP;
			}
		}
	}

	bool CleanUp()
	{
		LOG("\nDummyESC CleanUp!");
		return true;
	}
};

#endif // __DUMMYESC_H__