#include <stdio.h>
#include <math.h>

float f (float x){

    float y;

    /* equação y = x^2 - 7 */
    y = pow(x,2)-7;
    return y;
}

float derivf (float x){

    float y;
    y = 2*x ;

    return y;
}

float NewtonRaphson(float x0, float precisao){
    //inicia a variavel seguinte(x1) e o anterior
   float x1, anterior;

    //incrementa o primeiro valor de anterior para ser verdade a condição while e iniciar a rotina
   anterior = x0 + 2*precisao;

   while(fabs(x0 - anterior) > precisao){
      anterior = x0;
      x1 = x0 - (f(x0)/derivf(x0));
      x0 = x1;
   }
   return x1;
}

int main(int argc, char* argv[]){
    float raiz;

    raiz = NewtonRaphson(2.5, 0.0001);
    printf("raiz = %g\n", raiz);

    getchar;
    return 0;
}
