#include <stdio.h>
#include <time.h>
int bs(int a[],int l,int r,int x)
{
	int mid;
	if(r>=l)
	  {
	  	mid=l+(r-l)/2;
	  	if(a[mid]==x)
	  	  return 1;
	  	else if(a[mid]>x)
			  return bs(a,l,mid-1,x);
			return bs(a,mid+1,r,x);	  
		}
	return 0;	
}
int bs_n(int a[],int l,int r,int x)
{
	int mid;
	while(r>=l)
	  {
	  	mid=l+(r-l)/2;
	  	if(a[mid]==x)
	  	  return 1;
	  	else if(a[mid]>x)
	  	  r=mid-1;
			else
			  l=mid+1;  
		}  	
	return 0;	
}	
int main()
{
	int n,a[n],b;
	clock_t t,r;
	printf("Enter number of numbers  ");
	scanf("%d",&n);
	printf("Enter numbers\n");
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("Enter number to search  ");
	scanf("%d",&b);
	t=clock();
	if(bs(a,0,n-1,b))
	  printf("%d is found\n",b);
	else
	  printf("%d is not found\n",b); 
	t=clock()-t;
	printf("Time in recursive is %f\n",(float)t/CLOCKS_PER_SEC);
	r=clock()-t;
	if(bs_n(a,0,n-1,b))
	  printf("%d is found\n",b);
	else
	  printf("%d is not found\n",b);    
	r=clock()-r;  
	printf("Time in non-recursive is %f\n",(float)r/CLOCKS_PER_SEC);  
}
