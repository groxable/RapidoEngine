#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace std;

class Window {
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
