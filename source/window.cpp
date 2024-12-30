#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>

using namespace std;

class Window
{
public:
    Window();
    ~Window();
    int Create(string windowName, int screenWidth, int screenHeight, Uint32 flags);
    int GetScreenWidth() const;
    int GetScreenHeight() const;
    void SetWindowName();
    void SwapBuffer();
	
private:
    SDL_Window *m_SDL_Window;
    unsigned int m_screenWidth;
    unsigned int m_screenHeight;
    string m_windowName;
    SDL_GLContext m_glContext;
};

Window::Window()
{
    SDL_Init (SDL_INIT_EVERYTHING);
    SDL_GLContext m_glContext = SDL_GL_CreateContext(m_SDL_Window);
}

Window::~Window()
{
    if (m_SDL_Window)
        SDL_DestroyWindow(m_SDL_Window);
	SDL_GL_DeleteContext(m_glContext);
    SDL_Quit();
}

int Window::Create(string windowName, int screenWidth, int screenHeight, Uint32 flags)
{
    m_SDL_Window = SDL_CreateWindow
    (
        windowName.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screenWidth,
        screenHeight,
        SDL_WINDOW_SHOWN
    );

	if (m_SDL_Window == nullptr)
            cerr << "[E] SDL Window could not be created!" << endl;;

    return 0;
}

void Window::SwapBuffer()
{
    SDL_GL_SwapWindow(m_SDL_Window);
}

int Window::GetScreenWidth() const
{
	return m_screenWidth;
}
    
int Window::GetScreenHeight() const
{
	return m_screenHeight;
}
