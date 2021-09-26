#include <stdio.h>
int main(){
    int fi=0;
    while(fi==0){
        printf("Indiqui el primer nombre\n->");
        char caracter[100];
        scanf("%s",caracter);
        printf("Indiqui el segon nombre\n->");
        char caracter2[100];
        scanf("%s",caracter2);
        int a=0;
        int n=0;
        int comoEntero = caracter[n] - '0';   
        int resp=0;
        if(comoEntero==-38){
            printf("Introduzca un carácter porfavor\n");
        }
        else{
            while(a==0 ){
                //printf("%d\n",n);
                if((!(comoEntero>=0 && comoEntero<=9))){
                    if(comoEntero==-48){
                        a=1;
                        resp=1;   
                    }
                    else if(comoEntero==-3 && a==0){
                    }
                    else{
                        a=1;
                    } 
                }
                ++n;
                comoEntero = caracter[n] - '0';

            }
            
        }
        int a2=0;
        int n2=0;
        int comoEntero2 = caracter2[n2] - '0';   
        int resp2=0;
        if(comoEntero2==-38){
            printf("Introduzca un carácter porfavor\n");
        }
        else{
            while(a2==0 ){
                if((!(comoEntero2>=0 && comoEntero2<=9))){
                    if(comoEntero2==-48){
                        a2=1;
                        resp2=1;   
                    }
                    else if(comoEntero2==-3 && a2==0){
                    }
                    else{
                        a2=1;
                    } 
                }
                ++n2;
                comoEntero2 = caracter2[n2] - '0';

            }
            
        }



        if(resp==0){
            printf("El primer nombre no és enter\n");

        }
        if(resp==1){
            printf("El primer nombre és enter\n");

        }
        if(resp2==0){
            printf("El segón nombre no és enter\n");

        }
        if(resp2==1){
            printf("El segón nombre és enter\n");

        }
        int correcte=0;
        while(correcte==0){
            printf("¿Vol continuar inserint numeros?\n");
            printf("Escrigui 1 per continuar\nEscrigui 2 per acabar \n\n->");
            int aa;
            scanf("%d",&a);
            if(a==1){
                correcte=1;
            }
            else if(a==2){
                fi=1;
                correcte=1;
            }
            else {
            }
        }
    }
}
