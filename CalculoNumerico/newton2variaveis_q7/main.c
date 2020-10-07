#include <stdio.h>
#include <math.h>

// derivadas parciais
float Fx(float x, float y){
    return (2*x-5);
}
float Fy(float x, float y){
    return -1;
}
float Gx(float x, float y){
    return ((3/2)*cos(x/2)) ;
}
float Gy(float x, float y){
    return -1;
}

//Funçoes principais
float F(float x, float y){
    return (pow(x,2)-5*x+4-y);
}
float G(float x, float y){
    return (3*sin(x/2)-y) ;
}

//determinante de uma matriz 2x2
float det(float a, float b, float c, float d){
    return ((a*d)-(b*c));
}

void NewtonRaphson(float x0, float y0, float* xb, float* yb, float precisao)
{
    int fim;
    float x1,y1,nx,ny,den;

    do{

      den = det( Fx(x0,y0),Fy(x0,y0),Gx(x0,y0),Gy(x0,y0));
      nx =  det( F(x0,y0), Fy(x0,y0),G(x0,y0), Gy(x0,y0));
      ny =  det( Fx(x0,y0), F(x0,y0),Gx(x0,y0), G(x0,y0));
      x1 = x0 - (nx/den);
      y1 = y0 - (ny/den);
      //condiçao logica, o Do vai executar até que seja falsa
      fim = (fabs(x1-x0) < precisao) && (fabs(y1-y0) < precisao);
      x0  = x1;
      y0 = y1;
    }
    while(!fim);
    *xb = x1;
    *yb = y1;
}

int main(int argc, char* argv[]){

    float x,y;

    NewtonRaphson(6,4,&x,&y,0.0001);
    printf("resposta = (%g,%g)\n",x,y);

    getchar();
    return 0;

}
