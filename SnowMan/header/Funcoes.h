#ifndef FUNCOES_H
#define FUNCOES_H

#include <cmath>
#include <cstdio>

double prod(double vet1[3], double vet2[3]);

double prodVE(double vet1[3], double esc);

void arroba(double vet1[3], double vet2[3], double *resp);

void sub(double vet1[3], double vet2[3], double *resp);

void sum(double vet1[3], double vet2[3], double *resp);

void prodVC(double vet1[3], double val, double *resp);

double norma(double vet[3]);

void vetNormal(double vet[3], double *normal);

void printaVetor(double vet[3]);

void prodVet(double v1[3], double v2[3], double *resp);

void prodMatVet(double M[4][4], double v[3], double *resp);

#endif //FUNCOES_H