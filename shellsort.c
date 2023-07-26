#include <stdio.h>
#include <time.h>
int a[10];
void swap(int *a, int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
void shellsort(int n, int dist)
{
  int i,j,k,l;
  if(dist==0)
    return;
  for(i=0,j=i+dist;j<n;i++,j++)
    {
      if(a[i]>a[j])
        swap(&a[i],&a[j]);
      for(k=i-dist,l=i;a[l]<a[k] && k>=0;l=k,k-=dist)    
        swap(&a[l],&a[k]);
    }
  shellsort(n,dist/2);        
}
int main()
{
  int n,i;
  clock_t t;
  printf("Enter n ");
  scanf("%d",&n);
  printf("Enter %d values ",n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  t=clock();
  shellsort(n,n/2);
  t=clock()-t;
  printf("Sorted array\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\nTime taken by shellsort is %fs",(float)t/CLOCKS_PER_SEC);    
}
