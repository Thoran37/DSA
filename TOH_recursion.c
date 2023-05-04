#include<stdio.h>
#include<stdlib.h>
void TOH(int disks,char S,char D,char A)
{
	if(disks==1)
	  printf("moved from %c to %c\n",S,D);
	else
	  {
	    TOH(disks-1,S,A,D);
			printf("moved from %c to %c\n",S,D);
			TOH(disks-1,A,D,S);	
		}  
}
int main()
{
	int disks;
	char A,B,C;
	printf("Enter no.of disks  ");
	scanf("%d",&disks);
	TOH(disks,'A','B','C');
}
