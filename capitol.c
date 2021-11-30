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
int main(int argc,char *argv[]){
    char c;
    kill(getppid(),SIGUSR1);

    while(read(0,&c,1)){
        write(1,&c,1);
    }
    
    
    exit(0);
}
