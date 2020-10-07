#include <stdio.h>

void squeeze(char s[], char c[]);

int main(){
    char nome[] = "macaco";
    char mesa[] = "macaquinha";

    squeeze(nome, mesa);

    printf("%s", nome);
    return 0;
}

void squeeze(char s[], char c[]){
    int i,j;

    for( i = 0; s[i] != '\0'; i++)
    {
        for(j = 0; c[j] != '\0'; j++)
        {
            if(s[i] == c[j])
            {
                s[i] = ' ';
                break; 
            }
        }
    }
}


