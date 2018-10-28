#include "../header/Cilindro.h"
#include <iostream>

Cilindro::Cilindro(double raio, double base[3], double topo[3], Material *material_):Objeto(material_){
	this->raio = raio;
	this->base[0] = base[0];
	this->base[1] = base[1];
	this->base[2] = base[2];

	this->topo[0] = topo[0];
	this->topo[1] = topo[1];
	this->topo[2] = topo[2];

	setMatriz();
}

void Cilindro::setW(double observador[3]){ 
	
}

void Cilindro::setMatriz() {
	double D[3];
	sub(topo, base, D);
	vetNormal(D, d);

	M[0][0] = 1 - d[0]*d[0];
	M[0][1] = - d[0]*d[1];
	M[0][2] = - d[0]*d[2];
	M[0][3] = 0;
	
	M[1][0] = - d[1]*d[0];
	M[1][1] = 1 - d[1]*d[1];
	M[1][2] = d[1]*d[2];
	M[1][3] = 0;

	M[2][0] = - d[2]*d[0];
	M[2][1] = - d[2]*d[1];
	M[2][2] = 1 - d[2]*d[2];
	M[2][3] = 0;

	double H[3];
	sub(base, topo, H);
	lado = norma(H);
}

double Cilindro::getT() { return t; }

double Cilindro::getRaio() { return raio; }

void Cilindro::getN(double Pint[3], double * n){
	n[0] = N[0];
	n[1] = N[1];
	n[2] = N[2];
}

bool Cilindro::intersecaoCor(double D[3], double o[3]) {
	double a, b, c, delta, x1, x2, MD[3], MA[3], Pint[3], V[3], CE[3], A[3], tc, tb, tt, nb[3], nt[3], w[3], aux[3];
	bool intersepta = false;
	t = std::numeric_limits<double>::max(); 
	sub(o, base, A);
	prodMatVet(M, D, MD);
	prodMatVet(M, A, MA);
	setW(o);

	a = prod(MD, MD);
	b = 2 * prod(MA, MD);
	c = prod(MA, MA) - raio*raio;

	delta = (b*b)-(4*a*c);
	
	if(delta < 0) return false;

	if(delta == 0) tc = - b / (2*a);
		
	else{
		x1 = (-b+sqrt(delta))/(2*a);
		x2 = (-b-sqrt(delta))/(2*a);
		tc = (x1 < x2) ? x1 : x2;
	}
	prodVC(D, tc, Pint);
	sub(Pint, base, V);
	prodVC(d, prod(V, d), CE);
	sum(CE, base, E);
	sub(Pint, E, N);

	if (prod(V, d) > 0 and norma(CE) < lado) {
		t = tc;
		intersepta = true;
	}
	//Interceção com a base;

	sub(base, topo, nb);
	vetNormal(nb, nb);
	sub(o, base, w);
	tb = prod(w, nb)/prod(D, nb);
	prodVC(D, tb, Pint);
	sub(w, Pint, aux);
	if (norma(aux) <= raio) {
		t = tb;
		N[0] = nb[0];
		N[1] = nb[1];
		N[2] = nb[2];
		intersepta = true;
	}

	//Interseçao com o topo;
	sub(topo, base, nt);
	vetNormal(nt, nt);
	sub(o, topo, w);
	tt = prod(w, nt)/prod(D, nt);
	prodVC(D, tt, Pint);
	sub(w, Pint, aux);
	if (norma(aux) <= raio and tt < t) {
		t = tt;		
		N[0] = nt[0];
		N[1] = nt[1];
		N[2] = nt[2];
		intersepta = true;
	}

	return intersepta;	

}
bool Cilindro::intersecaoSombra(double D[3], double o[3]) {
	
	return false;
}

void Cilindro::mudaCoodCamera(Camera *camera){
	camera->transMundoCamera(base);
	camera->transMundoCamera(topo);
	setMatriz();
}
void Cilindro::mudaCoodMundo(Camera *camera){
	camera->transCameraMundo(base);
	camera->transCameraMundo(topo);
	setMatriz();

}
