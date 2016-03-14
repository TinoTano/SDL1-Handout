#include "Application.h"
#include "Globals.h"
#include "MemLeaks.h"

enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

int main(int argc, char *args[])
{
	ReportMemoryLeaks();
	SDL_Init(SDL_INIT_EVERYTHING);

	int main_return = EXIT_FAILURE;
	main_states state = MAIN_CREATION;
	Application* App = nullptr;

	while (state != MAIN_EXIT)
	{
		switch (state)
		{
			case MAIN_CREATION:
			{
				LOG("\nApplication Creation --------------");
				App = new Application();
				state = MAIN_START;
			}	break;

			case MAIN_START:
			{
				LOG("\nApplication Init --------------");
				if(App->Init() == false)
				{
					LOG("\nApplication Init exits with error -----");
					state = MAIN_EXIT;
				}
				else
					state = MAIN_UPDATE;

			}	break;

			case MAIN_UPDATE:
			{
				int update_return = App->Update();

				if (update_return == UPDATE_ERROR)
				{
					LOG("\nApplication Update exits with error -----");
					state = MAIN_EXIT;
				}

				if (update_return == UPDATE_STOP)
					state = MAIN_FINISH;

			} break;

			// TODO 1: Implement case MAIN_FINISH
			case MAIN_FINISH:
			{
				if (App->CleanUp() == false){
					LOG("\nApplication CleanUp exits with error -----");
					state = MAIN_EXIT;
				}
				else {
					state = MAIN_EXIT;
				}
				delete App;
			} break;
		}
	}

	LOG("\nBye :)\n");

	return main_return;
}