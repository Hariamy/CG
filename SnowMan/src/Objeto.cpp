#include "../header/Objeto.h"

Objeto::Objeto(Material *material_){
	this->material = material_;
}

Material Objeto::getMaterial(){
	return *this->material;
}
void Objeto::setMaterial(Material *material_){
	this->material = material_;
}
bool Objeto::intersecaoCor(double D[3], double o[3]){
	return false;
};

bool Objeto::intersecaoSombra(double D[3], double o[3]){
	return false;
};

double Objeto::getT(){
	return 0.0;
};

void Objeto::getN(double Pint[3], double *n){};

void Objeto::mudaCoodCamera(Camera *camera){};

void Objeto::mudaCoodMundo(Camera *camera){};