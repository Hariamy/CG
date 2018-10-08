#include "../header/Material.h"

Material::Material(double Kamb[3], double Kdif[3], double Kesp[3], int m){
	this->m = m;
	this->Kamb[0] = Kamb[0];
	this->Kamb[1] = Kamb[1];
	this->Kamb[2] = Kamb[2];

	this->Kdif[0] = Kdif[0];
	this->Kdif[1] = Kdif[1];
	this->Kdif[2] = Kdif[2];

	this->Kesp[0] = Kesp[0];
	this->Kesp[1] = Kesp[1];
	this->Kesp[2] = Kesp[2];
}
void Material::getKamb(double Kamb[3]){
	Kamb[0] = this->Kamb[0];
	Kamb[1] = this->Kamb[1];
	Kamb[2] = this->Kamb[2];
}
void Material::getKdif(double Kdif[3]){
	Kdif[0] = this->Kdif[0];
	Kdif[1] = this->Kdif[1];
	Kdif[2] = this->Kdif[2];
}
void Material::getKesp(double Kesp[3]){
	Kesp[0] = this->Kesp[0];
	Kesp[1] = this->Kesp[1];
	Kesp[2] = this->Kesp[2];

}
int Material::getM(){ return m; }