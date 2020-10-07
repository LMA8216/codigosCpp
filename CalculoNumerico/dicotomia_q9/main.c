#include <stdio.h>
#include <math.h>

float funcao( float x){

    float y;
    /*letra a*/
    y = pow(x,3) - pow(x,2)-1;

    /*letra b*/
    //y = exp(-x)*((x-1.0)/2.0);
    return y;
}

float dicotomia(float xa, float xb, float precisao){

    float xc, anterior;

    anterior = xb;
    xc = xa;
          // fica no loop ate a condição for falsa
    while(fabs(xc-anterior) > precisao){
        anterior = xc;
        xc = (xa+xb)/2.0;
        /*se a imagem de xc for negativa , entao o extremo esquerdo
         limitado por a(termo de imagem negativa) recebe xc*/
        if(funcao(xc) < 0){
            xa = xc;
        }
        /*se a imagem de xc for positiva , entao o extremo direito
         limitado por b(termo de imagem positivo) recebe xc*/
        else{
            xb = xc;
        }
    }
    return xc;
}

int main(int argc, char* argv[]){

    float raiz;

    raiz = dicotomia(0, 2, 0.0001);
    printf("raiz = %g\n", raiz);

    getchar();
    return 0;
}

