/*
PRA RODAR:
-------modo 1
g++ Luz.cpp Material.cpp Objeto.cpp Cone.cpp Esfera.cpp snowPOO.cpp -o main -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings


-------modo 2
g++ -c Funcoes.cpp -o Funcoes.o && g++ -c Luz.cpp -o Luz.o && g++ -c Objeto.cpp -o Objeto && g++ -c Material.cpp -o Material.o && g++ -c Cone.cpp -o Cone.o &&  g++ -c Esfera.cpp -o Esfera.o && g++ -c snowPOO.cpp -o snowPOO.o

g++ -o main Cone.o Esfera.o Objeto.o Material.o Luz.o Funcoes.o snowPOO.o -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings

--------modo 3
g++ -c *.cpp && g++ -o main *.o -O2 -L -lm -lpthread -lX11 -lGL -lGLU -lGLEW -lglut -Wno-write-strings


fazer camera e cenario
*/


#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../header/main.h"
#include "../CImg-2.4.0/CImg.h"

using namespace std;

static unsigned int   W_Npixels = 700, H_Npixels = 700;
static double         W = 200., H = 200.;


///////////////////FUNÇÃO QUE PINTA A TELA

void rayCasting(void) {
	using namespace cimg_library;
	
	CImg<unsigned char> fundo("../imagem/olaf4.jpg");
	
	int quantObjetos, quantLuzes, indice;
	double l, c, x, y, Dy, Dx, t;
	double v[3], Pint[3], Ipix[3];
	bool intercepta;
	Objeto *cenario[10];
	Luz *luzes[10];

	double d = 1000;

	double observador[3] = {0,0,0};
	double luzAmbiente[3] = {0.5, 0.5, 0.5};
	
	Dx = W/W_Npixels;
	Dy = H/H_Npixels;
	

	setCenario(cenario, luzes, &quantObjetos, &quantLuzes);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
		for(l = 0; l < H_Npixels; l++){
			y = H/2 - Dy/2 - l*Dy;

			for(c = 0; c < W_Npixels; c++){
				x = -W/2 + Dx/2 + c*Dx;

				double pixel[3] = {x, y, -d};
				sub(pixel, observador, v);

				t = std::numeric_limits<double>::max();
				intercepta = false;

				for (int i = 0; i < quantObjetos; i++) {
					if (cenario[i]->intersecaoCor(v, observador)) {
						if (cenario[i]->getT() < t) {
							intercepta = true;
							t = cenario[i]->getT();
							indice = i;
						}
					}
				}

				if (intercepta) {
					double vSombra[3], aux[3], n[3];
					corAmbriente(cenario[indice], luzAmbiente, Ipix);

					bool sombra;
					prodVC(v, t, Pint);
					for (int i = 0; i < quantLuzes; i++) {
						sombra = false;
						luzes[i]->getCoordenada(aux);
						sub(aux, Pint, vSombra);
						cenario[indice]->getN(Pint, n);

						if (prod(n, vSombra) >= 0) {
							for (int j = 0; j < quantObjetos and sombra == false; j++) {
								if (j != indice and cenario[j]->intersecaoSombra(vSombra, Pint)) {
									//sombra = true;
								}
							}

							if (not sombra) corLuz(cenario[indice], Pint, luzes[i], Ipix);	
						}

					}

					cenario[indice]->getN(Pint, aux);

				} else {
					int xImg = c;         //IMAGEM NORMAL
					int yImg = l;		  //IMAGEM NORMAL
					
					//int xImg = W_Npixels - c; //INVERTE IMAGEM
					//int yImg = H_Npixels - l; //INVERTE IMAGEM

					Ipix[0] = (double)fundo(xImg, yImg, 0, 0)/255;
					Ipix[1] = (double)fundo(xImg, yImg, 0, 1)/255;
					Ipix[2] = (double)fundo(xImg, yImg, 0, 2)/255;
				}

				glColor3f(Ipix[0], Ipix[1], Ipix[2]);
				glVertex2f(c, l);
			}
		}

   glEnd();

   glFlush();
}

//Pra fechar a janeça com o ESC
void Teclado(unsigned char key, int x, int y) {	
	switch((char)key) {
		case 27:
			glutDestroyWindow(0);
			exit(0);
			break;
	}
	glutPostRedisplay();
}

void redimenciona(int w, int h) {
	int wSize = w, hSize = h;
	if (h >= w) {
		hSize = w*H/W;
		glViewport(0, (h-hSize)/2, wSize, hSize);
	}
	else if (h < w) {
		wSize = h*W/H;
		glViewport((w-wSize)/2, 0,  wSize, hSize);
	}
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, W_Npixels, H_Npixels, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
	glutInitWindowSize(W_Npixels, H_Npixels);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-W_Npixels)/2,(glutGet(GLUT_SCREEN_HEIGHT)-H_Npixels)/2);

	glutCreateWindow("~s2~ SnowMan Fofiss ~s2~");
	glutDisplayFunc(rayCasting);
	glutReshapeFunc(redimenciona);
	glutKeyboardFunc(Teclado);

	glewExperimental = GL_TRUE;
	glewInit();

	glClearColor(0.8, 0.9, 0.9, 0.0);

	glutMainLoop(); 
}
