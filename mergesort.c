#include <stdio.h>
int a[10];
void merge()
void mergesort(int lb, int ub)
{
	if(ub==lb)
	  merge();
	int mid=(ub+lb)/2;
	mergesort(lb,mid);
	mergesort(mid+1,ub);
}
int main()
{
	int n,i;
	printf("Enter n  ");
	scanf("%d",&n);
	printf("Enter %d values  ",n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	mergesort(1,n); 
}
