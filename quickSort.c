#include <stdio.h>
#include <stdlib.h>

//起始位置和终止位置都是有效位置
int findMiddle(int a[],int start,int end)
{
	int i=start,j=end,mid=start;

	while(i<j)
	{
		for(j=end;j>start;j--)
		{
			if(a[j]<a[mid])
			{
				end = j;
				int tmp = a[j];
				a[j] = a[mid];
				a[mid] = tmp;
			}
		}


		for(i=start;i<end;i++)
		{

		}
	}
	mid = i;
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