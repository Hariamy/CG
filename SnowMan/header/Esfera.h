#ifndef ESFERA_H
#define ESFERA_H

#include <cmath>
#include <cstdio>

#include "Objeto.h"
#include "Funcoes.h"
#include "Camera.h"

class Esfera : public Objeto{
public:
	Esfera();
	Esfera(double raio, double centro[3], Material *material_);

	void setW(double observador[3]);
	void getN(double Pint[3], double * n);
	double getT();
	double getRaio();
	
	bool intersecaoCor(double D[3], double o[3]);
	bool intersecaoSombra(double D[3], double o[3]);
	void mudaCoodCamera(Camera *camera);
	void mudaCoodMundo(Camera *camera);


private:
	double raio, delta, t;
	double centro[3], w[3];
	Material *material;

};


#endif //ESFERA_H