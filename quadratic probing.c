#include <stdio.h>

int D,a[30],b[30],i,r,j;

int quad_prob(int k)
{
  r=(k+j)%D;
  if(b[r]==0 || j>D)
    return r;
  else
    {
      j*=j;
      quad_prob(k);
    }
}

void hash()
{
  int k;
  for(i=0;i<D;i++)
    {
      j=0;
      k=a[i]%D;
      if(!b[k])
        b[k]=a[i];
      else
        b[quad_prob(k)]=a[i];  
    }
}

int main()
{
  printf("Enter D ");
  scanf("%d",&D);
  printf("Enter numbers ");
  for(i=0;i<D;i++)
    scanf("%d",&a[i]);
  hash();
  for(i=0;i<D;i++)
    printf("%d ",b[i]);
}
