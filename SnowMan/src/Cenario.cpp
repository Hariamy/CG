#include "../header/Cenario.h"

void setCenario(Objeto *cenario[10], Luz *luzes[10], int *quantObjetos, int *quantLuzes){ 

//-----------------------------CAMERAS-----------------------------//

	double coordCameraFrente[3] = {0, 133, 874}; 
	double loockAtFrente[3] = {0, 116, 746};
	double viewUpFrente[3] = {0, 233, 732};
	Camera cameraFrente(coordCameraFrente, loockAtFrente, viewUpFrente);

	double coordCameraCima[3] = {0, 874, 0}; 
	double loockAtCima[3] = {0, 750, 0};
	double viewUpCima[3] = {0, 760, -320};
	Camera cameraCima(coordCameraCima, loockAtCima, viewUpCima);

	double coordCameraLado[3] = {874, 130, 0}; 
	double loockAtLado[3] = {750, 114, 0};
	double viewUpLado[3] = {760, 320, 0};
	Camera cameraLado(coordCameraLado, loockAtLado, viewUpLado);

	double coordCameraCosta[3] = {0, 0, -974}; 
	double loockAtCosta[3] = {0, 3, -750};
	double viewUpCosta[3] = {0, 320, -750};
	Camera cameraCosta(coordCameraCosta, loockAtCosta, viewUpCosta);

	double coordCameraTortaD[3] = {868, 100, 691}; 
	double loockAtTortaD[3] = {615, 75, 490};
	double viewUpTortaD[3] = {615, 400, 490};
	Camera cameraTortaD(coordCameraTortaD, loockAtTortaD, viewUpTortaD);

	double coordCameraTortaE[3] = {-868, 100, 691}; 
	double loockAtTortaE[3] = {-615, 75, 490};
	double viewUpTortaE[3] = {-615, 400, 490};
	Camera cameraTortaE(coordCameraTortaE, loockAtTortaE, viewUpTortaE);

//-----------------------------MATERIAIS-----------------------------//

	double amb1[3] = {1.5, 1.5, 1.5}; 
	double dif1[3] = {0.6, 0.6, 0.6}; 
	double esp1[3] = {0.6, 0.6, 0.6};
	Material *corpoMat = new Material(amb1, dif1, esp1, 8);

	double amb2[3] = {0.7, 0.3, 0.3}; 
	double dif2[3] = {0.7, 0.3, 0.3}; 
	double esp2[3] = {0.7, 0.5, 0.5};
	Material *botaoMat = new Material(amb2, dif2, esp2, 3);

	double amb3[3] = {0.1, 0.1, 0.1}; 
	double dif3[3] = {0.1, 0.1, 0.1}; 
	double esp3[3] = {0.9, 0.9, 0.9};
	Material *olhoMat = new Material(amb3, dif3, esp3, 9);

	double amb4[3] = {0.2, 0.7, 0.2}; 
	double dif4[3] = {0.2, 0.72, 0.2}; 
	double esp4[3] = {0.8, 0.9, 0.8};
	Material *cartolaMat = new Material(amb4, dif4, esp4, 2);

	double amb5[3] = {0.9, 0.72, 0.2}; 
	double dif5[3] = {0.9, 0.72, 0.2}; 
	double esp5[3] = {0.92, 0.92, 0.92};
	Material *narizMat = new Material(amb5, dif5, esp5, 2);
	
	double amb6[3] = {1, 1, 1}; 
	double dif6[3] = {0.8, 0.8, 0.8}; 
	double esp6[3] = {0.8, 0.8, 0.8};
	Material *pisoMat = new Material(amb6, dif6, esp6, 1);

//-----------------------------LUZES-----------------------------//
	double coodYLuz1 = 1000;
	double coodZLuz1 = 600;
	double coodZLuz2 = 500;

	double coodLuzPoste[3] = {0, 1000, 200};
	double corPoste[3] = {0.6, 0.6, 0.6};
	Luz *poste = new Luz(coodLuzPoste, corPoste);

	double coodLuz1[3] = {-10, coodYLuz1, coodZLuz1};
	double cor[3] = {0.05, 0.05, 0.05};
	Luz *poste1 = new Luz(coodLuz1, cor);

	double coodLuz2[3] = {-5, coodYLuz1, coodZLuz1};
	Luz *poste2 = new Luz(coodLuz2, cor);

	double coodLuz3[3] = {0, coodYLuz1, coodZLuz1};
	Luz *poste3 = new Luz(coodLuz3, cor);

	double coodLuz4[3] = {5, coodYLuz1, coodZLuz1};
	Luz *poste4 = new Luz(coodLuz4, cor);

	double coodLuz5[3] = {10, coodYLuz1, coodZLuz1};
	Luz *poste5 = new Luz(coodLuz5, cor);

	double coodLuz6[3] = {-10, coodYLuz1, coodZLuz2};
	Luz *poste6 = new Luz(coodLuz6, cor);

	double coodLuz7[3] = {-5, coodYLuz1, coodZLuz2};
	Luz *poste7 = new Luz(coodLuz7, cor);

	double coodLuz8[3] = {0, coodYLuz1, coodZLuz2};
	Luz *poste8 = new Luz(coodLuz8, cor);

	double coodLuz9[3] = {5, coodYLuz1, coodZLuz2};
	Luz *poste9 = new Luz(coodLuz9, cor);

	double coodLuz10[3] = {10, coodYLuz1, coodZLuz2};
	Luz *poste10 = new Luz(coodLuz10, cor);

//-----------------------------OBJETOS-----------------------------//

	double centro10[3] = {0, -1050 , 0};
	Objeto *piso = new Esfera(1000, centro10, pisoMat);
	
	double centro1[3] = {0, 40, 0};
	Objeto *cabeca = new Esfera(20.0, centro1, corpoMat);
	
	double centro2[3] = {0, -16, 0};
	Objeto *corpo = new Esfera(40.0, centro2, corpoMat);

	double centro3[3] = {0, 16, 24};
	Objeto *botao1 = new Esfera(3, centro3, botaoMat);

	double centro4[3] = {0, 7, 33};
	Objeto *botao2 = new Esfera(3, centro4, botaoMat);

	double centro5[3] = {0, -3, 38};
	Objeto *botao3 = new Esfera(3, centro5, botaoMat);

	double centro6[3] = {-5, 43, 19};
	Objeto *olho1 = new Esfera(3, centro6, olhoMat);

	double centro7[3] = {5, 43, 19};
	Objeto *olho2 = new Esfera(3, centro7, olhoMat);

	double centro8[3] = {0, 50, 0};
	double topo1[3] = {0, 88, 0};
	Objeto *cartola = new Cone(19, centro8, topo1, cartolaMat);

	double centro9[3] = {0, 34, 18};
	double topo2[3] = {0, 34, 36};
	Objeto *nariz = new Cone(3, centro9, topo2, narizMat);

	double centro11[3] = {0, -50, 0};
	double topo3[3] = {0, 90, 0};
	Objeto *coneSombra = new Cone(19, topo3, centro11, cartolaMat);

//-----------------------------VETOR DE OBJETOS-----------------------------//

	cenario[0] = cabeca;
	cenario[1] = corpo;
	cenario[2] = botao1;
	cenario[3] = botao2;
	cenario[4] = botao3;
	cenario[5] = olho1;
	cenario[6] = olho2;
	cenario[7] = cartola;
	cenario[8] = nariz;
	cenario[9] = piso;

	luzes[0] = poste1;
	luzes[1] = poste2;
	luzes[2] = poste3;
	luzes[3] = poste4;
	luzes[4] = poste5;
	luzes[5] = poste6;
	luzes[6] = poste7;
	luzes[7] = poste8;
	luzes[8] = poste9;
	luzes[9] = poste10;

	
	*quantObjetos = 9;
	*quantLuzes = 10;

/*
	cenario[0] = piso;
	cenario[1] = coneSombra;
*/

//-----------------------------COORDENADA DE MUNDO PARA CAMERA-----------------------------//

	for (int i = 0; i < *quantLuzes; i++) luzes[i]->mudaCoodCamera(cameraTortaE);

	for (int i = 0; i < *quantObjetos; i++) cenario[i]->mudaCoodCamera(cameraTortaE);
}

void corAmbriente(Objeto *obj, double Iamb[3], double *Ipix) {
	double Kamb[3];

	obj->getMaterial().getKamb(Kamb);

	arroba(Iamb, Kamb, Ipix);

}

void corLuz(Objeto *obj, double Pint[3], Luz *luz, double *Ipix) {
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
