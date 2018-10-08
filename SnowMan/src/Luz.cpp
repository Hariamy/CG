#include "../header/Luz.h"

Luz::Luz(double coordenada[3], double If[3]){
	this->coordenada[0] = coordenada[0];
	this->coordenada[1] = coordenada[1];
	this->coordenada[2] = coordenada[2];

	this->If[0] = If[0];
	this->If[1] = If[1];
	this->If[2] = If[2];
}

void Luz::getCoordenada(double *ret){
	ret[0] = coordenada[0];
	ret[1] = coordenada[1];
	ret[2] = coordenada[2];
}

void Luz::getIf(double *ret){
	ret[0] = If[0];
	ret[1] = If[1];
	ret[2] = If[2];
}

void Luz::mudaCoodCamera(Camera camera){
	camera.transMundoCamera(coordenada);
}
