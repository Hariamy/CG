#include <iostream>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "CImg-2.4.0/CImg.h"

using namespace cimg_library;

void drawScene(void) {
  double l, c, x, y;
  CImg<unsigned char> image("a.jpg");

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);

  for(l = 0; l < 700; l++){
    y = 700-l;
    for(c = 0; c < 700; c++){
      x = 700-c;
      glColor3f((float)image(x, y, 0, 0)/255, (float)image(x, y, 0, 1)/255, (float)image(x, y, 0, 2)/255);
      glVertex2f(c, l);
    }

  }

  glEnd();

  glFlush();
}


//Pra fechar a janeça com o ESC
void Teclado(unsigned char key, int x, int y) { 
  switch((char)key) {
    // ESC
    case 27:
    glutDestroyWindow(0);
    exit(0);
    break;
  }
  glutPostRedisplay();
}

void setup(void) {
  glClearColor(1.0, 1.0, 1.0, 0.0); 
}

void resize(int w, int h) {
  glViewport(0, 0, w, h); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 700, 0, 700, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);

  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
  glutInitWindowSize(700, 700);
  //glutInitWindowPosition(300, 10); 
  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-700)/2,(glutGet(GLUT_SCREEN_HEIGHT)-700)/2);

  glutCreateWindow("~s2~ SnowMan Fofiss ~s2~");
  glutDisplayFunc(drawScene);
  glutReshapeFunc(resize);
  glutKeyboardFunc(Teclado);

  glewExperimental = GL_TRUE;
  glewInit();

  setup(); 

  glutMainLoop(); 
}
