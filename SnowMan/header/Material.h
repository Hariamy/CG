#ifndef MATERIAL_H
#define MATERIAL_H

class Material{
public:
	Material();
	Material(double Kamb[3], double Kdif[3], double Kesp[3], int m);
	void getKamb(double Kamb[3]);
	void getKdif(double Kdif[3]);
	void getKesp(double Kesp[3]);
	int getM();
private:
	double Kamb[3];
	double Kdif[3];
	double Kesp[3];
	double m;
};

#endif //MATERIAL_H