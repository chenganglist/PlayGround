#include <stdio.h>
#include <stdlib.h>
//shellSort
//注意group只用于分组，gap才用于位移
void shellSort(int a[],int n)
{
	int gap,group,i,j;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(group=0;group<gap;group++)
		{
			for(i=group;i<n-gap;i+=gap)
			{
				for(j=i+gap;j>=gap;j-=gap)
				{
					if(a[j]<a[j-gap])
					{
						int tmp = a[j];
						a[j] = a[j-gap];
						a[j-gap] = tmp;
					}else{
						break;
					}
				}
			}
		}
	}
}

int main(int argc,char*argv[])
{
	int n;
	puts("请输入待排数组元素个数：");
	fflush(stdout);

	scanf("%d",&n);
	int* a = (int*)malloc(n*sizeof(int));
	puts("请依次输入待排数组元素：");
	fflush(stdout);	

	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}

	shellSort(a,n);

	puts("排序后的结果为：");
	fflush(stdout);

	for(i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
	free(a);
	return 0;
}