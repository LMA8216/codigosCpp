#include <stdio.h>
#include <ctype.h>
#include <math.h>

int htoi(char str[]);
int format_hexa(char s,int n);
int format_Hexa(char s, int n);
int format_num(char s, int n);

int main()
{   
    int n = htoi("2f");
    printf("%d",n);
    return 0;
}

int htoi(char str[])
{   
    int valueInt = 0;
    int i;
    for(i = 0; str[i] >= '0' && str[i] <= '9' || 
               str[i] >= 'a' && str[i] <= 'f' ||
               str[i] >= 'A' && str[i] <= 'B'  ; i++ )
    {
        if(str[i] >= '0' && str[i] <= '9')
            valueInt += format_num(str[i],i);
        else if(str[i] >= 'a' && str[i] <= 'f')
            valueInt += format_hexa(str[i],i);
        else
            valueInt += format_Hexa(str[i],i);
    }

    return valueInt;
}

int format_hexa(char s,int n){
    int hexa, c = 1 ;
    hexa = s - 'a' + 10;
    c = pow(16,n);
    
    hexa *= c;

    return hexa;
}

int format_Hexa(char s,int n){
    int hexa, c = 1 ;
    hexa = s - 'A' + 10;
    c = pow(16,n);
    
    hexa *= c;

    return hexa;
}

int format_num(char s,int n){
    int num, c = 1 ;
    num = s - '0';
    c = pow(16,n);
    
    num *= c;

    return num;
}