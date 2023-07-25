#include <stdio.h>
#include <time.h>
int arr[10];
void selection_non(int a[], int n)
{
	int i,j,t,loc;
	for(i=0;i<n-1;i++)
	  {
	  	loc=i;
	  	for(j=i+1;j<n;j++)
	  	  if(a[j]<a[loc])
	  	    loc=j;
	  	if(loc!=i)
			  {
	      	t=a[i];
	      	a[i]=a[loc];
	      	a[loc]=t;
				}    
		}
	printf("Sorted array-non recursion\n");
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);	
	printf("\n");				
}
void selection_rec(int n, int i)
{
	int loc=i,t,j=i+1;
	if(i==n)
	  return;
	for(;j<n;j++)
	  if(arr[j]<arr[loc])
	    loc=j;
  t=arr[i];
  arr[i]=arr[loc];
  arr[loc]=t;
	selection_rec(n,i+1);		
}
int main()
{
	int n,i,a[10];
	clock_t t,r;
	printf("Enter n  ");
	scanf("%d",&n);
	printf("Enter %d numbers  ",n);
	for(i=0;i<n;i++)
	  {
	    scanf("%d",&a[i]);
	    arr[i]=a[i];  
	  }  
	t=clock();
	selection_non(a,n);
	t=clock()-t;
	printf("Time in non-recursive selection sort is %f\n",(float)t/CLOCKS_PER_SEC);
	r=clock()-t;
	selection_rec(n,0);
	r=clock()-r;  
	printf("Sorted array-recursion\n");
	for(i=0;i<n;i++)
	  printf("%d ",arr[i]);	
	printf("\n"); 
	printf("Time in recursive selection sort is %f\n",(float)r/CLOCKS_PER_SEC);
}
