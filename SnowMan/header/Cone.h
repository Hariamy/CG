#ifndef CONE_H
#define CONE_H

#include <cmath>

#include "Objeto.h"
#include "Camera.h"
#include "Funcoes.h"

class Cone : public Objeto{

public:
	Cone();
	Cone(double raio, double centro[3], double topo[3], Material *material_);
	void setCalculos();
	void setW(double Pint[3]);
	
	double getT();
	void getN(double Pint[3], double *n);
	
	bool intersecaoCor(double D[3], double o[3]);
	bool intersecaoSombra(double D[3], double o[3]);
	void mudaCoodCamera(Camera camera);

private:
	double raio, delta, altura, teta, cosTeta, lado;
	double centro[3], topo[3], w[3], v[3], V[3], t;

	Material *material;
};


#endif //CONE_H