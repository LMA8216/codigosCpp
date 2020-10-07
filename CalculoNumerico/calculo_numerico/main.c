#include <stdio.h>
#include <math.h>

float funcao( float x){

    float y;

    //y = exp(x) + (x/2.0);
    //y = pow(x,3) - pow(x,2)-1;
    y = exp(-x)*((x-1)/2);
    return y;
}

float dicotomia(float xa, float xb, float precisao){

    float xc, anterior;

    anterior = xb;
    xc = xa;

    while(fabs(xc-anterior) > precisao){
        anterior = xc;
        xc = (xa+xb)/2.0;
        if(funcao(xa)*funcao(xb) < 0.0){
            xb = xc;
        }
        else
        if( funcao(xb)*funcao(xc) < 0.0){
            xa = xc;
        }
    }

    return xc;
}

int main(int argc, char* argv[]){

    float raiz;

    raiz = dicotomia(0.9, 1.1, 0.0001);
    printf("raiz = %g\n", raiz);

    getchar();
    return 0;
}

