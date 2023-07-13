// Heap Sort
#include <stdio.h>
#include <time.h>
int a[100],index=1,n,h=1;
void swap(int i,int j)
{
	int t=a[i];
  a[i]=a[j];
  a[j]=t;
}
void heapsort()
{
	if(2*h>n)
	  {
	  	h=1;
	    reheap();
	  }
	int max=a[2*h]>a[2*h+1]?2*h:2*h+1;
	swap(h,max);
	h=max;
}
void reheap()
{
	if(n==1)
	  return;
	swap(1,n);
	n--;
	heapsort();
}
void insert(int k)
{
	a[index++]=k;
	int i=index;
	while(i/2)
	  {
		  if(a[i]>a[i/2])
			  {
				  swap(i,i/2);
				  i/=2;
			  }
			else
			  break;
		}
}
int main()
{
	int i,t,k;
	printf("Enter n  ");
	scanf("%d",&n);
	k=n;
	printf("Enter numbers  ");
	for(i=0;i<n;i++)
	  {
	  	scanf("%d",&t);
	  	insert(t);
		}
	reheap();	
	for(i=1;i<=k;i++)
	  printf("%d ",a[i]);	
}
