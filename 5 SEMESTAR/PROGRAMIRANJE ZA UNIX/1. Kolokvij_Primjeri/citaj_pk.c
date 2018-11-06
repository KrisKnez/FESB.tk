#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) 
{
  int fd, n, l, i;  
  char c;  
  off_t poz;
  
  if (argc < 4) 
  {    
    printf("koristenje: ./pkcitaj <ime_datoteke> <broj od kojeg pocimamo citanje> <broj procitanih znakova>\n");   
    exit(0);  
  }  
  
  fd = open(argv[1], O_RDONLY);
  
  if (fd < 0) 
  {    
    perror("open"); 
    exit(-1);  
  }  

  poz = atoi(argv[2]);  
  
  if (lseek(fd, poz, SEEK_SET) == -1) 
  {
    perror("lseek");
    exit(-1);
  }
   
  l = atoi(argv[3]);
  
  for ( i=0 ; i<l ; i++) 
  {
    if ((n = read(fd, &c, 1)) > 0 ) 
    write(STDOUT_FILENO, &c, 1);    
    else 
    {      
      if (n == -1)  
        perror("read");
      else
        printf("\n\n");
      close(fd);
      exit(0);
    }    
  }  

  printf("\n\n");
  close(fd);
  return 0;
}
