#include <stdio.h>
#include <time.h>
int a[10],ind=1,n,h=1;
void swap(int *a,int *b)
{
	int t=*a;
  *a=*b;
  *b=t;
}
void heapsort()
{
  while(2*h<=n)
    {  
      int max=a[2*h]>a[2*h+1]?2*h:2*h+1;
      if(2*h==n)
        max=2*h;
      if(a[h]<a[max])
        {
          swap(&a[h],&a[max]);
          h=max;
        }
      else
        break;  
    }
}
void reheap()
{
	if(n==1)
	  return;
	swap(&a[1],&a[n]);
	n--;
	heapsort();
  h=1;
  reheap();
}
void insert(int k)
{
	int i=ind;
	a[ind++]=k;
	while(i/2)
	  {
		  if(a[i]>a[i/2])
			  {
				  swap(&a[i],&a[i/2]);
				  i/=2;
			  }
			else
			  break;
		}
}
int main()
{
	int i,q,k;
	clock_t t;
	printf("Enter n  ");
	scanf("%d",&n);
	k=n;
	printf("Enter %d numbers  ",k);
	for(i=0;i<n;i++)
	  {
	  	scanf("%d",&q);
	  	insert(q);
		}
	t=clock();	
	reheap();	
	t=clock()-t;
	printf("Sorted array\n");
	for(i=1;i<=k;i++)
	  printf("%d ",a[i]);	
	printf("\nTime taken by heap sort is %fs",(float)t/CLOCKS_PER_SEC);	
}
