#include <stdio.h>
#include <stdlib.h>

//find middle element
//end is the edge of array
int findMiddle(int a[],int start,int end)
{
	int data = a[start];
	while(start<end)
	{
		while(start<end)
		{
			if(a[end]<data)
			{
				a[start] = a[end];
				start++;
				break;
			}
			end--;
		}
		
		while(start<end)
		{	
			if(a[start]>data)
			{
				a[end] = a[start];
				end--;
				break;
			}
			start++;
		}
	}
	a[start] = data;
	return start;
}

void quickSort(int a[],int start,int end)
{
	if(start<end)
	{
		int mid = findMiddle(a,start,end);
		quickSort(a,start,mid-1);
		quickSort(a,mid+1,end);
	}
}


int main()
{
	int num;
	scanf("%d",&num);
	int *a = (int*)malloc(num*sizeof(int));
	
	int i;
	for(i=0;i<num;i++)
	{
		scanf("%d",a+i);
	}
	quickSort(a,0,num-1);
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}
	free(a);

	return 0;
}
