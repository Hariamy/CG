#include "../header/Cenario.h"

Cenario::Cenario(){
	quantObjetos = 0;
	quantLuzes = 0;
	quantCameras = 0;
	coordCamera = false;
}

void Cenario::addObjeto(Objeto *objeto) {
	objetos[quantObjetos] = objeto;
	quantObjetos++;
}

void Cenario::addLuz(Luz *luz) {
	luzes[quantLuzes] = luz;
	quantLuzes++;
}

void Cenario::addCamera(Camera *camera) {
	cameras[quantCameras] = camera;
	quantCameras++;
}

void Cenario::setCamera(int indice) {
	if (indice != cameraAtual){
		if (coordCamera) {
			for (int i = 0; i < quantLuzes; i++) luzes[i]->mudaCoodMundo(cameras[cameraAtual]);
			for (int i = 0; i < quantObjetos; i++) objetos[i]->mudaCoodMundo(cameras[cameraAtual]);
		}

		for (int i = 0; i < quantLuzes; i++) luzes[i]->mudaCoodCamera(cameras[indice]);
		for (int i = 0; i < quantObjetos; i++) objetos[i]->mudaCoodCamera(cameras[indice]);
		
		coordCamera = true;
		cameraAtual = indice;
	}
}

bool Cenario::cor(double pixel[3], double *Ipix) {
	double vSombra[3], aux[3], n[3], v[3], Pint[3], t;
	int indice;
	bool intercepta, sombra;
	sub(pixel, observador, v);

	t = std::numeric_limits<double>::max();
	intercepta = false;

	for (int i = 0; i < quantObjetos; i++) {
		if (objetos[i]->intersecaoCor(v, observador)) {
			if (objetos[i]->getT() < t) {
				intercepta = true;
				t = objetos[i]->getT();
				indice = i;
			}
		}
	}

	if (intercepta) {
		corAmbriente(objetos[indice], luzAmbiente, Ipix);
		prodVC(v, t, Pint);
		for (int i = 0; i < quantLuzes; i++) {
			sombra = false;
			luzes[i]->getCoordenada(aux);
			sub(aux, Pint, vSombra);
			objetos[indice]->getN(Pint, n);

			if (prod(n, vSombra) >= 0) {
				for (int j = 0; j < quantObjetos and sombra == false; j++) {
					if (j != indice and objetos[j]->intersecaoSombra(vSombra, Pint)) {
						//sombra = true;
					}
				}

				if (not sombra) corLuz(objetos[indice], Pint, luzes[i], Ipix);	
			}

		}
		return true;
	}
	return false;
}

void Cenario::corAmbriente(Objeto *obj, double Iamb[3], double *Ipix) {
	double Kamb[3];

	obj->getMaterial().getKamb(Kamb);

	arroba(Iamb, Kamb, Ipix);

}

void Cenario::corLuz(Objeto *obj, double Pint[3], Luz *luz, double *Ipix) {
	double aux[3], coodLuz[3], If[3], Kdif[3], Kamb[3], Kesp[3], Iesp[3], Idif[3];
	double v[3], l[3], r[3], n[3]; 
	double prodLN, prodVR;
	double observador[3] = {0, 0, 0};
	int m;


	obj->getN(Pint, n);
	obj->getMaterial().getKesp(Kesp);
	obj->getMaterial().getKdif(Kdif);
	m = obj->getMaterial().getM();

	luz->getIf(If);
	luz->getCoordenada(coodLuz);

	sub(observador, Pint, v);
	sub(coodLuz, Pint, l);
	
	vetNormal(v, v);
	vetNormal(n, n);
	vetNormal(l, l);

	prodLN = prod(l, n);
	if (prodLN < 0) prodLN = 0;
	
	prodVC(n, 2*(prodLN), aux);
	sub(aux, l, r);
	
	prodVR = pow(prod(v, r), m);

	arroba(If, Kdif, Idif);
	arroba(If, Kesp, Iesp);

	prodVC(Idif, prodLN, Idif);
	prodVC(Iesp, prodVR, Iesp);
	
	sum(Ipix, Idif, Ipix);
	sum(Ipix, Iesp, Ipix);


}
