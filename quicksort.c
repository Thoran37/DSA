#include <stdio.h>
int a[10];
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int lb,int ub)
{
	int pivot=a[lb],left=lb+1,right=ub;
	while(left<=right)
		{
			while(a[left]<=pivot)
				left++;
			while(a[right]>pivot)
				right--;
			if(left<right)
				swap(&a[left],&a[right]);		
		}
	swap(&a[lb],&a[right]);
	return right;	
}
void quicksort(int lb,int ub)
{
	int loc;
	if(lb<ub)
		{
			loc=partition(lb,ub);
			quicksort(lb,loc-1);
			quicksort(loc+1,ub);
		}
}
int main()
{
	int n;
	printf("ENter n  ");
	scanf("%d",&n);
	printf("Enter %d numbers  ",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(0,n-1);	
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
