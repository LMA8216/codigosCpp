#include <stdio.h>
#include <math.h>

int n;
float a,b,h,I;
float resultado = 0;

float funcao (float k){

float z;

    z = exp(2*k);

return z;
}

float amplitude_do_intervalo(){

 return (h=(b-a)/n);
}

void tabela_de_valores(){

    float x[n+1];
    float y[n+1];
    float Y[n+1];

    x[0] = a;
    for(int i=1; i<=n; i++){
        x[i] = x[i-1]+h ;
    }
    for(int j=0; j<=n; j++){
        y[j] = funcao(x[j]);
        if(j==0 || j==n){
            Y[j] = y[j];
        }
        else if(!(j%2))
        {
            Y[j] = 2*y[j];
        }
        else{
            Y[j] = 4*y[j];
        }
        printf("x%i = %f  y%i = %f\n",j,x[j],j,y[j]);

    }

    // Faz somatorio de Y
    for(int k=0;k<=n; k++){
        resultado = resultado + Y[k];
    }

}

void integracao(){
    I = (h/3)*resultado;
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
