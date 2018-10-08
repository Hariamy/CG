#include "Objeto.h"
#include "Luz.h"
#include "Material.h"
#include "Esfera.h"
#include "Cone.h"

void setCenario(Objeto *cenario[10], Luz *luzes[10], int *quantObjetos);
void corPint(Objeto *obj, double Pint[3], Luz *luz, double Iamb[3], double *Ipix, double quant);