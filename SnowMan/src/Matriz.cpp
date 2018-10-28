#include "../header/Matriz.h"

Matriz::Matriz(){
	a1.setX(1);
	a2.setY(1);
	a3.setZ(1);
	a4.setW(1);
}

Matriz::Matriz(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33){
	a1.set(a11, a12, a13);
	a2.set(a21, a22, a23);
	a3.set(a31, a32, a33);
	a4.setW(1);
}

Matriz::Matriz(Vetor a1, Vetor a2, Vetor a3){
	this->a1 = a1;
	this->a2 = a2;
	this->a3 = a3;
	a4.setW(1);
}

Matriz::Matriz(Vetor a1, Vetor a2, Vetor a3, Vetor a4){
	this->a1 = a1;
	this->a2 = a2;
	this->a3 = a3;
	this->a4 = a4;
}

void Matriz::setA11(double a11){ a1.setX(a11); }
void Matriz::setA12(double a12){ a1.setY(a12); }
void Matriz::setA13(double a13){ a1.setZ(a13); }
void Matriz::setA14(double a14){ a1.setW(a14); }

void Matriz::setA21(double a21){ a2.setX(a21); }
void Matriz::setA22(double a22){ a2.setY(a22); }
void Matriz::setA23(double a23){ a2.setZ(a23); }
void Matriz::setA24(double a24){ a2.setW(a24); }

void Matriz::setA31(double a31){ a3.setX(a31); }
void Matriz::setA32(double a32){ a3.setY(a32); }
void Matriz::setA33(double a33){ a3.setZ(a33); }
void Matriz::setA34(double a34){ a3.setW(a34); }

void Matriz::setA41(double a41){ a4.setX(a41); }
void Matriz::setA42(double a42){ a4.setY(a42); }
void Matriz::setA43(double a43){ a4.setZ(a43); }
void Matriz::setA44(double a44){ a4.setW(a44); }

void Matriz::setA1(Vetor a1){ this->a1 = a1; }
void Matriz::setA2(Vetor a2){ this->a2 = a2; }
void Matriz::setA3(Vetor a3){ this->a3 = a3; }
void Matriz::setA4(Vetor a4){ this->a4 = a4; }

double Matriz::getA11(){ return a1.getX(); }
double Matriz::getA12(){ return a1.getY(); }
double Matriz::getA13(){ return a1.getZ(); }
double Matriz::getA14(){ return a1.getW(); }

double Matriz::getA21(){ return a2.getX(); }
double Matriz::getA22(){ return a2.getY(); }
double Matriz::getA23(){ return a2.getZ(); }
double Matriz::getA24(){ return a2.getW(); }

double Matriz::getA31(){ return a3.getX(); }
double Matriz::getA32(){ return a3.getY(); }
double Matriz::getA33(){ return a3.getZ(); }
double Matriz::getA34(){ return a3.getW(); }

double Matriz::getA41(){ return a4.getX(); }
double Matriz::getA42(){ return a4.getY(); }
double Matriz::getA43(){ return a4.getZ(); }
double Matriz::getA44(){ return a4.getW(); }

Vetor Matriz::getA1(){ return a1; }
Vetor Matriz::getA2(){ return a2; }
Vetor Matriz::getA3(){ return a3; }
Vetor Matriz::getA4(){ return a4; }

Matriz Matriz::operator + (Matriz M){
	Matriz resposta;
	resposta.setA1(getA1() + M.getA1());
	resposta.setA2(getA2() + M.getA2());
	resposta.setA3(getA3() + M.getA3());

	return resposta;
}

Matriz Matriz::operator - (Matriz M){
	Matriz resposta;
	resposta.setA1(getA1() - M.getA1());
	resposta.setA2(getA2() - M.getA2());
	resposta.setA3(getA3() - M.getA3());

	return resposta;
}

Matriz Matriz::operator ->* (Matriz M){
	Matriz resposta;
	resposta.setA11(getA11() * M.getA11() + getA12() * M.getA21() + getA13() * M.getA31() + getA14() * M.getA41());
	resposta.setA12(getA11() * M.getA12() + getA12() * M.getA22() + getA13() * M.getA32() + getA14() * M.getA42());
	resposta.setA13(getA11() * M.getA13() + getA12() * M.getA23() + getA13() * M.getA33() + getA14() * M.getA43());
	resposta.setA14(getA11() * M.getA14() + getA12() * M.getA24() + getA13() * M.getA34() + getA14() * M.getA44());
	
	resposta.setA21(getA21() * M.getA11() + getA22() * M.getA21() + getA23() * M.getA31() + getA24() * M.getA41());
	resposta.setA22(getA21() * M.getA12() + getA22() * M.getA22() + getA23() * M.getA32() + getA24() * M.getA42());
	resposta.setA23(getA21() * M.getA13() + getA22() * M.getA23() + getA23() * M.getA33() + getA24() * M.getA43());
	resposta.setA24(getA21() * M.getA14() + getA22() * M.getA24() + getA23() * M.getA34() + getA24() * M.getA44());
	
	resposta.setA31(getA31() * M.getA11() + getA32() * M.getA21() + getA33() * M.getA31() + getA34() * M.getA41());
	resposta.setA32(getA31() * M.getA12() + getA32() * M.getA22() + getA33() * M.getA32() + getA34() * M.getA42());
	resposta.setA33(getA31() * M.getA13() + getA32() * M.getA23() + getA33() * M.getA33() + getA34() * M.getA43());
	resposta.setA34(getA31() * M.getA14() + getA32() * M.getA24() + getA33() * M.getA34() + getA34() * M.getA44());

	resposta.setA41(getA41() * M.getA11() + getA42() * M.getA21() + getA43() * M.getA31() + getA44() * M.getA41());
	resposta.setA42(getA41() * M.getA12() + getA42() * M.getA22() + getA43() * M.getA32() + getA44() * M.getA42());
	resposta.setA43(getA41() * M.getA13() + getA42() * M.getA23() + getA43() * M.getA33() + getA44() * M.getA43());
	resposta.setA44(getA41() * M.getA14() + getA42() * M.getA24() + getA43() * M.getA34() + getA44() * M.getA44());

	return resposta;
}

Matriz Matriz::operator * (double valor){
	Matriz resposta;
	resposta.setA1(getA1() * valor);
	resposta.setA2(getA2() * valor);
	resposta.setA3(getA3() * valor);
}

void Matriz::operator += (Matriz M){
	setA1(getA1() + M.getA1());
	setA2(getA2() + M.getA2());
	setA3(getA3() + M.getA3());
	setA4(getA4() + M.getA4());
}
void Matriz::operator -= (Matriz M){
	setA1(getA1() - M.getA1());
	setA2(getA2() - M.getA2());
	setA3(getA3() - M.getA3());
	setA4(getA4() - M.getA4());
}
void Matriz::operator *= (double valor){
	setA1(getA1() * valor);
	setA2(getA2() * valor);
	setA3(getA3() * valor);
	setA4(getA4() * valor);
}

void Matriz::operator = (Matriz M){
	setA1(M.getA1());
	setA2(M.getA2());
	setA3(M.getA3());
	setA4(M.getA4());
}

Vetor &Matriz::operator[](int i){
	try {
		switch (i){
			case 0:
				return a1; break;
			case 1:
				return a2; break;
			case 2:
				return a3; break;
		}
	} catch(...){
		throw 20;
	}
}

void Matriz::print(){
	a1.print();
	a2.print();
	a3.print();
	a4.print();
}
