#include <stdio.h>
//#include <sys/wait.h>
int main(){
    printf("Indiqui el primer nombre\n->");
    char caracter[100];
    scanf("%s",caracter);
    printf("Indiqui el segon nombre\n->");
    char caracter2[100];
    scanf("%s",caracter2);
    int n=0;
    int comoEntero = caracter[n] - '0';   
    int resp=0;
    int fi=1;
    if(comoEntero==-38){
        printf("Introduzca un carácter porfavor\n");
    }
    else if(comoEntero==-3){
        ++n;  
        comoEntero = caracter[n] - '0';  
        while((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48){
            ++n;
            if((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48)  comoEntero = caracter[n] - '0';
            if((comoEntero>=0 && comoEntero<=9)||comoEntero==-48){
                
                fi=0;
            }
            else fi=1;
              
        }
    }
    else{
        while((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48){
            ++n;
            if((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48)  comoEntero = caracter[n] - '0';
            if((comoEntero>=0 && comoEntero<=9)||comoEntero==-48){
                
                fi=0;
            }
            else fi=1;              
        }
    }
    if(fi==1){
        printf("El primer nombre no és enter! \n");
    }
    else{
        printf("El primer nombre és enter!\n");
    }

    n=0;
    comoEntero = caracter2[n] - '0';   
    resp=0;
    fi=1;
    if(comoEntero==-38){
        printf("Introduzca un carácter porfavor\n");
    }
    else if(comoEntero==-3){
        ++n;  
        comoEntero = caracter2[n] - '0';  
        while((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48){
            ++n;
            if((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48)  comoEntero = caracter2[n] - '0';
            if((comoEntero>=0 && comoEntero<=9)||comoEntero==-48){
                
                fi=0;
            }
            else fi=1;
              
        }
    }
    else{
        while((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48){
            ++n;
            if((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48)  comoEntero = caracter2[n] - '0';
            if((comoEntero>=0 && comoEntero<=9)||comoEntero==-48){
                
                fi=0;
            }
            else fi=1;              
        }
    }
    if(fi==1){
        printf("El segon nombre no és enter! \n");
    }
    else{
        printf("El segon nombre és enter!\n");
    }










}
