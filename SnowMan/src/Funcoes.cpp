#include "../header/Funcoes.h"

double prod(double vet1[3], double vet2[3]){
	return (vet1[0] * vet2[0]) + (vet1[1] * vet2[1]) + (vet1[2] * vet2[2]);
}

double prodVE(double vet1[3], double esc){
	return (vet1[0] * esc) + (vet1[1] * esc) + (vet1[2] * esc);
}

void arroba(double vet1[3], double vet2[3], double *resp) {
	resp[0] = vet1[0] * vet2 [0];
	resp[1] = vet1[1] * vet2 [1];
	resp[2] = vet1[2] * vet2 [2];
}

void sub(double vet1[3], double vet2[3], double *resp){
	resp[0] = vet1[0] - vet2 [0];
	resp[1] = vet1[1] - vet2 [1];
	resp[2] = vet1[2] - vet2 [2];

}

void sum(double vet1[3], double vet2[3], double *resp){
	resp[0] = vet1[0] + vet2 [0];
	resp[1] = vet1[1] + vet2 [1];
	resp[2] = vet1[2] + vet2 [2];

}

void prodVC(double vet1[3], double val, double *resp){
	resp[0] = vet1[0] * val;
	resp[1] = vet1[1] * val;
	resp[2] = vet1[2] * val;

}

double norma(double vet[3]){
	return sqrt(vet[0] * vet[0] + vet[1] * vet[1] + vet[2] * vet[2]);
}

void vetNormal(double vet[3], double *normal){
	double val = 1/norma(vet);

	prodVC(vet, val, normal);
}

void printaVetor(double vet[3]){
	printf("\n%f %f %f\n", vet[0], vet[1], vet[2]);
}

void prodVet(double v1[3], double v2[3], double *resp){
	resp[0] = (v1[1]*v2[2])-( v2[1]*v1[2]);
	resp[1] = -((v1[0]*v2[2])-( v2[0]*v1[2])); 
	resp[2] = (v1[0]*v2[1])-( v2[0]*v1[1]);
}

void prodMatVet(double M[4][4], double v[3], double *resp) {
	resp[0] = M[0][0] * v[0] + M[0][1] * v[1] + M[0][2] * v[2] + M[0][3];

	resp[1] = M[1][0] * v[0] + M[1][1] * v[1] + M[1][2] * v[2] + M[1][3];

	resp[2] = M[2][0] * v[0] + M[2][1] * v[1] + M[2][2] * v[2] + M[2][3];
}

