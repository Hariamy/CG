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
