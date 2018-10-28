#ifndef MATRIZ_H
#define MATRIZ_H

#include "Vetor.h"

#include <cmath>
#include <exception>
#include <iostream>

class Matriz {
private:
	Vetor a1;
	Vetor a2;
	Vetor a3;
	Vetor a4;

public:
	Matriz();
	
	Matriz(double a11, double a12, double a13,
		   double a21, double a22, double a23,
		   double a31, double a32, double a33);

	Matriz(double a11, double a12, double a13, double a14,
		   double a21, double a22, double a23, double a24,
		   double a31, double a32, double a33, double a34,
		   double a41, double a42, double a43, double a44);

	Matriz(Vetor a1, Vetor a2, Vetor a3);
	Matriz(Vetor a1, Vetor a2, Vetor a3, Vetor a4);


	void setA11(double a11);
	void setA12(double a12);
	void setA13(double a13);
	void setA14(double a14);

	void setA21(double a21);
	void setA22(double a22);
	void setA23(double a23);
	void setA24(double a24);
	
	void setA31(double a31);
	void setA32(double a32);
	void setA33(double a33);
	void setA34(double a34);

	void setA41(double a41);
	void setA42(double a42);
	void setA43(double a43);
	void setA44(double a44);
	
	void setA1(Vetor a1);
	void setA2(Vetor a2);
	void setA3(Vetor a3);
	void setA4(Vetor a4);

	double getA11();
	double getA12();
	double getA13();
	double getA14();

	double getA21();
	double getA22();
	double getA23();
	double getA24();
	
	double getA31();
	double getA32();
	double getA33();
	double getA34();

	double getA41();
	double getA42();
	double getA43();
	double getA44();

	Vetor getA1();
	Vetor getA2();
	Vetor getA3();
	Vetor getA4();

	Matriz operator + (Matriz M);
	Matriz operator - (Matriz M);
	Matriz operator ->*(Matriz M);
	Matriz operator * (double valor);

	void operator += (Matriz M);
	void operator -= (Matriz M);
	void operator *= (double valor);

	void operator = (Matriz M);
	
	Vetor &operator[](int i);
	
	void print();

};


#endif //Matriz_h