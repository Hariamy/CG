#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <cmath>
#include <limits>
#include <cstdio>
#include <iostream>

#include "Objeto.h"
#include "Funcoes.h"
#include "Camera.h"

using namespace std;

class Triangulo : public Objeto{
public:
	Triangulo();
	Triangulo(double P1[3], double P2[3], double P3[3], Material *material_);

	void getN(double Pint[3], double * n);

	bool intersecaoCor(double D[3], double o[3]);
	bool intersecaoSombra(double D[3], double o[3]);
	void mudaCoodCamera(Camera *camera);
	void mudaCoodMundo(Camera *camera);


private:
	double t, lado;
	double P1[3], P2[3], P3[3], N[3];
	Material *material;
	void setNormal();

};


#endif //TRIANGULO_H