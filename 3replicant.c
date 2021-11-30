#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dummy3.h"

int main(int argc,char *argv[]){
	int Memoria = atoi(argv[1]);
    char* buffer=malloc(Memoria);
    dummy_init(buffer,Memoria);
    
    int by;
    while((by=read(0,buffer,Memoria))>0){
        dummy_calc(buffer, by);
    }
    dummy_end();
    exit(0);//no entra



}
