#include "windows.h"

const char * TITLE = "[physim] Physics Engine";

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Coloca aquí tu código de renderización OpenGL
    glutSwapBuffers();
}

void windows(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow(TITLE);
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}