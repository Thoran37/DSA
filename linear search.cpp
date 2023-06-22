#include <stdio.h>
#include <time.h>
int linear_search(int a[],int b,int n)
{
	for(int i=0;i<n;i++)
	  if(a[i]==b)
	    return 1;
	return 0;    
}
int recursive(int a[],int b,int n)
{
	if(n==0)
	  return 0;
	else if(a[n-1]==b)
	  return 1;
	else
	  return recursive(a,b,n-1);  
}
int main()
{
	int n,a[n],b,k;
	clock_t t;
	printf("Enter number of numbers  ");
	scanf("%d",&n);
	printf("Enter numbers\n");
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("Enter number to search  ");
	scanf("%d",&b);  
	printf("Enter 1 for non-recursive and 2 for recursive  ");
	scanf("%d",&k);
	switch(k)
	  {
	  	case 1: t=clock();
							if(linear_search(a,b,n))
			          printf("%d is found\n",b);
			        else
			          printf("%d is not found\n",b); 
							t=clock()-t;
							printf("The time taken is %f seconds\n",(float)t/CLOCKS_PER_SEC);break;
			case 2: t=clock();
							k=recursive(a,b,n);
							if(k==0)
							  printf("%d is not found\n",b);
							else 
							  printf("%d is found\n",b);  
							t=clock()-t;
							printf("The time taken is %f seconds\n",(float)t/CLOCKS_PER_SEC);  
		}
	    
}
