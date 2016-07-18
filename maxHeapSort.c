#include <stdio.h>
#include <stdlib.h>

//需要注意左右子节点相等，并且同时大于父节点的情况
//注意数组与堆的对应关系了lchild=2*p+1;rchild=2*p+2
void ajustMaxHeap(int a[],int i,int n)
{
	int lchild = 2*i+1;
	int rchild = 2*i+2;
	while(lchild<n)
	{
		if(rchild<n)
		{
			if(a[rchild]>a[i] && a[rchild]>=a[lchild])
			{
				int tmp = a[rchild];
				a[rchild] = a[i];
				a[i] = tmp;
				i = rchild;
				lchild = 2*i+1;
				rchild = 2*i+2;
			}else if(a[lchild]>a[i] && a[lchild]>=a[rchild])
			{
				int tmp = a[lchild];
				a[lchild] = a[i];
				a[i] = tmp;
				i = lchild;
				lchild = 2*i+1;
				rchild = 2*i+2;
			}else
			{
				break;
			}
		}else
		{
			if(a[lchild]>a[i])
			{
				int tmp = a[lchild];
				a[lchild] = a[i];
				a[i] = tmp;
				i = lchild;
				lchild = 2*i+1;
				rchild = 2*i+2;
			}else
			{
				break;
			}
		}
	}
}


void buildMaxHeap(int a[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		ajustMaxHeap(a,i,n);
	}
}

//堆排序实际是一种选择排序
void maxHeapSort(int a[],int n)
{
	buildMaxHeap(a,n);
	int i;
	for(i=n-1;i>0;i--)
	{
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		ajustMaxHeap(a,0,i);
	}
}


int main(int argc,char* argv[])
{
	int num;
	puts("请输入数组的大小：");
	fflush(stdout);
	scanf("%d",&num);

	puts("请依次输入数组元素：");
	fflush(stdout);
	int *a = (int*)malloc(num*sizeof(int));

	int i;
	for(i=0;i<num;i++)
	{
		scanf("%d",a+i);
	}

	maxHeapSort(a,num);

	puts("排序结果为： ");
	fflush(stdout);
	
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}

	free(a);
	return 0;
}