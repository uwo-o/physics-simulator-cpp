#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Coloca aquí tu código de renderización OpenGL
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Tu Proyecto OpenGL");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}