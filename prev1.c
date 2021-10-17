// Funci´o que procesa el codi del exit
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 20
int llegir_comanda(char *com){
    int len=0;
    char tmp[80];
    sprintf(tmp,"Escriu una comanda acabada amb Ctrl-D (exit per sortir)\n");
    write(1,tmp,strlen(tmp));
    if((len=read(0,com,MAX))==-1){
        printf("Error al llegir comanda\n");
    }
    return len;
}
int main()
{
    
    while(1){
        int longitud;
        int pid;
        int stat;
        char text[MAX];
        longitud=llegir_comanda(text);
    
        if (longitud>0)//mentres la comanda sigui major que 0
        {
            if (strcmp(text,"exit")==0){ //comparem el text amb exit i si son iguals sortim
                //int strcmp (const char* str1, const char* str2);   https://www.programiz.com/c-programming/library-function/string.h/strcmp
                exit(0);
            }
            else{
                
                pid=fork();//creem un fill
                if(pid==0){ //i si es el fill llavors entrem aqui 
                
                
                    printf("Executant %s amb PID=%d\n",text,getpid());//imprimim el text i el fill
                    execlp(text,text,NULL); //executem la comanda i si tot funciona be el fill s'acaba, 
                    printf("Comanda incorrecta\n"); //si no s'acaba vol dir que ha donat error  i llavors avisem i fem un exit per no deixar zombis
                    exit(0); 
                }
                
                
            }
            wait(&stat);//Esperem al fill per tal de que acabi
            //printf("%d\n",stat);
            //PREGUNTA:  Quina es la utilitat del stat?
            if (WIFEXITED(stat)){
                printf("Fill amb PID %d acaba amb un Exit status: %d\n",pid, WEXITSTATUS(stat));

            }
            /*
            int b=1; //https://www.geeksforgeeks.org/wait-system-call-c/
            int a=wait(&b);
            printf("B: %d\n",b); 
            printf("a: %d\n",a); 
            printf( "pid:%d\n",pid);  
            */         
            
        }
    }
}


