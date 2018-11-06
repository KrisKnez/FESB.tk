#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
  int fd1, n, brojac;
  off_t s;

  brojac = -1;
  char sl;
   
  if (argc != 2) 
  {
    printf("Koristenje: citaj <ime_datoteke>\n");
    exit(0);
  }
                    
  fd1=open(argv[1], O_RDONLY);

  if (fd1 < 0) 
  {
    perror("open");
    exit(-1);
  }

  if (lseek(fd1, -1, SEEK_END)==-1)
    perror("Greska");
                                    
  while((n=read(fd1, &sl, 1)) > 0) 
  {
    write(STDOUT_FILENO, &sl, 1);
	s=lseek(fd1, -2, SEEK_CUR);
    if (s==-1)
	  perror("Greska");
    if(s==0)
	{
	  read(fd1,&sl,1);
	  write(STDOUT_FILENO,&sl,1);
	  return -1;
    }
  } 
                                              
  if (n == -1) 
  {
    perror("read");
  }
                                                          
  close(fd1);
  exit(0);
}

