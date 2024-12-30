#include "window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WIDTH 1280
#define HEIGHT 720

using namespace std;

int main(int argc, char **argv)
{
    Window *w = new Window();
    w->Create("test", WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	bool terminated = false;
	SDL_Event event;

    while (!terminated)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                terminated = true;
            }

            if (event.type == SDL_WINDOWEVENT)
            {
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_CLOSE:
                        terminated = true;
                        break;
                    case SDL_WINDOWEVENT_MINIMIZED:
                    	clog << "[I] Window minimized." << endl;
                        break;
                    case SDL_WINDOWEVENT_RESTORED:
                    	clog << "[I] Window restored." << endl; // TODO: configure logging system and use it instead of clog
                        break;
                }
            }
        }

        // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);    It doesn't working...
        // glClear(GL_COLOR_BUFFER_BIT);
    };
}
