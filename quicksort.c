#include <stdio.h>
#include <time.h>
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
			while(left<=ub && a[left]<=pivot)
				left++;
			while(right>=lb && a[right]>pivot)
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
	clock_t t;
	printf("ENter n  ");
	scanf("%d",&n);
	printf("Enter %d numbers  ",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	t=clock();	
	quicksort(0,n-1);	
	t=clock()-t;
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nTime taken for recursive quick sort is %f",(float)t/CLOCKS_PER_SEC);	
}
