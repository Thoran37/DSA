#include <stdio.h>
int D,a[30],b[30],i,r,j,R;
int double_hash(int k, int f)
{
  r=(k+j*(R-(f%R)))%D;
  if(b[r]==0 || j>D)
    return r;
  else
    {
      j++;
      double_hash(k,f);
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
        b[double_hash(k,a[i])]=a[i];  
    }
}
int main()
{
  int flag,k;
  printf("Enter D ");
  scanf("%d",&D);
  printf("Enter 0 to stop\n");
  printf("Enter numbers ");
  i=0;
  while(scanf("%d",&a[i]))
    {
      if(!a[i])
        break;
      i++;
    }
  for(i=D-1;i>=0;i--)
    {
      flag=1;
      for(int h=2;h<i;h++)
        if(i%h==0)
          {
            flag=0;
            break;
          }
      if(flag)
        {
          R=i;    
          break;
        }
    }
  hash();
  for(i=0;i<D;i++)
    printf("%d ",b[i]);
}
