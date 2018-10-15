/*
PRA RODAR:
-------modo 1
g++ Luz.cpp Material.cpp Objeto.cpp Cone.cpp Esfera.cpp snowPOO.cpp -o main -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings


-------modo 2
g++ -c Funcoes.cpp -o Funcoes.o && g++ -c Luz.cpp -o Luz.o && g++ -c Objeto.cpp -o Objeto && g++ -c Material.cpp -o Material.o && g++ -c Cone.cpp -o Cone.o &&  g++ -c Esfera.cpp -o Esfera.o && g++ -c snowPOO.cpp -o snowPOO.o

g++ -o main Cone.o Esfera.o Objeto.o Material.o Luz.o Funcoes.o snowPOO.o -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings

--------modo 3
g++ -c *.cpp && g++ -o main *.o -O2 -L -lm -lpthread -lX11 -lGL -lGLU -lGLEW -lglut -Wno-write-strings && ./main


fazer camera e cenario
*/

#include <cmath>
#include <cstdio>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../lib/CImg/CImg.h"

#include "../header/ExibeMenu.h"
#include "../header/Luz.h"
#include "../header/Objeto.h"
#include "../header/Esfera.h"
#include "../header/Cone.h"
#include "../header/Funcoes.h"
#include "../header/Camera.h"
#include "../header/Cenario.h"

using namespace std;

static unsigned int   W_Npixels = 700, H_Npixels = 700;
static double         W = 200., H = 200.;

Cenario *cenario = new Cenario();
double d;


