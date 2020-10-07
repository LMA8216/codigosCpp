#include <stdio.h>
#include <math.h>

int n;
float a,b,h,I;
float resultado = 0;

float amplitude_do_intervalo(){

 h=1;
 return h;
}

void tabela_de_valores(){

    float x[n+1];
    float y[n+1];
    float Y[n+1];

    printf("Digite os valores de y: ");
    for(int i=0; i<=n; i++){
        scanf("%f",&y[i]);
    }

    for(int j=0; j<=n; j++){
        if(j==0 || j==n){
            Y[j] = y[j];
        }
        else{
            Y[j] = 2*y[j];
        }
        printf("y%i = %f\n",j,y[j]);

    }

    // Faz somatorio de Y
    for(int k=0;k<=n; k++){
        resultado = resultado + Y[k];
    }

}

void integracao(){
    I = ((3*h)/8)*resultado;
    printf("\n\no rasultado da integracao : %f\n",I);
}


void ler_dados(){

printf("defina o numero de sub-intervalo : ");
scanf("%i",&n);
printf("Agora defina o intervalo de integracao\n");
printf("a: ");
scanf("%f",&a);
printf("b: ");
scanf("%f",&b);
}

int main(int argc, char* argv[]){

    ler_dados();
    amplitude_do_intervalo();
    tabela_de_valores();
    integracao();

}
