#include <stdio.h>
#include <math.h>

int n;

float funcao (int x){

//letra a

float y = 1/(16+x^2);

return y;

}

void ler_dados(int x){

printf("defina o numero de sub-intervalo : ");
scanf("%i",&n);
printf("Agora defina o intervalo de integração\n");
printf("a: ");
scanf("%i",&a);
putchar("\n");
printf("b: ");
scanf("%i",&b);
putchar("\n");
}

int main(int argc, char* argv[]){

    ler_dados();

}


