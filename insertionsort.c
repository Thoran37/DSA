#include <stdio.h>
#include <time.h>
int arr[10];
void insertion_non(int a[], int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	  {
	  	t=a[i];
			for(j=i-1;j>=0 && a[j]>t;j--)
			  a[j+1]=a[j];
			a[j+1]=t;  
		}
	printf("Sorted array-non recursion\n");
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);	
	printf("\n");				
}
void insertion_rec(int n, int i)
{
	int t=arr[i],j;
	if(i==n)
	  return;
	for(j=i-1;j>=0 && arr[j]>t;j--)
	  arr[j+1]=arr[j];
	arr[j+1]=t;			
	insertion_rec(n,i+1);
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
	insertion_non(a,n);
	t=clock()-t;
	printf("Time in non-recursive selection sort is %f\n",(float)t/CLOCKS_PER_SEC);
	r=clock()-t;
	insertion_rec(n,0);
	r=clock()-r;  
	printf("Sorted array-recusrion\n");
	for(int i=0;i<n;i++)
	  printf("%d ",arr[i]);	
	printf("\n"); 
	printf("Time in recursive selection sort is %f\n",(float)r/CLOCKS_PER_SEC);
}
