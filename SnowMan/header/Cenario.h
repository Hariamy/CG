#ifndef CENARIO_H
#define CENARIO_H

#include <limits>
#include <cmath>

#include "Luz.h"
#include "Objeto.h"
#include "Esfera.h"
#include "Cone.h"
#include "Funcoes.h"
#include "Camera.h"
#include "Cenario.h"

using namespace std;

class Cenario {
private:
	Camera *cameras[20];
	Objeto *objetos[20];
	Luz *luzes[20];

	int quantObjetos;
	int quantLuzes;
	int quantCameras;
	int cameraAtual;

	bool coordCamera;
	bool piso;

	double observador[3];
	double luzAmbiente[3];

	void corLuz(Objeto *obj, double Pint[3], Luz *luz, double *Ipix);
	void corAmbriente(Objeto *obj, double Iamb[3], double *Ipix);

public:
	Cenario();
	void addObjeto(Objeto *objeto);
	void addLuz(Luz *luz);
	void addCamera(Camera *camera);
	void setCamera(int indice);
	bool cor(double pixel[3], double *Ipix);
	bool getPiso();
	
};

#endif //CENARIO_H