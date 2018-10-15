#ifndef OBJETO_H
#define OBJETO_H

#include "Material.h"
#include "Camera.h"

#include <cstdio>

class Objeto{
public:
	Objeto();
	Objeto(Material *material);
	Material getMaterial();
	void setMaterial(Material *material);
	virtual bool intersecaoCor(double D[3], double o[3]){};
	virtual bool intersecaoSombra(double D[3], double o[3]){};
	virtual double getT(){};
	virtual void getN(double Pint[3], double *n){};
	virtual void mudaCoodCamera(Camera *camera){};
	virtual void mudaCoodMundo(Camera *camera){};

private:
	Material *material;

};

#endif //OBJETO_H