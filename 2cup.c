#define TEAMNAME "JoaquimHervas"
#define ENIGMA1 "FFEE"
//KEY=7a65f :)))))))))))))))))))))))))))))))))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include "dummy2.h"


int comprova_int(char caracter2[]){
    int n=0;
    int comoEntero = caracter2[n] - '0';   
    int resp=0;
    int fi=1;
    int pid;
    int final;

    while((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48){
        ++n;
        if((comoEntero>=0 && comoEntero<=9) && comoEntero!=-48)  comoEntero = caracter2[n] - '0';
        if((comoEntero>=0 && comoEntero<=9)||comoEntero==-48){
            
            fi=0;
        }
        else fi=1;              
    }
    
    if(fi==1){
        printf("(-1)El segon nombre no és enter mes gran que 0! \n");
        return 0;
    }
    else{
        //inútil en verdad , se puede eliminar
        if(caracter2[0]==48){
            fi=0;
            n=0;
            while(!caracter2[n]==0){
                ++n;
                if(caracter2[n]!=48 && caracter2[n]!=0 ){
                    fi=1;
                    break;
                }
            }
            if(fi==1){
                printf("Nombre introduit correctament! ✓\n");
                return 1;
            } 
            else {
                printf("(-1)El segon nombre no és enter mes gran que 0! \n");
                return 0;
            }

        }
        else {
            printf("Nombre introduit correctament! ✓\n");
            return 1;
        }

        //exit(1);
    }


}

int main(){
    
        //TT
        printf("Indiqui el nombre de replicants\n->");
        char caracter2[100];
        scanf("%s",caracter2);
        int r=comprova_int(caracter2);
        if(r==1){
            
            
            //printf("%d\n",ret);
        }
        else exit(0);
        char *ptr;
        int Nombre_Replicants = strtol(caracter2, &ptr, 10);
        printf("Indiqui la memoria del replicant en Bytes\n->");
        char caracter[100];
        scanf("%s",caracter);
        r=comprova_int(caracter);
        if(r==1){
            
            //printf("%d\n",ret);
        }
        else exit(0);

        char *ptr1;
        int Memoria = strtol(caracter, &ptr1, 10);
        int entrada=dummy_open( );
        int a=0;
        int fi=0;
        int blacklist=getpid();
        int wiwa=0;

        while(a<Nombre_Replicants && fi==0){
            
            int pid=fork();
            if(pid==0) fi=1;
            else {
            
                int stat;
                wait(&stat);
                if (WIFEXITED(stat)){
                    //printf("%d",WEXITSTATUS(stat));
                    if(WEXITSTATUS(stat)!=-1){
                        
                        wiwa=wiwa+WEXITSTATUS(stat);
                        printf("%d\n",WEXITSTATUS(stat));
                    }
                    else{
                        printf("El replicant %d no ha tingut exit en la seva missió\n", pid);
                        exit(1); //acabem de fer replicants ja que un ha fallat
                    }
                   
                }                 
            }
            ++a;
        }
        if (blacklist!=getpid()){


            char buffer[Memoria];
            dummy_init(buffer,Memoria );
            int ere=dummy_comp(buffer, read(entrada,&buffer,Memoria));
            //printf("elcomp: %d\n",ere);
            dummy_exit();
        }
        printf("la wiwa: %d\n",wiwa);
        if(dummy_test(wiwa, ENIGMA1, TEAMNAME)==1) printf("Ha acabat be");
        else{
            printf("ha acabat malament\n");
        }

    
}
