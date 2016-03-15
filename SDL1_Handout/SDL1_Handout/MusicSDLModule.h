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
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
		g.background_music = Mix_LoadMUS("music.ogg");
		if (g.background_music == NULL)
		{
			std::cout << "Unable to load Ogg file: \n" << Mix_GetError() << "\n";
		}
		else{
			std::cout << "Music loaded! \n";
		}
		if (Mix_PlayMusic(g.background_music, -1) == -1) { 
			std::cout << "Unable to play Ogg file: " << Mix_GetError() << "\n";
			return 1; 
		}
		return true;
	}

	bool CleanUp()
	{
		LOG("\nMusicSDLModule CleanUp!\n");
		Mix_FreeMusic(g.background_music);
		g.background_music = NULL;
		Mix_Quit();
		SDL_Quit();
		return true;
	}
};


#endif