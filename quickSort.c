#include <stdio.h>
#include <stdlib.h>

//起始位置和终止位置都是有效位置
int findMiddle(int a[],int start,int end)
{
	int i=start,j=end,mid=start;

	while(start<end)
	{
		for(j=end;j>start;j--)
		{
			if(a[j]<a[mid])
			{
				int tmp = a[j];
				a[j] = a[mid];
				a[mid] = tmp;
				mid = j;
				end = j;
			}
		}


		for(i=start;i<end;i++)
		{
			if(a[i]>a[mid])
			{
				int tmp = a[i];
				a[i] = a[mid];
				a[mid] = tmp;
				mid = i;
				start = i;
			}
		}
	}

	return mid;
}


void quickSort(int a[],int start,int end)
{
	if(start<end)
	{
		int mid = findMiddle(a,start,end);
		quickSort(a,start,mid);
		quickSort(a,mid+1,end)
	}
}

int main()
{
	int num;
	scanf("%d",&num);
	int i;
	int *a = (int*)malloc(num*sizeof(a));

	for(i=0;i<num;i++)
	{
		scanf("%d",a+i);
	}

	quickSort(a,0,n-1);

	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}

	free(a);
	return 0;
}