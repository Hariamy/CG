#ifndef LUZ_H
#define LUZ_H

#include "Camera.h"

class Luz{
public:
	Luz(double coordenada[3], double If[3]);

	void getCoordenada(double *ret);
	void getIf(double *ret);

	void mudaCoodCamera(Camera *camera);
	void mudaCoodMundo(Camera *camera);

private:
	double coordenada[3];
	double If[3];
};


#endif //LUZ_H