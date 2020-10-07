#include <stdio.h>
#include <math.h>

int N;
float b[30];
float x[30];
float a[30][30];

void show(){

   int i,j;

  printf("Ordem do sistema: n = %d\n\n\n",N);
  for(i=0;i<N;i++)
   {
      for(j=0;j<N;j++)
   printf("  %10.6f",a[i][j]);
     printf("  %10.6f\n",b[i]);
   }
  printf("\n\n\n<ENTER> ");
  getch();
}

void LeMatriz(){
  int i,j;

        printf("Ordem do sistema: n= ");
        scanf("%d",&N);
        printf("\n\nDigite os valores separados por espacos.\n");
        for(i=0;i<N;i++){

            printf("linha %3d: \n",i+1);
            for(j=0;j<N; j++){
            scanf("%f",&(a[i][j]));
            }
            scanf("%f",&(b[i]));

        }
    show();
}

float det(float a, float b, float c, float d){
    return ((a*d)-(b*c));
}

void Triang(){

  int i,j,k;

    for(k=0;k<(N-1);k++){
        for(i=k+1; i<N; i++){
            //laço para alterar as linhas abaixo do pivo na matriz A
            for(j=k+1;j<N; j++){
                a[i][j]=det(a[k][k],a[i][k],a[k][j],a[i][j]);
                show();
            }
           //zera os elementos abaixo do pivo e altera o elemento na linha da matriz B
           b[i]=det(a[k][k],a[i][k],b[k],b[i]);
           a[i][k] = 0;
           show();
        }
    }
}

void solucao(){

  int k,j;
  float s;

   //resolve o unico elemnto nao zero da ultima linha da matriz A
   x[N-1]=b[N-1]/a[N-1][N-1];
   //resolve os outros valores da matriz soluçao subindo as linhas na matriz A
   for(k=N-2; k>=0;k--)
   {
       s=0;
       // a variavel S vai guardar o valor da operação feita com os valores das variaveis ja descobertas
       for(j=k+1; j<N; j++){
         s+=a[k][j]*x[j];
       }
       x[k]=(b[k]-s)/a[k][k];
   }
}

void imprime(){
 int i;
    printf("\n\nSolucao do sistema linear\n");
    for(i=0;i<N;i++)
        printf("x(%3d)=%10.6g\n",i,x[i]);
    printf("\n\nproblema encerrado.\n");
}

int main()
{
    LeMatriz();
    Triang();
    solucao();
    imprime();
    getch();
}
