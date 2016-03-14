#ifndef _MUSICSDLMODULE_
#define _MUSICSDLMODULE_

#include "Module.h"
#include "Globals.h"

class ModuleMusic : public Module 
{
	bool Init()
	{
		LOG("\nMusicSDLModule Init!");
		SDL_Init(SDL_INIT_EVERYTHING);
		Mix_Init(MIX_INIT_OGG);
		g.background_music = Mix_LoadMUS("music.ogg");
		if (g.background_music == NULL)
		{
			std::cout << "Music not loaded";
		}
		else{
			std::cout << "Music loaded";
		}
		Mix_PlayMusic(g.background_music, -1);
		return true;
	}

	bool CleanUp()
	{
		LOG("\nMusicSDLModule CleanUp!");
		Mix_FreeMusic(g.background_music);
		g.background_music = NULL;
		Mix_Quit();
		return true;
	}
};


#endif