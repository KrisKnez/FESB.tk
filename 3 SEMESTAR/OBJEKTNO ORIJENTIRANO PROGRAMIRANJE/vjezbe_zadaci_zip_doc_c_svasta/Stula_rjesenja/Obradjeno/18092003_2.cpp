#include <stdio.h>
int y=0;
void main(void)
{
printf("%d\n",y);
if(++y)
{
int y=5;
printf("%d\n",++y);
}
printf("%d\n",y);
}