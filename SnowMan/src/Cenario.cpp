#include "../header/Cenario.h"

void setCenario(Objeto *cenario[10], Luz *luzes[10], int *quantObjetos){
	double coordCamera[3] = {0, 133, 874}; 
	double loockAt[3] = {0, 116, 746};
	double viewUp[3] = {0, 233, 732};
	Camera camera(coordCamera, loockAt, viewUp);

	double coordCameraCima[3] = {0, 874, 0}; 
	double loockAtCima[3] = {0, 750, 0};
	double viewUpCima[3] = {0, 760, -320};
	Camera cameraCima(coordCameraCima, loockAtCima, viewUpCima);

	double coordCameraLado[3] = {874, 130, 0}; 
	double loockAtLado[3] = {750, 114, 0};
	double viewUpLado[3] = {760, 320, 0};
	Camera cameraLado(coordCameraLado, loockAtLado, viewUpLado);

	double amb1[3] = {0.8, 0.8, 0.8}; 
	double dif1[3] = {0.7, 0.7, 0.7}; 
	double esp1[3] = {0.7, 0.7, 0.7};
	Material *corpoMat = new Material(amb1, dif1, esp1, 1);

	double amb2[3] = {0.7, 0.4, 0.4}; 
	double dif2[3] = {0.7, 0.3, 0.3}; 
	double esp2[3] = {0.7, 0.3, 0.3};
	Material *botaoMat = new Material(amb2, dif2, esp2, 3);

	double amb3[3] = {0.1, 0.1, 0.1}; 
	double dif3[3] = {0.1, 0.1, 0.1}; 
	double esp3[3] = {0.9, 0.9, 0.9};
	Material *olhoMat = new Material(amb3, dif3, esp3, 9);

	double amb4[3] = {0.2, 0.7, 0.2}; 
	double dif4[3] = {0.72, 0.72, 0.72}; 
	double esp4[3] = {0.92, 0.92, 0.92};
	Material *cartolaMat = new Material(amb4, dif4, esp4, 2);

	double amb5[3] = {0.9, 0.72, 0.2}; 
	double dif5[3] = {0.9, 0.72, 0.2}; 
	double esp5[3] = {0.92, 0.92, 0.92};
	Material *narizMat = new Material(amb5, dif5, esp5, 2);

	double coodLuz[3] = {0, 200, 400};
	double cor[3] = {0.3, 0.3, 0.3};
	Luz *poste = new Luz(coodLuz, cor);

	//Informações dos Objetos
	//CORPO 
	double centro1[3] = {0, 20, -40};
	Objeto *cabeca = new Esfera(23.0, centro1, corpoMat);
	
	double centro2[3] = {0, -16, -51};
	Objeto *corpo = new Esfera(40.0, centro2, corpoMat);

	double centro3[3] = {0, 0, -15};
	Objeto *botao1 = new Esfera(2, centro3, botaoMat);

	double centro4[3] = {0, -6, -13.7};
	Objeto *botao2 = new Esfera(2, centro4, botaoMat);

	double centro5[3] = {0, -10, -12.5};
	Objeto *botao3 = new Esfera(2, centro5, botaoMat);

	double centro6[3] = {4, 20, -19};
	Objeto *olho1 = new Esfera(2, centro6, olhoMat);

	double centro7[3] = {-4, 20, -19};
	Objeto *olho2 = new Esfera(2, centro7, olhoMat);

	double centro8[3] = {0, 21, -30};
	double topo1[3] = {0, 38, -15};
	Objeto *cartola = new Cone(24.6, centro8, topo1, cartolaMat);

	double centro9[3] = {0, 17, -20};
	double topo2[3] = {0, 17, -15};
	Objeto *nariz = new Cone(2, centro9, topo2, narizMat);

/////////////////////OBJETOS DE TESTE////////////////////////////////////
	double centro10[3] = {0, -240 , 0};
	Objeto *piso = new Esfera(200, centro10, corpoMat);
	
	double centro1T[3] = {0, 40, 0};
	Objeto *cabecaT = new Esfera(20.0, centro1T, corpoMat);
	
	double centro2T[3] = {0, -16, 0};
	Objeto *corpoT = new Esfera(40.0, centro2T, corpoMat);

	double centro3T[3] = {0, 16, 24};
	Objeto *botao1T = new Esfera(3, centro3T, botaoMat);

	double centro4T[3] = {0, 6, 33};
	Objeto *botao2T = new Esfera(3, centro4T, botaoMat);

	double centro5T[3] = {0, -3, 38};
	Objeto *botao3T = new Esfera(3, centro5T, botaoMat);

	double centro6T[3] = {-5, 43, 19};
	Objeto *olho1T = new Esfera(3, centro6T, olhoMat);

	double centro7T[3] = {5, 43, 19};
	Objeto *olho2T = new Esfera(3, centro7T, olhoMat);

	double centro8T[3] = {0, 50, 0};
	double topo1T[3] = {0, 88, 0};
	Objeto *cartolaT = new Cone(19, centro8T, topo1T, cartolaMat);

	double centro9T[3] = {0, 34, 36};
	double topo2T[3] = {0, 34, 20};
	Objeto *narizT = new Cone(3, centro9T, topo2T, narizMat);

	cenario[0] = cabecaT;
	cenario[1] = corpoT;
	cenario[2] = botao1T;
	cenario[3] = botao2T;
	cenario[4] = botao3T;
	cenario[5] = olho1T;
	cenario[6] = olho2T;
	cenario[7] = cartolaT;
	cenario[8] = narizT;
	cenario[9] = piso;

	//cenario[0] = narizT;
	luzes[0] = poste;

	*quantObjetos = 10;
	for (int i = 0; i < 1; i++) luzes[i]->mudaCoodCamera(camera);

	for (int i = 0; i < *quantObjetos; i++) cenario[i]->mudaCoodCamera(camera);
}

void corPint(Objeto *obj, double Pint[3], Luz *luz, double Iamb[3], double *Ipix, double quant){

	double aux[3], coodLuz[3], If[3], Kdif[3], Kamb[3], Kesp[3], Iam[3], Iesp[3], Idif[3];
	double v[3], l[3], r[3], n[3]; 
	double prodLuN, prodVeR;
	double observador[3] = {0, 0, 0};

	obj->getMaterial().getKamb(Kamb);
	obj->getMaterial().getKesp(Kesp);
	obj->getMaterial().getKdif(Kdif);
	int m = obj->getMaterial().getM();

	luz->getIf(If);
	luz->getCoordenada(coodLuz);

	sub(observador, Pint, v);
	obj->getN(Pint, n);
	sub(coodLuz, Pint, l);

	vetNormal(v, v);
	vetNormal(n, n);
	vetNormal(l, l);

	prodLuN = prod(l, n);

	if (prodLuN < 0) prodLuN = 0;

	prodVC(n, 2*(prod(l, n)), aux);
	sub(aux, l, r);

	prodVeR = pow(prod(v, r), m);

	arroba(Iamb, Kamb, Iam);
	arroba(If, Kdif, Idif);
	arroba(If, Kesp, Iesp);

	prodVC(Idif, prodLuN, Idif);
	prodVC(Iesp, prodVeR, Iesp);
	

	sum(Iam, Idif, Ipix);
	sum(Ipix, Iesp, Ipix);
	

	Ipix[0] = Ipix[0]/quant;	
	Ipix[1] = Ipix[1]/quant;	
	Ipix[2] = Ipix[2]/quant;	
}	