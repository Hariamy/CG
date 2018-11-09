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
#include <string>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../lib/CImg/CImg.h"

#include "../header/ExibeMenu.h"
#include "../header/Cilindro.h"
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
char planoFundo[10][30];
int indiceFundo = 4;
int controlador = 4;
double d;



void setCenario(){

//-----------------------------CAMERAS-----------------------------//

	double lookAt[3] = {0, 20, 0};
	double viewUp[3] = {0, 80, 0};

	double coordCameraFrente[3] = {-1.17, 102.57, 1109.32}; 
	Camera *cameraFrente = new Camera(coordCameraFrente, lookAt, viewUp);

	double coordCameraCosta[3] = {-1.17, 102.57, -1109.32}; 
	Camera *cameraCosta = new Camera(coordCameraCosta, lookAt, viewUp);

	double coordCameraLadoD[3] = {1109.32, 102.57, -1.17}; 
	Camera *cameraLadoD = new Camera(coordCameraLadoD, lookAt, viewUp);

	double coordCameraLadoE[3] = {-1109.32, 102.57, -1.17};
	Camera *cameraLadoE = new Camera(coordCameraLadoE, lookAt, viewUp);

	double coordCameraTortaD[3] = {868, 100, 691}; 
	Camera *cameraTortaD = new Camera(coordCameraTortaD, lookAt, viewUp);

	double coordCameraTortaE[3] = {-868, 100, 691};
	Camera *cameraTortaE = new Camera(coordCameraTortaE, lookAt, viewUp);

	double coordCameraTortaDT[3] = {868, 100, -691};
	Camera *cameraTortaDT = new Camera(coordCameraTortaDT, lookAt, viewUp);

	double coordCameraTortaET[3] = {-868, 100, -691};
	Camera *cameraTortaET = new Camera(coordCameraTortaET, lookAt, viewUp);

	double coordCameraCima[3] = {0, 874, 0}; 
	double loockAtCima[3] = {0, 750, 0};
	double viewUpCima[3] = {0, 760, -320};
	Camera *cameraCima = new Camera(coordCameraCima, loockAtCima, viewUpCima);

	cenario->addCamera(cameraCosta);
	cenario->addCamera(cameraTortaDT);
	cenario->addCamera(cameraLadoD);
	cenario->addCamera(cameraTortaD);
	cenario->addCamera(cameraFrente);
	cenario->addCamera(cameraTortaE);
	cenario->addCamera(cameraLadoE);
	cenario->addCamera(cameraTortaET);


	cenario->addCamera(cameraCima);

//----------------------------MATERIAIS----------------------------//

	double amb1[3] = {2, 2, 2}; 
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

	double amb4[3] = {0.2, 0.72, 0.2}; 
	double dif4[3] = {0.2, 0.72, 0.2}; 
	double esp4[3] = {0.2, 0.72, 0.2};
	Material *cartolaMat = new Material(amb4, dif4, esp4, 10);

	double amb5[3] = {0.9, 0.72, 0.2}; 
	double dif5[3] = {0.9, 0.72, 0.2}; 
	double esp5[3] = {0.92, 0.92, 0.92};
	Material *narizMat = new Material(amb5, dif5, esp5, 2);
	
	double amb6[3] = {1, 1, 1}; 
	double dif6[3] = {0.8, 0.8, 0.8}; 
	double esp6[3] = {0.8, 0.8, 0.8};
	Material *pisoMat = new Material(amb6, dif6, esp6, 1);
	
	double amb7[3] = {1.5, 1.5, 1.5}; 
	double dif7[3] = {0.6, 0.6, 0.6}; 
	double esp7[3] = {0.6, 0.6, 0.6};
	Material *prataMat = new Material(amb7, dif7, esp7, 8);

	double amb8[3] = {0.6, 0.2, 0.2}; 
	double dif8[3] = {0.6, 0.2, 0.2}; 
	double esp8[3] = {0.6, 0.2, 0.2};
	Material *vermelhoMat = new Material(amb8, dif8, esp8, 1);

	double amb9[3] = {1, 0.5, 0}; 
	double dif9[3] = {1, 0.5, 0}; 
	double esp9[3] = {1, 0.5, 0};
	Material *laranjinhaMat = new Material(amb9, dif9, esp9, 1);

	double amb10[3] = {0.59, 0.4, 0.3}; 
	double dif10[3] = {0.59, 0.4, 0.3}; 
	double esp10[3] = {0.59, 0.4, 0.3};
	Material *cigarroMat = new Material(amb10, dif10, esp10, 1);

//-----------------------------OBJETOS-----------------------------//

	double centro10[3] = {0, -2050 , 0};
	Objeto *piso = new Esfera(2000, centro10, cartolaMat);
	
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

	double centro11[3] = {20, -80, 0};
	double topo3[3] = {-20, 40, 0};
	Objeto *coneSombra = new Cone(40, centro11, topo3, cartolaMat);

	double centro12[3] = {100, 0, 0};
	Objeto *esferaSombra = new Esfera(19, centro12, cartolaMat);

	double centro13[3] = {100, 0, -100};
	Objeto *esferaSombra2 = new Esfera(100, centro13, botaoMat);


	double centro14[3] = {20, 30, 0};
	double topo4[3] = {100, 30, 0};
	Objeto *cilindro = new Cilindro(2, centro14, topo4, cigarroMat);

	cenario->addObjeto(piso);
	cenario->addObjeto(cabeca);
	cenario->addObjeto(corpo);
	cenario->addObjeto(botao1);
	cenario->addObjeto(botao2);
	cenario->addObjeto(botao3);
	cenario->addObjeto(olho1);
	cenario->addObjeto(olho2);
	cenario->addObjeto(cartola);
	cenario->addObjeto(nariz);
	cenario->addObjeto(cilindro);
	/*
	
	cenario->addObjeto(coneSombra);
	cenario->addObjeto(esferaSombra);
	cenario->addObjeto(esferaSombra2);
	
	*/

//------------------------------LUZES------------------------------//
	double coodYLuz1 = 1000;
	double coodZLuz1 = 600;
	double coodZLuz2 = 500;

	double coodLuzPoste[3] = {0, 200, 200};
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

	cenario->addLuz(poste);
	/*
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
	*/

//--------------------------IMAGEM FUNDO---------------------------//

	strcpy(planoFundo[0], "../imagem/cubemap/negz.jpg");
	strcpy(planoFundo[1], "../imagem/cubemap/torto2.jpg");
	strcpy(planoFundo[2], "../imagem/cubemap/negx.jpg");
	strcpy(planoFundo[3], "../imagem/cubemap/negzx.jpg");
	strcpy(planoFundo[4], "../imagem/cubemap/posz.jpg");
	strcpy(planoFundo[5], "../imagem/cubemap/poszx.jpg");
	strcpy(planoFundo[6], "../imagem/cubemap/posx.jpg");
	strcpy(planoFundo[7], "../imagem/cubemap/torto1.jpg");
	
	strcpy(planoFundo[8], "../imagem/cubemap/negy.jpg");
	strcpy(planoFundo[9], "../imagem/cubemap/posy.jpg");

}

