#ifndef CAMERA_H
#define CAMERA_H

#include "Funcoes.h"

class Camera{
private:
	double coordCamera[3];
	double loockAt[3];
	double viewUp[3];
	double ic[3];
	double jc[3];
	double kc[3];

	double MundoParaCamera[4][4];
	double CameraParaMundo[4][4];

public:
	Camera();
	Camera(double coordCamera[3], double loockAt[3], double viewUp[3]);

	void setCoordenadas();
	void setMatrizes();

	void transCameraMundo(double *ponto);
	void transMundoCamera(double *ponto);
};

#endif //CANERA_H