#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstdio>
/*
pRA RODAR: 
g++ SnowMan.cpp -o main -lGL -lGLU -lGLEW -lglut -lm -Wno-write-strings
*/


#  include <GL/glew.h>
#  include <GL/freeglut.h>


using namespace std;

#define left    -250.0f
#define right   250.0f

#define top     250.0f
#define bottom  -250.0f

#define largura 500.0f
#define altura 500.0f

/////////////////CONSTANTES PARA A LUZZZ //////////////////////
float Iamb[3] = {1, 1, 1};
float If[3] = {0.3, 0.3, 0.3};

float Luz[3] = {0, 20, 50};
//float Luz[3] = {0, 0, -60};

/////////////////VARIÁVEIS PARA A LUZZZ //////////////////////
float n[3];
float lu[3];
float r[3];
float ve[3];

float prodLuN;
float prodVeR;
float Pint[3];

float Iam[3];
float Idif[3];
float Iesp[3];
float Ipix[3];

float Kamb[3] = {0.8, 0.8, 0.8};
float Kdif[3] = {0.7, 0.7, 0.7};
float Kesp[3] = {0.7, 0.7, 0.7};

float Kambb[3] = {0.7, 0.4, 0.4};
float Kdifb[3] = {0.7, 0.3, 0.3};
float Kespb[3] = {0.7, 0.3, 0.3};

float Kambo[3] = {0.1, 0.1, 0.1};
float Kdifo[3] = {0.1, 0.1, 0.1};
float Kespo[3] = {0.9, 0.9, 0.9};


////////////////LARGURINHA DO QUADRADO///////////////
float dx = (right - left)/largura;
float dy = (top - bottom)/altura;

////////////////FUNÇÕES DE VETORES//////////////////
float prod(float vet1[3], float vet2[3]){
   return (vet1[0] * vet2[0]) + (vet1[1] * vet2[1]) + (vet1[2] * vet2[2]);
}

float prodVE(float vet1[3], float esc){
   return (vet1[0] * esc) + (vet1[1] * esc) + (vet1[2] * esc);
}

float arroba(float vet1[3], float vet2[3], float *resp) {
   resp[0] = vet1[0] * vet2 [0];
   resp[1] = vet1[1] * vet2 [1];
   resp[2] = vet1[2] * vet2 [2];
}

void sub(float vet1[3], float vet2[3], float *resp){
   resp[0] = vet1[0] - vet2 [0];
   resp[1] = vet1[1] - vet2 [1];
   resp[2] = vet1[2] - vet2 [2];

}

void sum(float vet1[3], float vet2[3], float *resp){
   resp[0] = vet1[0] + vet2 [0];
   resp[1] = vet1[1] + vet2 [1];
   resp[2] = vet1[2] + vet2 [2];

}

void prodVC(float vet1[3], float val, float *resp){
   resp[0] = vet1[0] * val;
   resp[1] = vet1[1] * val;
   resp[2] = vet1[2] * val;

}

float norma(float vet[3]){
   return sqrt(vet[0] * vet[0] + vet[1] * vet[1] + vet[2] * vet[2]);
}

void vetNormal(float vet[3], float *normal){
   float val = 1/norma(vet);

   prodVC(vet, val, normal);
}

void printaVetor(float vet[3]){
   printf("\n%f %f %f\n", vet[0], vet[1], vet[2]);
}


//////////////////CALCULA O A INTERSẼÇÃO E O PONTO DE INTERSEÇÃO ////////////
float intersecao_esfera(float v[3], float w[3], float r, float *Pint){
   float a, b, c, delta, x1, x2, t;

   a = prod(v, v);
   b = 2 * prod(v, w);
   c = prod(w, w) - r*r;
   
   delta = (b*b)-(4*a*c);
   
   if(delta < 0) return false;
   else{
      if(delta == 0) t = -b / (2*a);
      else{
         x1 = (-b+sqrt(delta))/(2*a);
         x2 = (-b-sqrt(delta))/(2*a);
         t = (x1 < x2) ? x1 : x2;
      }

      prodVC(v, t, Pint);

      return true;
   }
}


//////////////////CALCULA O A INTERSẼÇÃO E O PONTO DE INTERSEÇÃO ////////////
float intersecao_cone(float D[3], float v[3], float A[3], float cosAlfa, float lado, float *Pint){
   float a, b, c, delta, x1, x2, t;
   float tamanhoPint[3];
   float tamanho;
   a = pow(prod(D, v), 2) - prod(D, D) * pow(cosAlfa, 2);
   b = 2 * prod(A, D) * pow(cosAlfa, 2) - 2 * prod(D, A) * prod(v, v);
   c = pow(prod(A, v), 2) - prod(A, A) * pow(cosAlfa, 2);
   
   delta = pow(b, 2) - (4 * a * c);
   
   if(delta < 0) return false;
   else{
      return true;
      if(delta == 0) t = -b / (2*a);
      else{
         x1 = (-b+sqrt(delta))/(2*a);
         x2 = (-b-sqrt(delta))/(2*a);
         t = (x1 < x2) ? x1 : x2;
      }

      prodVC(D, t, Pint);
      sub(A, Pint, tamanhoPint);
      tamanho = norma(tamanhoPint);
//      if (tamanho > 0 and tamanho <= lado) return true;
 //     return false;
   }
}

