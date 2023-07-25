#include <stdio.h>
#include <time.h>
int a[10];
void merge(int lb, int mid, int ub)
{
  int size1=mid-lb+1,size2=ub-mid,l[size1],r[size2],i,j,k;
  for(i=0;i<size1;i++)
    l[i]=a[lb+i];
  for(i=0;i<size2;i++)
    r[i]=a[mid+1+i];
  for(i=0,j=0,k=lb;i<size1 && j<size2;k++)
    {
      if(l[i]<=r[j])
        {
          a[k]=l[i];
          i++;
        }
      else
        {
          a[k]=r[j];
          j++;
        }   
    }  
  while(i<size1)
    {
      a[k]=l[i];
      i++;
      k++;
    }  
  while(j<size2)
    {
      a[k]=r[j];
      j++;
      k++;
    }  
}
void mergesort(int lb, int ub)
{
  if(lb<ub)
    {
      int mid=(ub+lb)/2;
      mergesort(lb,mid);
      mergesort(mid+1,ub);
      merge(lb,mid,ub);
    }
}
int main()
{
  int n,i;
  clock_t t;
  printf("Enter n  ");
  scanf("%d",&n);
  printf("Enter %d values  ",n);
  for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
  t=clock();   
  mergesort(1,n); 
  t=clock()-t;
  for(i=1;i<=n;i++)
    printf("%d ",a[i]);
  printf("\nTime taken by merge sort is %fs",(float)t/CLOCKS_PER_SEC);  
}
