#include <stdio.h>
#include <time.h>
int arr[10];
void bsort_non(int a[], int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	  for(j=0;j<n-1-i;j++)
	    if(a[j]>a[j+1])
	      {
	      	t=a[j];
	      	a[j]=a[j+1];
	      	a[j+1]=t;
				}
	printf("Sorted array-non recusrion\n");
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);	
	printf("\n");				
}
void bsort(int n)
{
	int i,t;
	if(n==1)
	  return;
	for(i=0;i<n-1;i++)
	  if(arr[i]>arr[i+1])
	      {
	      	t=arr[i];
	      	arr[i]=arr[i+1];
	      	arr[i+1]=t;
				}
	bsort(--n);		 
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
	bsort_non(a,n);
	t=clock()-t;
	printf("Time in non-recursive bubble sort is %f\n",(float)t/CLOCKS_PER_SEC);
	r=clock()-t;
	bsort(n);
	r=clock()-r;  
	printf("Sorted array-recusrion\n");
	for(int i=0;i<n;i++)
	  printf("%d ",arr[i]);	
	printf("\n"); 
	printf("Time in recursive bubble sort is %f\n",(float)r/CLOCKS_PER_SEC);
}
