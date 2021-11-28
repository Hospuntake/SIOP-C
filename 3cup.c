
//B_KEY=7a65f :)))))))))))))))))))))))))))))))))
//Comentari: Tarda una mica avegades , pero sempre acaba compilant .
#define TEAMNAME "JoaquimHervas" // insert between "" your team name
#define ENIGMA2 "SIGSTOP" // insert between "" solution of enigna 2
#define BRONCEKEY "7a65f" // insert BRONCEKEY between ""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include "dummy3.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>


void sigusr1(){
    signal(SIGUSR1, sigusr1);
    printf("CHILD: I have received a SIGHUP\n");

}


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
        printf("(-1)El nombre no és enter mes gran que 0! \n");
        return 0;
    }
    else{
        printf("Nombre introduit correctament! ✓\n");
        return 1;
    }


}

int main(){
    

    //TT
    printf("Indiqui el nombre de replicants\n->");
    char caracter2[100];
    scanf("%s",caracter2);
    int r=comprova_int(caracter2);
    if(r==1){
        
    }
    else exit(0);
    char *ptr;
    int Nombre_Replicants = strtol(caracter2, &ptr, 10);

    printf("Indiqui la memoria del replicant en Bytes\n->");
    char caracter[100];
    scanf("%s",caracter);
    r=comprova_int(caracter);
    if(r==1){

    }
    else exit(0);

    char *ptr1;
    int Memoria = strtol(caracter, &ptr1, 10);

    int fd[2];//Preparem per fer el pipe, entrada+sortida
    pipe(fd);
    int Entrada=open("dummy.dat",O_RDONLY);
            

    //mirem que el canal d'Entrada cap el capitol sigui correcte
    int estat= dummy_checkfile(Entrada);
    
    int suma=0;
    int id;
    
    if(estat){//si el banc d'entrada es correcte llavors entrem dins
        int pidr;
        int pid;
        if(pidr=fork()){ //Entra el fork del "Capitol"
            close(0);close(1);//Tanquem els std i posem x tal de conectar
            dup2(Entrada,0);dup2(fd[1],1);//el capitol amb el programa principal a traves dels fd a la posicio dels std
            close(fd[0]);//Tanquem els duplicats que no estan a la std
            close(fd[1]);
            char c;
            //-----------------
            
            kill(getppid(),SIGUSR1);
            
            while (read(0, &c, 1) > 0){
                write(1, &c, 1);
                
                
            } 
            
            

            exit(0);            
        }
        else{//entra el TT
            //wait(&id);
            //kill(pid, SIGUSR1);
           
            signal(SIGUSR1,ready);
            //ready(SIGUSR1);
            //waitpid(pidr,&id,0);
            close(fd[1]);
            int i=0;
            int fi=0;
            
            while(i<Nombre_Replicants && fi==0){
                pid=fork();
                ++i;
                if(pid==0){
                    
                    fi=1;
                }
                else{
                    wait(&id);
                    if (WIFEXITED(id)){
                        printf("%d \n",WEXITSTATUS(id));
                        suma=suma+WEXITSTATUS(id);
                    }
                }

            }
            if(pid==0){
                /*
                char erre[]="aaaaaaaaa";
                write(0,erre,strlen(erre));
                */
                close(0);
                dup(fd[0]);//Conectem el Replicant amb el capitol 
                close(fd[0]);
                
                char buffer[Memoria];
                dummy_init(buffer,Memoria);
                
                int by;
                while((by=read(0,&buffer,Memoria))>0){
                    dummy_calc(buffer, Memoria);
                }
                dummy_end();
                exit(0);//no entra
            }
            close(fd[0]);//jaja se ma olvidao


             
            dummy_testing(suma,ENIGMA2,TEAMNAME,BRONCEKEY);    


        }






    }
    else{
        close(fd[0]);
        close(fd[1]);

    }































    /*
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
                if(WEXITSTATUS(stat)!=-1){
                    wiwa=wiwa+WEXITSTATUS(stat);
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
        int by;
        while((by=read(entrada,&buffer,Memoria))>0) dummy_comp(buffer, by);
        dummy_exit();
    }
    dummy_test(wiwa, ENIGMA1, TEAMNAME);
    */
}
