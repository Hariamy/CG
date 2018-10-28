#ifndef CILINDRO_H
#define CILINDRO_H

#include <cmath>
#include <limits>
#include <cstdio>

#include "Objeto.h"
#include "Funcoes.h"
#include "Camera.h"

using namespace std;

class Cilindro : public Objeto{
public:
	Cilindro();
	Cilindro(double raio, double base[3], double topo[3], Material *material_);

	void setW(double observador[3]);
	void getN(double Pint[3], double * n);
	double getT();
	double getRaio();
	
	bool intersecaoCor(double D[3], double o[3]);
	bool intersecaoSombra(double D[3], double o[3]);
	void mudaCoodCamera(Camera *camera);
	void mudaCoodMundo(Camera *camera);


private:
	double raio, delta, t, lado;
	double base[3], topo[3], d[3], E[3], N[3];
	double M[4][4];
	Material *material;
	void setMatriz();

};


#endif //CILINDRO_H