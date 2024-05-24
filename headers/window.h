#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void resize_callbak(GLFWwindow *, int, int);

class Window {
    public:
        Window();
        ~Window();
        GLFWwindow * create(int, int);
};


#endif