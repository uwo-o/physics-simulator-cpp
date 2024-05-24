#include "constants.h"
#include "window.h"

#include <iostream>

int main(int argc, char** argv) {
    Window * window = new Window();
    GLFWwindow * m_window = window->create(1280,720);

    while(!glfwWindowShouldClose(m_window)){
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    delete window;

    return 0;
}