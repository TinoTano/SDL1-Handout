#ifndef _MUSICSDLMODULE_
#define _MUSICSDLMODULE_

#include "Module.h"
#include "Globals.h"
#include "conio.h"

class ModuleMusic : public Module {
	bool Init()
	{
		LOG("\nMusicSDLModule Init!");
		return true;
	}

	int Update(){
		if (_kbhit()){
			return UPDATE_STOP;
		}
	}

	bool CleanUp()
	{
		LOG("\nMusicSDLModule CleanUp!");
		return true;
	}
};


#endif
