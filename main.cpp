#define SDL_MAIN_HANDLED

#include <iostream>

#include "MainWindow.h"

int main()
{
    MainWindow *window = new MainWindow();
    window->StartWindowLoop();
    delete window;
    return 0;
}
