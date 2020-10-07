#include <stdio.h>
#include <math.h>

int n;
float a,b,h,I;
float resultado = 0;

float funcao (float k){

float z;

//letra a

//z = 1/(16+(k*k));


//letra b

//z = 1/k;


//letra c

//z = k*(pow(4-(k*k),0.5));


//letra d

//z = sin(k);


//letra e

//z = (k*k*k);


//letra f

//z = pow(1+(k*k),0.5);


//letra g

//z = pow(1+(k*k*k),0.5);


//letra h

//z = log((1+(k*k)));


//letra i

//z = 1/(k+1);


//letra j

z = log((2+(pow(k,0.5))));


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
        else{
            Y[j] = 2*y[j];
        }
        printf("x%i = %f  y%i = %f\n",j,x[j],j,y[j]);

    }

    // Faz somatorio de Y
    for(int k=0;k<=n; k++){
        resultado = resultado + Y[k];
    }

}

void integracao(){
    I = (h/2)*resultado;
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
