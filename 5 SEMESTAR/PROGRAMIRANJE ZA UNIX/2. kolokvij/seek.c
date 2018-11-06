#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1, n;
  char sl;
   
  if (argc != 2) {
    printf("Koristenje: citaj <ime_datoteke>\n");
    exit(0);
  }
                    
  fd1=open(argv[1], O_RDONLY);
  if (fd1 < 0) {
    perror("open");
    exit(-1);
  }

	if (lseek(fd1, 3, SEEK_SET)==-1)
	perror("Greska");
                                    
  while((n=read(fd1, &sl, 1)) > 0) {
    write(STDOUT_FILENO, &sl, 1);
  } 
                                              
  if (n == -1) {
    perror("read");
  }
                                                          
  close(fd1);
  exit(0);
}