///////////////////FUNÇÃO QUE PINTA A TELA

void rayCasting(void) {
	using namespace cimg_library;
	
	CImg<unsigned char> plano(planoFundo[indiceFundo]);

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
					if (cenario->getPiso()) {
						Ipix[0] = (double)plano(c, l, 0, 0)/(255 * 2);
						Ipix[1] = (double)plano(c, l, 0, 1)/(255 * 2);
						Ipix[2] = (double)plano(c, l, 0, 2)/(255 * 2);
					
					} else {
						Ipix[0] = (double)plano(c, l, 0, 0)/255;
						Ipix[1] = (double)plano(c, l, 0, 1)/255;
						Ipix[2] = (double)plano(c, l, 0, 2)/255;
						
					}
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
	d = 700;

}

//Pra fechar a janeça com o ESC
void Teclado(unsigned char key, int x, int y) {	
	switch((char)key) {
		case 27: //ESC
			limpaMenu(); glutDestroyWindow(0); exit(0); break;

		case 'A':
			if (controlador - 1 < 0) controlador = 7; 
			else controlador --;
			cenario->setCamera(controlador); indiceFundo = controlador; break;

		case 'a':
			if (controlador - 1 < 0) controlador = 7; 
			else controlador --;
			cenario->setCamera(controlador); indiceFundo = controlador; break;

		case 'D':
			if (controlador + 1 > 7) controlador = 0; 
			else controlador ++;
			cenario->setCamera(controlador); indiceFundo = controlador; break;

		case 'd':
			if (controlador + 1 > 7) controlador = 0; 
			else controlador ++;
			cenario->setCamera(controlador); indiceFundo = controlador; break;
				
		case 'W': 
			cenario->setCamera(8); indiceFundo = 8; break;

		case 'w': 
			cenario->setCamera(8); indiceFundo = 8; break;

		case '+': 
			d += 50; break;

		case '-': 
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
