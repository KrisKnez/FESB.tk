//Ispisuje dane datoteke ili standardni ulaz

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define BUFFSIZE 8192

int main(int argc, char *argv[])
{
    int n, fd1, i;
    char sl;
    char buf[BUFFSIZE];
    
    //ako nema argumenata citaj s standardnog ulaza
    if (argc <= 1){
        while((n=read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
            if (write(STDOUT_FILENO, buf, n) != n)
                perror("write");
        if(n < 0)
            perror("read");
            
    //ako ima argumenata citaj s tim datotekama
    } else {
        for (i=1; i<argc; i++){
            fd1=open(argv[i], O_RDONLY);
            while(read(fd1, &sl, 1) > 0)
                write(STDOUT_FILENO, &sl, 1);
            close(fd1);
        }
    }
    
    exit(0);
}

