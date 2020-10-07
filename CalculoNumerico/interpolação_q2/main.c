#include <stdio.h>
#include <math.h>
//N estebelece quantos pontos tem a tabela
//M estabelece qauntos termos tem a funcao aproximadora

int N,M;
float X[30],Y[30];
float A[30][30], B[30];

void LeDados(){
  int i;
    printf("Numeros de pontos: n= ");
    scanf("%d",&N);
    printf("\n\nDigite X e Y separados por espacos.\n\n");
    for(i=0;i<N;i++){
        printf("[%3d] ",i+1);
        scanf("%f",&(X[i]));
        scanf("%f",&(Y[i]));
    }
    M = N-1;
}

//calcula a potencia n de x
float pot(float x,int n){
  if(n){
    /*se n for diferente de zero , entao multiplica x por si mesmo
    quantas vezes n for diferente de zero na recursividade*/
    return x*pot(x,n-1);
  }
  else{
    return 1.0;
  }
}

void SistemaLinear(){
   int i,j;

   for(i=0;i<=M;i++){
      for(j=0;j<=M;j++){
        A[i][j] = pot(X[i],j);
      }
     B[i] = Y[i];
   }
}

float det(float a,float b, float c, float d){
    return (a*d)-(b*c);
}

void TriGauss(){
  int i,j,k;
    // a variavel K restringe a matriz A para uma 2x2, por isso ela vai ate M-1
    for(k=0;k<=(M-1);k++){
        for(i=k+1;i<=M;i++){
            for(j=k+1;j<=M;j++){
                A[i][j]=det(A[k][k],A[i][k],A[k][j],A[i][j]);
            }
            B[i]=det(A[k][k],A[i][k],B[k],B[i]);
            A[i][k]=0;
        }
    }
}

void SolGauss(){
  int k,j;
  float s;
   //matriz triangular superior, comeca encontrando o valor da variavel na ultima linha
   X[M]=B[M]/A[M][M];
   for(k=M-1;k>=0;k--){
      s=0;
      for(j=k+1;j<=M;j++)
        s+=A[k][j]*X[j];
      X[k]=(B[k]-s)/A[k][k];
   }
}

void Resultado(){
  int i;
    //monta a função polinomial começando pela potencia 1
     printf("\n\nPolinomio interpolador: \n");
     printf("p(x)=");
     for(i=0;i<=M;i++){
        printf("%g",X[i]);
        // Segundo coeficiente, coloca somente um x(potencia 2)
        if(i) printf("x");
        // Demais potencia coloca ^i potencia respectiva na sequencia
        // e acrescenta o "+"
        if(i>1) printf("^%d",i);
        if(i<M) printf(" + ");
     }
}

void interpolar(){
   int i;
   float x,y;

   printf("\n\n\nValor a ser interpolado: ");
   scanf("%f",&x);
   for(i=0,y=0;i<=M;i++)
     y += X[i]*pot(x,i);
   printf("\np(%g) = %g\n\n",x,y);
}

void main()
{
    LeDados();
    SistemaLinear();
    TriGauss();
    SolGauss();
    Resultado();
    for(;;) interpolar();
}
