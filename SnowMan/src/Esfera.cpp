#include "../header/Esfera.h"

Esfera::Esfera(double raio, double centro[3], Material *material_):Objeto(material_){
	this->raio = raio;
	this->centro[0] = centro[0];
	this->centro[1] = centro[1];
	this->centro[2] = centro[2];
}
void Esfera::setW(double observador[3]){ 
	sub(observador, centro, w); 
}

double Esfera::getT() { return t; }
double Esfera::getRaio() { return raio; }

void Esfera::getN(double Pint[3], double * n){
	sub(Pint, centro, n);
}

bool Esfera::intersecaoCor(double D[3], double o[3]) {
	double a, b, c, delta, x1, x2;
	
	setW(o);

	a = prod(D, D);
	b = 2 * prod(D, w);
	c = prod(w, w) - raio*raio;

	delta = (b*b)-(4*a*c);
	
	if(delta < 0) return false;
	else {
		if(delta == 0) t = - b / (2*a);
			
		else{
			x1 = (-b+sqrt(delta))/(2*a);
			x2 = (-b-sqrt(delta))/(2*a);
			t = (x1 < x2) ? x1 : x2;
		}

		return true;	
	}
}
bool Esfera::intersecaoSombra(double D[3], double o[3]) {
	double a, b, c, delta, x1, x2, w[3], t, Pint[3];
	
	sub(o, centro, w); 
	
	a = prod(D, D);
	b = 2 * prod(D, w) + 2 *prod(o, D);
	c = prod(w, w) + 2 * prod(w, o) + prod(o, o) - raio*raio;

	delta = (b*b) - (4*a*c);
	if(delta < 0) return false;
	else {
		if(delta == 0) t = -b / (2*a);
			
		else{
			x1 = (-b+sqrt(delta))/(2*a);
			x2 = (-b-sqrt(delta))/(2*a);
			t = (x1 < x2) ? x2 : x1;
		}
		prodVC(D, t, Pint);
		sum(o, Pint, Pint);
		double aux[3];
		getN(Pint, aux);

		if (prod(D, aux) < 0) return false;
	}
	return true;
}

void Esfera::mudaCoodCamera(Camera camera){
	camera.transMundoCamera(centro);

}