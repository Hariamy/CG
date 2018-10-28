#ifndef VETOR_H
#define VETOR_H
 
#include <cmath>
#include <exception>
#include <iostream>

class Vetor {
private:
	double x, y, z, w;

public:
	Vetor();
	Vetor(double x, double y, double z);
	Vetor(double x, double y, double z, double w);

	double getX();
	double getY();
	double getZ();
	double getW();

	void set(double x, double y, double z);

	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void setW(double w);

	Vetor operator + (Vetor v);
	Vetor operator - (Vetor v);
	Vetor operator ->*(Vetor v);
	Vetor operator * (double valor);
	
	void operator += (Vetor v);
	void operator -= (Vetor v);
	void operator *= (double valor);
	
	void operator = (Vetor v);
	double operator * (Vetor v);
	double &operator[](int i);
	
	Vetor normaliza();
	double norma();

	void print();
};

#endif //VETOR_H