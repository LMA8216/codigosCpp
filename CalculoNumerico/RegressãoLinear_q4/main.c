#include <stdio.h>
#include <math.h>

int N;
float X[30],Y[30];
float A[2][3];

void LeDados(){
    int i;

    printf("Numero de pontos: n= ");
    scanf("%d",&N);
    printf("\n\nDigite X e Y separados por espacos.\n\n");
    for(i=0;i<N;i++){
        printf("[%3d] ",i+1);
        scanf("%f",&(X[i]));
        scanf("%f",&(Y[i]));
    }
}

void MontaSistema(){

   int i;
   float s;

   // zera toda a matriz
   A[0][1]=0; A[1][1]=0;
   A[0][2]=0; A[1][2]=0;
   for(i=0; i<N; i++){
      // termo A12 da matriz é igual ΣXk
      A[0][1] += X[i];
      // termo A22 é igual Σ(Xk^2)
      A[1][1] += X[i]*X[i];
      //termo A13 da matriz B é igual a ΣYk
      A[0][2] += Y[i];
      //termo A23 da matriz B é igual a Σ(Yk*Xk)
      A[1][2] += X[i]*Y[i];
   }
   // termo A11 é quantidade de pontos
   A[0][0] = N;
   // termo A21 é igual A12
   A[1][0] = A[0][1];
}

float det(float a, float b, float c, float d){
    return (a*d)-(c*b);
}

int main()
{
    float a,b;

    LeDados();
    MontaSistema();
            // (b1*A22)-(A12*B2)/(A11*A22)-(A12*A21)
    a = det(A[0][2],A[0][1],A[1][2],A[1][1])
       /det(A[0][0],A[0][1],A[1][0],A[1][1]);
            // (A11*b2)-(b1*A21)/(A11*A22)-(A12*A21)
    b = det(A[0][0],A[0][2],A[1][0],A[1][2])
       /det(A[0][0],A[0][1],A[1][0],A[1][1]);
    printf("g(x)=%f10.6 + %f10.6 x\n<ENTER> ",a,b);
    getch();

    return 0;
}
