#include <stdlib.h>
#include "Application.h"
#include "Globals.h"
#include "MemLeaks.h"

#include <SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif


enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = nullptr;
main_states state;

void main_loop_iteration()
{
	switch (state)
	{
	case MAIN_UPDATE:
	{
		int update_return = App->Update();

		if (update_return == UPDATE_ERROR)
		{
			LOG("Application Update exits with error -----");
			state = MAIN_EXIT;
		}
		else if (update_return == UPDATE_STOP)
			state = MAIN_FINISH;
	}
	break;

	case MAIN_FINISH:
	{
		LOG("Application CleanUp --------------");
		if (App->CleanUp() == false)
		{
			LOG("Application CleanUp exits with error -----");
		}
		state = MAIN_EXIT;
#ifdef __EMSCRIPTEN__
		emscripten_cancel_main_loop();
#endif
	} break;
	}
}


int main(int argc, char* argv[])
{
	ReportMemoryLeaks();

	int main_return = EXIT_FAILURE;
	state = MAIN_CREATION;

	// Creation and Start phases are executed once
	LOG("Application Creation --------------");
	App = new Application();
	state = MAIN_START;

	LOG("Application Init --------------");
	if (App->Init() == false)
	{
		LOG("Application Init exits with error -----");
		state = MAIN_EXIT;
	}
	else
	{
		state = MAIN_UPDATE;
		LOG("Application Update --------------");
	}

#ifdef __EMSCRIPTEN__
	if (state != MAIN_EXIT) {
		emscripten_set_main_loop(main_loop_iteration, 0, 1);
	}
#else
	while (state != MAIN_EXIT)
	{
		main_loop_iteration();
	}
#endif

	if (state == MAIN_EXIT) {
		main_return = EXIT_SUCCESS;
	}
	
	delete App;
	LOG("Bye :)\n");
	return main_return;
}