void setCenario(){

//-----------------------------CAMERAS-----------------------------//

	double coordCameraFrente[3] = {0, 165, 1105}; 
	double loockAtFrente[3] = {0, 116, 746};
	double viewUpFrente[3] = {0, 233, 732};
	Camera *cameraFrente = new Camera(coordCameraFrente, loockAtFrente, viewUpFrente);

	double coordCameraCosta[3] = {0, 165, -1105}; 
	double loockAtCosta[3] = {0, 116, -746};
	double viewUpCosta[3] = {0, 233, -732};
	Camera *cameraCosta = new Camera(coordCameraCosta, loockAtCosta, viewUpCosta);

	double coordCameraCima[3] = {0, 874, 0}; 
	double loockAtCima[3] = {0, 750, 0};
	double viewUpCima[3] = {0, 760, -320};
	Camera *cameraCima = new Camera(coordCameraCima, loockAtCima, viewUpCima);

	double coordCameraLadoD[3] = {1114, 162, 0}; 
	double loockAtLadoD[3] = {750, 114, 0};
	double viewUpLadoD[3] = {760, 320, 0};
	Camera *cameraLadoD = new Camera(coordCameraLadoD, loockAtLadoD, viewUpLadoD);

	double coordCameraLadoE[3] = {-1114, 162, 0}; 
	double loockAtLadoE[3] = {-750, 114, 0};
	double viewUpLadoE[3] = {-760, 320, 0};
	Camera *cameraLadoE = new Camera(coordCameraLadoE, loockAtLadoE, viewUpLadoE);

	double coordCameraTortaD[3] = {868, 100, 691}; 
	double loockAtTortaD[3] = {615, 75, 490};
	double viewUpTortaD[3] = {615, 400, 490};
	Camera *cameraTortaD = new Camera(coordCameraTortaD, loockAtTortaD, viewUpTortaD);

	double coordCameraTortaE[3] = {-868, 100, 691}; 
	double loockAtTortaE[3] = {-615, 75, 490};
	double viewUpTortaE[3] = {-615, 400, 490};
	Camera *cameraTortaE = new Camera(coordCameraTortaE, loockAtTortaE, viewUpTortaE);

	cenario->addCamera(cameraCosta);
	cenario->addCamera(cameraLadoD);
	cenario->addCamera(cameraTortaD);
	cenario->addCamera(cameraFrente);
	cenario->addCamera(cameraTortaE);
	cenario->addCamera(cameraLadoE);
	cenario->addCamera(cameraCima);

//----------------------------MATERIAIS----------------------------//

	double amb1[3] = {1.5, 1.5, 1.5}; 
	double dif1[3] = {0.6, 0.6, 0.6}; 
	double esp1[3] = {0.6, 0.6, 0.6};
	Material *corpoMat = new Material(amb1, dif1, esp1, 8);

	double amb2[3] = {0.7, 0.3, 0.3}; 
	double dif2[3] = {0.7, 0.3, 0.3}; 
	double esp2[3] = {0.7, 0.5, 0.5};
	Material *botaoMat = new Material(amb2, dif2, esp2, 3);

	double amb3[3] = {0.1, 0.1, 0.1}; 
	double dif3[3] = {0.1, 0.1, 0.1}; 
	double esp3[3] = {0.9, 0.9, 0.9};
	Material *olhoMat = new Material(amb3, dif3, esp3, 9);

	double amb4[3] = {0.2, 0.7, 0.2}; 
	double dif4[3] = {0.2, 0.72, 0.2}; 
	double esp4[3] = {0.8, 0.9, 0.8};
	Material *cartolaMat = new Material(amb4, dif4, esp4, 2);

	double amb5[3] = {0.9, 0.72, 0.2}; 
	double dif5[3] = {0.9, 0.72, 0.2}; 
	double esp5[3] = {0.92, 0.92, 0.92};
	Material *narizMat = new Material(amb5, dif5, esp5, 2);
	
	double amb6[3] = {1, 1, 1}; 
	double dif6[3] = {0.8, 0.8, 0.8}; 
	double esp6[3] = {0.8, 0.8, 0.8};
	Material *pisoMat = new Material(amb6, dif6, esp6, 1);

//-----------------------------OBJETOS-----------------------------//

	double centro10[3] = {0, -1050 , 0};
	Objeto *piso = new Esfera(1000, centro10, pisoMat);
	
	double centro1[3] = {0, 40, 0};
	Objeto *cabeca = new Esfera(20.0, centro1, corpoMat);
	
	double centro2[3] = {0, -16, 0};
	Objeto *corpo = new Esfera(40.0, centro2, corpoMat);

	double centro3[3] = {0, 16, 24};
	Objeto *botao1 = new Esfera(3, centro3, botaoMat);

	double centro4[3] = {0, 7, 33};
	Objeto *botao2 = new Esfera(3, centro4, botaoMat);

	double centro5[3] = {0, -3, 38};
	Objeto *botao3 = new Esfera(3, centro5, botaoMat);

	double centro6[3] = {-5, 43, 19};
	Objeto *olho1 = new Esfera(3, centro6, olhoMat);

	double centro7[3] = {5, 43, 19};
	Objeto *olho2 = new Esfera(3, centro7, olhoMat);

	double centro8[3] = {0, 50, 0};
	double topo1[3] = {0, 88, 0};
	Objeto *cartola = new Cone(19, centro8, topo1, cartolaMat);

	double centro9[3] = {0, 34, 18};
	double topo2[3] = {0, 34, 36};
	Objeto *nariz = new Cone(3, centro9, topo2, narizMat);

	double centro11[3] = {0, -50, 0};
	double topo3[3] = {0, 90, 0};
	Objeto *coneSombra = new Cone(19, topo3, centro11, cartolaMat);

	cenario->addObjeto(cabeca);
	cenario->addObjeto(corpo);
	cenario->addObjeto(botao1);
	cenario->addObjeto(botao2);
	cenario->addObjeto(botao3);
	cenario->addObjeto(olho1);
	cenario->addObjeto(olho2);
	cenario->addObjeto(cartola);
	cenario->addObjeto(nariz);

//------------------------------LUZES------------------------------//
	double coodYLuz1 = 1000;
	double coodZLuz1 = 600;
	double coodZLuz2 = 500;

	double coodLuzPoste[3] = {0, 1000, 200};
	double corPoste[3] = {0.6, 0.6, 0.6};
	Luz *poste = new Luz(coodLuzPoste, corPoste);

	double coodLuz1[3] = {-10, coodYLuz1, coodZLuz1};
	double cor[3] = {0.05, 0.05, 0.05};
	Luz *poste1 = new Luz(coodLuz1, cor);

	double coodLuz2[3] = {-5, coodYLuz1, coodZLuz1};
	Luz *poste2 = new Luz(coodLuz2, cor);

	double coodLuz3[3] = {0, coodYLuz1, coodZLuz1};
	Luz *poste3 = new Luz(coodLuz3, cor);

	double coodLuz4[3] = {5, coodYLuz1, coodZLuz1};
	Luz *poste4 = new Luz(coodLuz4, cor);

	double coodLuz5[3] = {10, coodYLuz1, coodZLuz1};
	Luz *poste5 = new Luz(coodLuz5, cor);

	double coodLuz6[3] = {-10, coodYLuz1, coodZLuz2};
	Luz *poste6 = new Luz(coodLuz6, cor);

	double coodLuz7[3] = {-5, coodYLuz1, coodZLuz2};
	Luz *poste7 = new Luz(coodLuz7, cor);

	double coodLuz8[3] = {0, coodYLuz1, coodZLuz2};
	Luz *poste8 = new Luz(coodLuz8, cor);

	double coodLuz9[3] = {5, coodYLuz1, coodZLuz2};
	Luz *poste9 = new Luz(coodLuz9, cor);

	double coodLuz10[3] = {10, coodYLuz1, coodZLuz2};
	Luz *poste10 = new Luz(coodLuz10, cor);

	cenario->addLuz(poste1);
	cenario->addLuz(poste2);
	cenario->addLuz(poste3);
	cenario->addLuz(poste4);
	cenario->addLuz(poste5);
	cenario->addLuz(poste6);
	cenario->addLuz(poste7);
	cenario->addLuz(poste8);
	cenario->addLuz(poste9);
	cenario->addLuz(poste10);

}

