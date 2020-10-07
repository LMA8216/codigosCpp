#include <stdio.h>
#include <math.h>
// define o numero de termos M
#define M 2

// N numero de amostras
int N;
float X[30],Y[30],y[30];
float A[30][30],B[30];

//funcoes que compoem a função aproximadora
// y= X[1]*x + X[2]
// y= a*x + b
//
float g0(/*float x*/){
    return 1;
}

float g1(float x){
    return x;
}

float g2(float x){
    return log(x);
}
float funcaoOriginal(x0,x1,nb){
    return (pow(M_E,x0))*(pow(M_E,(nb*x1)));
}

void LeDados(){
  int i;
    printf("Numeros de pontos: n= ");
    scanf("%d",&N);
    printf("\n\nDigite X e Y separados por espacos.\n\n");
    for(i=0;i<N;i++){
        printf("[%3d] ",i+1);
        scanf("%f",&(X[i]));
        scanf("%f",&(y[i]));
        Y[i] = g2(y[i]);
    }
}

float funcao(int i, int k){
    /*O numero de termos da funcao aproximadora afeta
      as proximas linhas(switch) */

    switch(i){
        case 0 : return(g0(X[k]));
        case 1 : return(g1(X[k]));
    }
  return 0;
}

void SistemaNormal(){
  int i,j,k;
  float r,s;

  //zera todo os valores (limpa a matriz A e B);
  for(i=0;i<M;i++){
    for(j=0;j<M;j++)
    A[i][j]=0;
    B[i]=0;
  }
  for(k=0;k<N;k++){
    for(i=0;i<M;i++){
      //funcao 0 faz ΣXk
      r = funcao(i,k);
      B[i]+= r*Y[k];
      for(j=0;j<M;j++){
        s = funcao(j,k);
        A[i][j] += r*s;
      }
    }
  }
}

float det(float a, float b, float c, float d){
    return (a*d)-(b*c);
}

void show(){

   int i,j;

  printf("Ordem do sistema: n = %d\n\n\n",N);
  for(i=0;i<M;i++)
   {
      for(j=0;j<M;j++){
      printf("  %12.6f",A[i][j]);
      }
     printf("  %12.6f\n",B[i]);
   }
  printf("\n\n\n<ENTER> ");
  getch();
}

void TriGauss(){
  int i,j,k;
    // a variavel K restringe a matriz A para uma 2x2, por isso ela vai ate M-1
    for(k=0;k<=(M-1);k++){
        for(i=k+1;i<M;i++){
            for(j=k+1;j<M;j++){
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
   X[M-1]=B[M-1]/A[M-1][M-1];
   for(k=M-2;k>=0;k--){
      s=0;
      for(j=k+1;j<M;j++)
        s+=A[k][j]*X[j];
      X[k]=(B[k]-s)/A[k][k];
   }
}

void Imprime(){
  int i;

  printf("\n\nSolucao do sistema linear\n");
  for(i=0;i<M;i++){
    printf("a(%3d)=%10.6g\n",i,X[i]);
  }
  printf("\n\n\nProblema encerrado.\n");
}

void FuncaoFinal(){
  float n;
  float r;
  // mostra a funcao original completa
  printf("\ny = %10.6g*e^(%10.6g*T)\n",pow(M_E,X[0]),X[1]);
  printf("\nNumero a interpolar : ");
  scanf("%f",&n);
  r = pow(M_E,X[0])*pow(M_E,(n*X[1]));
  printf("\nresultado: %f\n",r);
}

void main()
{
    LeDados();
    SistemaNormal();
    show();
    TriGauss();
    show();
    SolGauss();
    Imprime();
    for(;;){
    FuncaoFinal();
    }
}