/////////////////CALCULA A COR DOS PARANAUE//////////////////////////
void cor(int obj, float centro[3]){
   float aux[3];
   float observador[3] = {0, 0, 0};
   sub(observador, Pint, ve);
   sub(Pint, centro, n);
   sub(Luz, Pint, lu);

   vetNormal(ve, ve);
   vetNormal(n, n);
   vetNormal(lu, lu);
   
   prodLuN = prod(lu, n);
   if (prodLuN < 0) prodLuN = 0;

   prodVC(n, 2*(prod(lu, n)), aux);
   sub(aux, lu, r);

   prodVeR = prod(ve, r);

   if (obj == 1) {
      //AMBIENTE
      arroba(Iamb, Kambb, Iam);
      
      //DIFUSA
      arroba(If, Kdifb, Idif);

      //ESPECULAR
      arroba(If, Kespb, Iesp);
   
   } else if(obj == 2) {
      //AMBIENTE
      arroba(Iamb, Kamb, Iam);

      //DIFUSA
      arroba(If, Kdif, Idif);

      //ESPECULAR
      arroba(If, Kesp, Iesp);

   } else if(obj == 3) {
      //AMBIENTE
      arroba(Iamb, Kambo, Iam);

      //DIFUSA
      arroba(If, Kdifo, Idif);

      //ESPECULAR
      arroba(If, Kespo, Iesp);

   }
   prodVC(Idif, prodLuN, Idif);
   prodVC(Iesp, prodVeR, Iesp);



   sum(Iam, Idif, Ipix);
   sum(Ipix, Iesp, Ipix);

}


///////////////////FUNÇÃO QUE PINTA A TELA
void drawScene(void) {
   float l, c, x, y;
   float d = -90;
   float v[3];
   float observador[3] = {0,0,0};

   //Informações dos Objetos 
   float r1 = 30;
   float w1[3];
   float centro1[3] = {0, 20, -51};
   sub(observador, centro1, w1);

   float r2 = 40;
   float w2[3];
   float centro2[3] = {0, -20, -51};
   sub(observador, centro2, w2);

   float rb1 = 2;
   float wb1[3];
   float centrob1[3] = {0, -10, -20};
   sub(observador, centrob1, wb1);

   float rb2 = 1.9;
   float wb2[3];
   float centrob2[3] = {0, -20, -20};
   sub(observador, centrob2, wb2);

   float rb3 = 1.7;
   float wb3[3];
   float centrob3[3] = {0, -30, -20};
   sub(observador, centrob3, wb3);

   float ro1 = 2;
   float wo1[3];
   float centroo1[3] = {5, 10, -25};
   sub(observador, centroo1, wo1);

   float ro2 = 2;
   float wo2[3];
   float centroo2[3] = {-5, 10, -25};
   sub(observador, centroo2, wo2);

   //Conezinhoo Funciona nunca te pedi nada
   float rc = 5;
   float Vc[3];
   float vc[3];
   float ac[3] = {0, 50, -5};
   float centroc[3] = {0, 0, -5};
   sub(centroc, ac, Vc);
   float hc = norma(Vc);
   float teta = atan(rc/hc);
   float cosTeta = cos(teta);
   vetNormal(Vc, vc);
   float lado = sqrt(pow(hc, 2) + pow(rc, 2));
   
   glClear(GL_COLOR_BUFFER_BIT);
   
   //Laço que pinta
   glBegin(GL_POINTS);
      for(l = 0; l < 500; l++){
         y = bottom + l;
         for(c = 0; c < 500; c++){
            x = left + c;
            float pixel[3] = {x, y, d};

            sub(pixel, observador, v);
            
            if (intersecao_esfera(v, wb1, rb1, Pint)){        //Teste do Primeiro Botão
               cor(1, centrob1);
               glColor3f(Ipix[0], Ipix[1], Ipix[2]);

            } else if(intersecao_esfera(v, wb2, rb2, Pint)){  //Teste do Segundo Botão
               cor(1, centrob2);
               glColor3f(Ipix[0], Ipix[1], Ipix[2]);
            
            } else if(intersecao_esfera(v, wb3, rb3, Pint)) { //Teste do Terceiro Botão
               cor(1, centrob3);
               glColor3f(Ipix[0], Ipix[1], Ipix[2]);

            } else if (intersecao_esfera(v, wo1, ro1, Pint)){  //Teste do Primeiro Olho
               cor(3, centroo1);
               glColor3f(Ipix[0], Ipix[1], Ipix[2]);

            } else if(intersecao_esfera(v, wo2, ro2, Pint)){  //Teste do Segundo Olho
               cor(3, centroo2);
               glColor3f(Ipix[0], Ipix[1], Ipix[2]);
              
            } else if (intersecao_esfera(v, w1, r1, Pint)) {   //Teste da Cabeça / Bucho
               cor(2, centro1);
               glColor3f(Ipix[0], Ipix[1], Ipix[2]);
            
            } else if (intersecao_esfera(v, w2, r2, Pint)){   //Teste do Bucho / Cabeça
               cor(2, centro2);
               glColor3f(Ipix[0], Ipix[1], Ipix[2]);

            } /*else if (intersecao_cone(v, vc, ac, cosTeta, lado, Pint)){
               glColor3f(0.5, 0.5, 0.5);


            } */else{               //Cor de BackGround
               glColor3f(0.8, 0.9, 0.9);

            }

            glVertex2f(c, l);     //Pinta o Pixel
         }
      }

   glEnd();

   glFlush();
}

// INão mudei nada aqui.
void setup(void) 
{
   glClearColor(1.0, 1.0, 1.0, 0.0); 
}

void resize(int w, int h)
{
   glViewport(0, 0, w, h); 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 500, 0, 500, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Adicionei as coordenadas ordo aqui.
int main(int argc, char **argv) 
{

   glutInit(&argc, argv);

   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glOrtho(0, 500, 0, 500, 1, 1);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("SnowMan");
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);  


   glewExperimental = GL_TRUE;
   glewInit();

   setup(); 
   
   glutMainLoop(); 
}
