
#include "../header/Triangulo.h"

Triangulo::Triangulo(double P1[3], double P2[3], double P3[3], Material *material_) : Objeto(material_){
	this->P1[0] = P1[0];
	this->P1[1] = P1[1];
	this->P1[2] = P1[2];

	this->P2[0] = P2[0];
	this->P2[1] = P2[1];
	this->P2[2] = P2[2];

	this->P3[0] = P3[0];
	this->P3[1] = P3[1];
	this->P3[2] = P3[2];
	
	setNormal();
}

void Triangulo::getN(double Pint[3], double * n){
	vetNormal(N, n);
}


void Triangulo::setNormal(){
	double V1[3], V2[3];
	sub(P2, P1, V1);
	sub(P3, P1, V2);

	prodVet(V1, V2, N);
}

bool Triangulo::intersecaoCor(double D[3], double o[3]) {
	double n[3], w[3], Pint[3];
	double w1[3], w2[3], w3[3], aux[3], aux1[3], aux2[3], aux3[3];
	double V1[3], V2[3];
	double A1, A2, A3, A;

	vetNormal(N, n);
	sub(P1, o, w); //wbarra
	if (prod(D, n) != 0) t = prod(w, n)/prod(D, n);
	else return false;

	prodVC(D, t, Pint);
	sum(o, Pint, Pint);

	sub(P2, P1, V1);
	sub(P3, P1, V2);
	prodVet(V1, V2, aux);
	A = norma(aux)/2;
	
	sub(P1, Pint, w1);
	sub(P2, Pint, w2);
	sub(P3, Pint, w3);

	prodVet(w1, w2, aux1);
	prodVet(w3, w1, aux2);
	prodVet(w2, w3, aux3);
	/*
	A1 = prod(aux1, n)/2;
	A2 = prod(aux2, n)/2;
	A3 = prod(aux3, n)/2;
	*/

	A1 = norma(aux1)/2;
	A2 = norma(aux2)/2;
	A3 = norma(aux3)/2;

	return abs(A - (A1 + A2 + A3)) < 0.000000005 ? true : false;
	
}
bool Triangulo::intersecaoSombra(double D[3], double o[3]){ return false;}

void Triangulo::mudaCoodCamera(Camera *camera) {
	camera->transMundoCamera(P1);
	camera->transMundoCamera(P2);
	camera->transMundoCamera(P3);
	setNormal();
}
void Triangulo::mudaCoodMundo(Camera *camera) {
	camera->transCameraMundo(P1);
	camera->transCameraMundo(P2);
	camera->transCameraMundo(P3);
	setNormal();
}
