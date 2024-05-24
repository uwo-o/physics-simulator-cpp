#include "window.h"

void resize_callbak(GLFWwindow * window, int w, int h){
    glViewport(0,0,w,h);
}

Window::Window(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Window::~Window(){
    glfwTerminate();
}

GLFWwindow * Window::create(int w, int h){
    GLFWwindow * window = glfwCreateWindow(w,h, "Physim", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }

    glViewport(0,0,w,h);
    glfwSetFramebufferSizeCallback(window, resize_callbak);

    return window;
}