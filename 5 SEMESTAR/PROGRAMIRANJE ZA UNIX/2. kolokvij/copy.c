#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1,fd2,n;
  char c;

  if( argc!=3)
  {
	printf(" Nedovoljan broj argumenata:");
	return 0;
  }

	fd1 = open (argv[1],O_RDONLY);
	fd2 = open (argv[2],O_CREAT|O_RDWR|O_APPEND);

	if(fd1==-1 && fd2==-1)
	{
	  perror("open");
	  return 0;
	}

	while((n=read(fd1,&c,1))>0)
		write(fd2,&c,1);
	
	close(fd1);
	close(fd2);
	
 
	return 0;
}
