//G_KEY=0xdc0df       :)))))))))))))))))))))))))))))))))
//Comentari: Tarda una mica avegades , pero sempre acaba compilant .
#define TEAMNAME "JoaquimHervas" // insert between "" your team name
#define ENIGMA2 "SIGSTOP" // insert between "" solution of enigna 2
#define BRONCEKEY "7a65f" // insert BRONCEKEY between ""
#define SERVNAME "SIOP-server"
#define SERVADDR "147.83.159.200"
#define SERVPORT 9999
#define CRTLPORT 9900
#define ENIGMA3 "07F4"// replace simbol @ with solution of enigna 3
#define SILVERKEY "ab39f"  // insert SILVERKEY between ""
#define GOLDKEY "" // use only for SIOP Challenge : insert GOLDKEY between ""

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include "dummy4.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
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
        write(1,"(-1)El nombre no és un natural mes gran que 0! \n",49);
        return 0;
    }
    else{
        return 1;
    }
}

int main(){

    printf("Indiqui el nombre de replicants\n->");
    char caracter2[100];
    scanf("%s",caracter2);
    int r=comprova_int(caracter2);
    int Nombre_Replicants;
    if(r==1){
        Nombre_Replicants = atoi(caracter2);
        if(Nombre_Replicants<=0){
            write(1,"(-1)El primer nombre no és mes gran que 0! \n",44);
            exit(-1);
        } 
    }
    else exit(-1);

    

    printf("Indiqui la memoria del replicant en Bytes\n->");
    char caracter[100];
    scanf("%s",caracter);
    r=comprova_int(caracter);

    if(r==1){
        int pr = atoi(caracter);
        if(pr<=0){
            write(1,"(-1)El segón nombre no és mes gran que 0! \n",44); 
            exit(-1);
        }
    }
    else exit(-1);

    int ctrlfd=ctrlconnect(SERVADDR,CRTLPORT,ENIGMA3, TEAMNAME, SILVERKEY, GOLDKEY); //retorna el file descriptor del canal de control i verifica l'enigma i la clau
    int fd = connecta(SERVADDR,SERVPORT); //retorna el file descriptor del canal de dades
    int fi=0;int i=0;int id;int suma=0;int pid;
    while(i<Nombre_Replicants && fi==0){
        pid=fork();
        ++i;
        if(pid==0){      
            fi=1;
            close(ctrlfd);
            dup2(fd,0);close(fd);
            
            execlp("./4replicant","4replicant",caracter,NULL );//INSERIR NOMBRE DEL ARCHIVO!!!!!!!!!!!!!!!!!!!!!!!!
        }//############################################################
        else{
            wait(&id);
            printf("Exit Status= %d \n",WEXITSTATUS(id));
            suma=suma+WEXITSTATUS(id);
        }
    }
    
    /*******reading answer from Capitol **************/
    char buffer[suma],buffy[256];
    int nbytes=sprintf (buffer, "%d", suma);
    write(ctrlfd,buffer,nbytes);
    int len=read(ctrlfd,buffy,128);
    buffy[len]='\0';
    printf("MISSION: %s\n",buffy);
    close(ctrlfd); 
}