///////////////////FUNÇÃO QUE PINTA A TELA

void rayCasting(void) {
	using namespace cimg_library;
	
	CImg<unsigned char> fundo("../imagem/frozen.jpg");

	double l, c, x, y, Dy, Dx;
	double Ipix[3];
	
	Dx = W/W_Npixels;
	Dy = H/H_Npixels;

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);

		for(l = 0; l < H_Npixels; l++){
			y = H/2 - Dy/2 - l*Dy;

			for(c = 0; c < W_Npixels; c++){
				x = -W/2 + Dx/2 + c*Dx;

				double pixel[3] = {x, y, -d};

				if (not cenario->cor(pixel, Ipix)) {
					Ipix[0] = (double)fundo(c, l, 0, 0)/255;
					Ipix[1] = (double)fundo(c, l, 0, 1)/255;
					Ipix[2] = (double)fundo(c, l, 0, 2)/255;
				}

				glColor3f(Ipix[0], Ipix[1], Ipix[2]);
				glVertex2f(c, l);
			}
		}

   glEnd();

   glFlush();
}

void setGlobais(){
	glClearColor(0.8, 0.9, 0.9, 0.0);
	setCenario();
	cenario->setCamera(4);
	d = 900;
}

//Pra fechar a janeça com o ESC
void Teclado(unsigned char key, int x, int y) {	
	switch((char)key) {
		case 27: //ESC
			limpaMenu(); glutDestroyWindow(0); exit(0); break;

		case 48: //0
			cenario->setCamera(0); break;

		case 49: //1
			cenario->setCamera(1); break;

		case 50: //2
			cenario->setCamera(2); break;

		case 51: //3
			cenario->setCamera(3); break;

		case 52: //4
			cenario->setCamera(4); break;

		case 53: //5
			cenario->setCamera(5); break;
		
		case 54: //6
			cenario->setCamera(6); break;

		case 43: //+
			d += 50; break;

		case 45: //-
			d -= 50; break;

		default:
			break;
	}
	glutPostRedisplay();
}

void redimenciona(int w, int h) {
	int hSize = w*H/W;
	int wSize = h*W/H;

	if (h >= w) 
		glViewport(0, (h-hSize)/2, w, hSize);
	
	else if (h < w) 
		glViewport((w-wSize)/2, 0,  wSize, h);
	
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, W_Npixels, H_Npixels, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv) {
	exibeMenu();
	setGlobais();

	glutInit(&argc, argv);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
	glutInitWindowSize(W_Npixels, H_Npixels);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-W_Npixels)/2,(glutGet(GLUT_SCREEN_HEIGHT)-H_Npixels)/2);

	glutCreateWindow("_-_-_-_-_-_ Snowman _-_-_-_-_-_");
	glutDisplayFunc(rayCasting);
	glutReshapeFunc(redimenciona);
	glutKeyboardFunc(Teclado);
	glutCloseFunc(limpaMenu);

	glewExperimental = GL_TRUE;
	glewInit();

	glutMainLoop(); 
}
