
#include "../header/snowPOO.h"

/*
PRA RODAR:
-------modo1:
g++ Luz.cpp Material.cpp Objeto.cpp Cone.cpp Esfera.cpp snowPOO.cpp -o main -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings


-------modo 2
g++ -c Funcoes.cpp -o Funcoes.o && g++ -c Luz.cpp -o Luz.o && g++ -c Objeto.cpp -o Objeto && g++ -c Material.cpp -o Material.o && g++ -c Cone.cpp -o Cone.o &&  g++ -c Esfera.cpp -o Esfera.o && g++ -c snowPOO.cpp -o snowPOO.o

g++ -o main Cone.o Esfera.o Objeto.o Material.o Luz.o Funcoes.o snowPOO.o -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings

--------modo 3
g++ -c *.cpp && g++ -o main *.o -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings

*/

#  include <GL/glew.h>
#  include <GL/freeglut.h>

using namespace std;

#define left    -350.0
#define right   350.0

#define top     350.0
#define bottom  -350.0

double largura = 700.0;
double altura = 700.0;

///////////////////FUNÇÃO QUE PINTA A TELA
void drawScene(void) {
	double l, c, x, y;
	double d = -3500;
	double v[3], Pint[3], Ipix[3];
	double observador[3] = {0,0,0};

	double luzAmbiente[3] = {1, 1, 1};
	int quantObjetos;
	
	Objeto *cenario[10];
	Luz *luzes[10];

	setCenario(cenario, luzes, &quantObjetos);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	for(l = 0; l < 700; l++){
	 y = bottom + l;

	 for(c = 0; c < 700; c++){
	    x = left + c;

	    double pixel[3] = {x, y, d};

	    sub(pixel, observador, v);

	    Ipix[0] = 0.8;
	    Ipix[1] = 0.9;
	    Ipix[2] = 0.9;

	    double t = std::numeric_limits<double>::max();
	    int indice = -1;
	    
	    for (int i = 0; i < quantObjetos; i++) {
	    	if (cenario[i]->intersecaoCor(v, observador)) {
	    		if (cenario[i]->getT() < t) {
	    			t = cenario[i]->getT();
	    			indice = i;
	    		}
	    		
	    	}
	    }
	    if (indice != -1) {
	    	double quantSombra = 1;
	    	prodVC(v, t, Pint);
	    
	    	double vSombra[3];
	    	double aux[3];
	    	bool IndiceIgual = false;
	    	luzes[0]->getCoordenada(aux);
	    	
	    	for (int i = 0; i < quantObjetos; i++) {
	    		sub(aux, Pint, vSombra);
		    	if (cenario[i]->intersecaoSombra(vSombra, Pint)) {
		    		if (i == indice) IndiceIgual = true;

		    		quantSombra += 10;
		    	}
		    }
		    //if (IndiceIgual) quantSombra = 1;
			
	    	corPint(cenario[indice], Pint, luzes[0], luzAmbiente, Ipix, quantSombra);
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

// Adicionei as coordenadas ordo aqui.
int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("SnowMan");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(Teclado);

	glewExperimental = GL_TRUE;
	glewInit();

	setup(); 

	glutMainLoop(); 
}
