#include <stdio.h>
#include <math.h>

int N;
float X[30],Y[30],xx,ff;

void LerDados(){
  int i;
    printf("Numeros de pontos: n= ");
    scanf("%d",&N);
    printf("\n\nDigite X e Y separados por espacos.\n\n");
    for(i=0;i<N;i++){
        printf("[%3d] ",i+1);
        scanf("%f",&(X[i]));
        scanf("%f",&(Y[i]));
    }
}

float Lagrange(float xx){
  float p,num,den;
  int i,j;

  p=0;
  // formula Pn(x)=Σ(i=0 até n)Yi*Π(j=0 até n, sempre diferente de i)((xx-xj)/(xi-xj))
  for(i=0;i<N;i++){
    num = 1;
    den = 1;
    for(j=0;j<N;j++){
        if(j!=i){
            num *= xx-X[j];
            den *= X[i]-X[j];
        }
    }
    p+= num*Y[i]/den;
  }
  return p;
}

void main()
{
    LerDados();
    for(;;){
       printf("X = ");
       scanf("%f",&xx);
       ff = Lagrange(xx);
       printf("\nValor interpolado pelo polinomio de lagrange:\n");
       printf("p(%g) = %g\n",xx,ff);
    }
    return 0;
}
