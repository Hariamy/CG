#include "../header/Camera.h"

Camera::Camera(double coordCamera[3], double loockAt[3], double viewUp[3]){
	this->coordCamera[0] = coordCamera[0];
	this->coordCamera[1] = coordCamera[1];
	this->coordCamera[2] = coordCamera[2];

	this->loockAt[0] = loockAt[0];
	this->loockAt[1] = loockAt[1];
	this->loockAt[2] = loockAt[2];

	this->viewUp[0] = viewUp[0];
	this->viewUp[1] = viewUp[1];
	this->viewUp[2] = viewUp[2];

	setCoordenadas();
	setMatrizes();
}

void Camera::setCoordenadas(){
	double Kc[3], Ic[3], Jc[3], aux[3];
	sub(coordCamera, loockAt, Kc);
	vetNormal(Kc, kc);

	sub(viewUp, loockAt, aux);
	prodVet(aux, Kc, Ic);
	vetNormal(Ic, ic);

	prodVet(kc, ic, Jc);
	vetNormal(Jc, jc);
}

void Camera::setMatrizes(){
	CameraParaMundo[0][0] = ic[0];
	CameraParaMundo[0][1] = jc[0];
	CameraParaMundo[0][2] = kc[0];
	CameraParaMundo[0][3] = coordCamera[0];

	CameraParaMundo[1][0] = ic[1];
	CameraParaMundo[1][1] = jc[1];
	CameraParaMundo[1][2] = kc[1];
	CameraParaMundo[1][3] = coordCamera[1];

	CameraParaMundo[2][0] = ic[2];
	CameraParaMundo[2][1] = jc[2];
	CameraParaMundo[2][2] = kc[2];
	CameraParaMundo[2][3] = coordCamera[2];

	CameraParaMundo[3][0] = 0;
	CameraParaMundo[3][1] = 0;
	CameraParaMundo[3][2] = 0;
	CameraParaMundo[3][3] = 1;		


	MundoParaCamera[0][0] = ic[0];
	MundoParaCamera[0][1] = ic[1];
	MundoParaCamera[0][2] = ic[2];
	MundoParaCamera[0][3] = - prod(ic, coordCamera);

	MundoParaCamera[1][0] = jc[0];
	MundoParaCamera[1][1] = jc[1];
	MundoParaCamera[1][2] = jc[2];
	MundoParaCamera[1][3] = - prod(jc, coordCamera);

	MundoParaCamera[2][0] = kc[0];
	MundoParaCamera[2][1] = kc[1];
	MundoParaCamera[2][2] = kc[2];
	MundoParaCamera[2][3] = - prod(kc, coordCamera);

	MundoParaCamera[3][0] = 0;
	MundoParaCamera[3][1] = 0;
	MundoParaCamera[3][2] = 0;
	MundoParaCamera[3][3] = 1;

}

void Camera::transMundoCamera(double *ponto){
	double aux[3];
	aux[0] = MundoParaCamera[0][0] * ponto[0] + MundoParaCamera[0][1] * ponto[1] + MundoParaCamera[0][2] * ponto[2] + MundoParaCamera[0][3];

	aux[1] = MundoParaCamera[1][0] * ponto[0] + MundoParaCamera[1][1] * ponto[1] + MundoParaCamera[1][2] * ponto[2] + MundoParaCamera[1][3];

	aux[2] = MundoParaCamera[2][0] * ponto[0] + MundoParaCamera[2][1] * ponto[1] + MundoParaCamera[2][2] * ponto[2] + MundoParaCamera[2][3];
	
	for (int i = 0; i < 3; i++) ponto[i] = aux[i];
}

void Camera::transCameraMundo(double *ponto){
	double aux[3];
	aux[0] = CameraParaMundo[0][0] * ponto[0] + CameraParaMundo[0][1] * ponto[1] + CameraParaMundo[0][2] * ponto[2] + CameraParaMundo[0][3];

	aux[1] = CameraParaMundo[1][0] * ponto[0] + CameraParaMundo[1][1] * ponto[1] + CameraParaMundo[1][2] * ponto[2] + CameraParaMundo[1][3];

	aux[2] = CameraParaMundo[2][0] * ponto[0] + CameraParaMundo[2][1] * ponto[1] + CameraParaMundo[2][2] * ponto[2] + CameraParaMundo[2][3];
	
	for (int i = 0; i < 3; i++) ponto[i] = aux[i];
}