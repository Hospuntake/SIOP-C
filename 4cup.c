//G_KEY=0xdc0df       :)))))))))))))))))))))))))))))))))

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

int main(int argc, char *argv[]){
    if(argc==3){
        int r=comprova_int(argv[1]);
        int Nombre_Replicants;
        Nombre_Replicants = atoi(argv[1]);
        if(r==1){
            
            if(Nombre_Replicants<=0){
                write(1,"(-1)El primer nombre no és mes gran que 0! \n",44);
                exit(-1);
            } 
        }
        else exit(-1);
        

        r=comprova_int(argv[2]);
        int pr = atoi(argv[2]);
        //char caracter2=argv[2];

        if(r==1){
            
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
            if(pid==0 ){      
                fi=1;
                close(ctrlfd);
                dup2(fd,0);
                close(fd);
                
                execlp("./4replicant","4replicant",argv[2],NULL );//INSERIR NOMBRE DEL ARCHIVO!!!!!!!!!!!!!!!!!!!!!!!!
                
            }
            else{
                wait(&id);
                suma=suma+WEXITSTATUS(id);
            }
        }
        char buffer[suma],buffy[256];
        int nbytes=sprintf (buffer, "%d", suma);
        write(ctrlfd,buffer,nbytes);
        int len=read(ctrlfd,buffy,256);
        buffy[len]='\0';
        printf("MISSION: %s\n",buffy);
        close(ctrlfd);

    }
    else{
        write(1,"(-1)Format incorrecte. El format es el seguent: ./program NombreReplicants MemoriaReplicant(en bytes) \n",103);
        exit(-1);

    }
     
}
