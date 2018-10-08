#include "../header/Cone.h"

Cone::Cone(double raio, double centro[3], double topo[3], Material *material_) : Objeto(material_){
	this->raio = raio;

	this->centro[0] = centro[0];
	this->centro[1] = centro[1];
	this->centro[2] = centro[2];

	this->topo[0] = topo[0];
	this->topo[1] = topo[1];
	this->topo[2] = topo[2];

	setCalculos();
}	
void Cone::setCalculos() {
	sub(centro, topo, V);
	altura = norma(V);
	teta = atan(raio/altura);
	vetNormal(V, v);
	lado = sqrt(pow(altura, 2) + pow(raio, 2));
	cosTeta = altura/lado;
}
void Cone::setW(double Pint[3]) {
	sub(Pint, topo, w);
}
double Cone::getT() { return t; }

void Cone::getN(double Pint[3], double *n){
	double aux[3];
	prodVet(V, w, aux);
	prodVet(aux, w, n);
}

bool Cone::intersecaoCor(double D[3], double o[3]) {
	double a, b, c, delta, x1, x2;
	double Pint[3], aux[3];
	
	prodVC(topo, prod(D, v), aux);

	a = pow(prod(D, v), 2) - prod(D, D) * pow(cosTeta, 2);
	b = 2 * prod(topo, D) * pow(cosTeta, 2) - 2 * prod(aux, v);
	c = pow(prod(topo, v), 2) - prod(topo, topo) * pow(cosTeta, 2);

	delta = pow(b, 2) - (4 * a * c);

	if (delta < 0) return false;
	
	if (delta == 0) t = -b / (2*a);
	else{
		x1 = (-b+sqrt(delta))/(2*a);
		x2 = (-b-sqrt(delta))/(2*a);
		t = (x1 < x2) ? x1 : x2;
	}
	
	prodVC(D, t, Pint);
	setW(Pint);

	if (norma(w) < lado and prod(V, w) > 0) return true;
	return false;

}

bool Cone::intersecaoSombra(double D[3], double o[3]) {
	double a, b, c, delta, x1, x2, t, w[3];
	double Pint[3], aux1[3], aux2[3];
	
	prodVC(topo, prod(D, v), aux1);
	prodVC(topo, prod(o, v), aux2);

	a = pow(prod(D, v), 2) - prod(D, D) * pow(cosTeta, 2);

	b = 2 * prod(v, o) * prod(D, v) - 2 * prod(aux1, v) - 2 * prod(o, D) * pow(cosTeta, 2) + 2 * prod(D, topo) * pow(cosTeta, 2);

	c = pow(prod(o, v), 2) - 2 * prod(aux2, v) * pow(prod(topo, v), 2) - prod(o, o) * pow(cosTeta, 2) + 2 * prod(o, topo) * pow(cosTeta, 2) - prod(topo, topo) * pow(cosTeta, 2);

	delta = pow(b, 2) - (4 * a * c);

	if(delta < 0) return false;

	if(delta == 0) t = -b / (2*a);
		
	else{
		x1 = (-b+sqrt(delta))/(2*a);
		x2 = (-b-sqrt(delta))/(2*a);
		t = (x1 < x2) ? x1 : x2;
	}
	prodVC(D, t, Pint);
	sub(Pint, topo, w);

	if (norma(w) < lado and prod(V, w) > 0) return true;
	return false;
	
}

void Cone::mudaCoodCamera(Camera camera){
	camera.transMundoCamera(centro);
	camera.transMundoCamera(topo);
	
}