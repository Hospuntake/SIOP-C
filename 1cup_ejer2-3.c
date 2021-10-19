#include <stdio.h>
//#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    while(1){
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
        int pid;
        if(comoEntero==-38){
            printf("Introduzca un carácter porfavor\n");
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
            printf("(-1)El primer nombre no és enter mes gran que 0! \n");
        }
        else{
            if(caracter[0]==48){
                fi=0;
                n=0;
                while(!caracter[n]==0){
                    ++n;
                    if(caracter[n]!=48 && caracter[n]!=0 ){
                        fi=1;
                        break;
                    }
                }
                if(fi==1) printf("El primer nombre és enter mes gran que 0!\n");
                else printf("(-1)El primer nombre no és enter mes gran que 0! \n");


            }
            else printf("El primer nombre és enter mes gran que 0!\n");
        }

        n=0;
        comoEntero = caracter2[n] - '0';   
        resp=0;
        fi=1;
        if(comoEntero==-38){
            printf("Introduzca un carácter porfavor\n");
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
            printf("(-1)El segon nombre no és enter mes gran que 0! \n");
        }
        else{
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
                if(fi==1) printf("El segon nombre és enter mes gran que 0!\n");
                else printf("(-1)El segon nombre no és enter mes gran que 0! \n");


            }
            else printf("El segon nombre és enter mes gran que 0!\n");
        }



        //CREACIO DEL REPLICANT
        n=4;
        int a=0;
        fi=0;
        //printf("PADRE AAAAA getpid: %d  pid: %d\n",getpid(),pid);
        int blacklist=getpid();
        while(a<n && fi==0){
            int pid=fork();
            printf("PIDS: %d\n",getpid());
            if(pid==0) fi=1;
            else wait();
            ++a;
            
        }
        //printf("getpid: %d  pid: %d\n",getpid(),pid);
        if (blacklist!=getpid()){

        
            
            if(pid==0){
                n=0;
                comoEntero = caracter2[n] - '0';   
                resp=0;
                fi=1;
                if(comoEntero==-38){
                    printf("-1\n");
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
                    printf("-1\n");
                }
                else{
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
                        if(fi==1) printf("El replicant amb PID: %d ha comprovat que el segon nombre és enter mes gran que 0!\n",getpid());
                        else printf("-1\n");


                    }
                    
                    else printf("El replicant amb PID: %d ha comprovat que el segon nombre és enter mes gran que 0!\n",getpid());
                }
                
                exit(0);
                
                
            }
        }
        
        /*
        else{
            int stat;
            while((pid=waitpid(-1,&stat,WNOHANG))>0){
                if (WIFEXITED(stat)){
                    printf("Fill amb PID %d acaba amb un Exit status: %d\n",pid, WEXITSTATUS(stat));

                }
                
            }

            
            
            printf("Replicant amb PID %d acaba amb un Exit status: %d\n",pid,stat);
            

        }
        */
    }
}
