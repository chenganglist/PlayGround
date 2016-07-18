//quickSort
#include <stdio.h>
#include <stdlib.h>

//findMiddle递归的核心,不要引入多余变量，以免纠缠不清
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


//quickSort
void quickSort(int a[],int start,int end)
{
	if(start<end)
	{
		int mid = findMiddle(a,start,end);
		quickSort(a,start,mid-1);
		quickSort(a,mid+1,end);
	}
}


int main(int argc,char* argv[])
{
	int num;
	puts("请输入排序数组元素个数: ");
	fflush(stdout);
	
	int *a = (int*)malloc(num*sizeof(int));
	int i;
	puts("请依次输入数组元素: ");
	fflush(stdout);

	for(i=0;i<num;i++)
	{
		scanf("%d",a+i);
	}

	puts("排序后的结果: ");
	fflush(stdout);	

	for(i=0;i<num;i++)
	{
		printf("%d",a[i]);
	}	
	free(a);
	return 0;
}