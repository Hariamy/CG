#include "../header/Vetor.h"

Vetor::Vetor(){
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vetor::Vetor(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	w = 0;
}

Vetor::Vetor(double x, double y, double z, double w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double Vetor::getX(){ return x; }
double Vetor::getY(){ return y; }
double Vetor::getZ(){ return z; }
double Vetor::getW(){ return w; }

void Vetor::setX(double x){ this->x = x; }
void Vetor::setY(double y){ this->y = y; }
void Vetor::setZ(double z){ this->z = z; }
void Vetor::setW(double w){ this->w = w; }
void Vetor::set(double x, double y, double z){
	this->x = x; 
	this->y = y; 
	this->z = z; 
}

Vetor Vetor::operator + (Vetor v){
	Vetor retorno(x + v.getX(), y + v.getY(), z + v.getZ(), w + v.getW());
	return retorno;
}

Vetor Vetor::operator - (Vetor v){
	Vetor retorno(x - v.getX(), y - v.getY(), z - v.getZ(), w - v.getW());
	return retorno;
}

Vetor Vetor::operator * (double valor){
	Vetor retorno(valor * getX(), valor * getY(), valor * getZ(), valor * getW());
	return retorno;
}

void Vetor::operator += (Vetor v){
	setX(getX() + v.getX());
	setY(getY() + v.getY());
	setZ(getZ() + v.getZ());
	setW(getW() + v.getW());
}

void Vetor::operator -= (Vetor v){
	setX(getX() - v.getX());
	setY(getY() - v.getY());
	setZ(getZ() - v.getZ());
	setW(getW() - v.getW());
}
void Vetor::operator *= (double valor){
	setX(getX() * valor);
	setY(getY() * valor);
	setZ(getZ() * valor);
	setW(getW() * valor);
}

Vetor Vetor::operator ->*(Vetor v){
	Vetor retorno(y*v.getZ() - v.getY()*z, -(x*v.getZ() - v.getX()*z), x*v.getY() - v.getX()*y);
	return retorno;
}

void Vetor::operator = (Vetor v){
	setX(v.getX());
	setY(v.getY());
	setZ(v.getZ());
	setW(v.getW());
}

double Vetor::operator * (Vetor v){
	return x * v.getX() + y * v.getY() + z * v.getZ() + w * v.getW();
}

double &Vetor::operator[](int i){
	try {
		switch (i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
			case 3:
				return w; break;
		}
	} catch(...){
		throw 20;
	}
}

Vetor Vetor::normaliza(){
	Vetor retorno(x, y, z);
	retorno *= (1/norma());
	return retorno;
}

double Vetor::norma(){
	return sqrt(x * x + y * y + z * z);
}

void Vetor::print(){
	std::cout << x << " " << y << " " << z << " " << w << std::endl;
}