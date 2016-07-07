#include <stdio.h>
#include <stdlib.h>

//从第i个节点向下调整节点
//这里的n指数组元素的个数
void ajustMaxHeap(int a[],int i,int n)
{
	int lchild = 2*i + 1;
	int rchild = 2*i + 2;
	while(lchild<n)
	{
		if(rchild<n)
		{
			if(a[lchild]>a[rchild] && a[lchild]>a[i])
			{
				int tmp = a[lchild];
				a[lchild] = a[i];
				a[i] = tmp;
				i = lchild;
			    lchild = 2*i + 1;
				rchild = 2*i + 2;
			}else if(a[rchild]>a[lchild] && a[rchild]>a[i])
			{
				int tmp = a[rchild];
				a[rchild] = a[i];
				a[i] = tmp;
				i = rchild;
			    lchild = 2*i + 1;
				rchild = 2*i + 2;
			}else{
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
			    lchild = 2*i + 1;
				rchild = 2*i + 2;
			}else
			{
				break;
			}
		}
	}
}


//建立最大堆
void buildMaxHeap(int a[],int n)
{
	int i;
	for(i = n/2;i>=0;i--)
	{
		ajustMaxHeap(a,i,n);
	}
}


//每次选择最大元素，完成最大堆排序
void maxHeapSort(int a[],int n)
{
	buildMaxHeap(a,n);

	int i;
	for(i=n-1;i>0;i--)
	{
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		ajustMaxHeap(a,0,i);
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

	maxHeapSort(a,num);

	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}

	free(a);
	return 0;
}