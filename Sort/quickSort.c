#include <stdio.h>
#include <stdlib.h>

//起始位置和终止位置都是有效位置
//变量不要设置太多，直接使用start和end左右回走
int findMiddle(int a[],int start,int end)
{
	int tmp=a[start];

	while(start<end)
	{
		while(start<end)
		{
			if(a[end]<tmp)
			{
				a[start] = a[end];
				start++;
				break;
			}
			end--;
		}


		while(start<end)
		{
			if(a[start]>tmp)
			{
				a[end] = a[start];
				end--;
				break;
			}
			start++;
		}
	}

	//以下两句代码都可行
	//a[start] = tmp;
	a[end] = tmp;
	return start;
}


void quickSort(int a[],int start,int end)
{
	if(start<end)
	{
		int mid = findMiddle(a,start,end);
		//中间已经排好的数不加入下一步排序
		quickSort(a,start,mid-1);
		quickSort(a,mid+1,end);
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

	quickSort(a,0,num-1);

	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}

	free(a);
	return 0;
}