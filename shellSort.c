#include <stdio.h>
#include <stdlib.h>

void shellSort(int a[],int num)
{
	int gap,k,i,j;
	for(gap=num/2;gap>=1;gap=gap/2)
	{
		for(k=0;k<gap;k++)
		{
			for(i=k;i<num-1;i=i+gap)
			{
				for(j=i;j>=k;j=j-gap)
				{
					if(a[j+1]<a[j])
					{
						int tmp = a[j+1];
						a[j+1] = a[j];
						a[j] = tmp;
					}else
					{
						break;
					}
				}
			}
		}
	}
}

int main()
{
	int num;
	scanf("%d",&num);
	int* a = (int*)malloc(num*sizeof(int));
	int i;
	for(i=0;i<num;i++)
	{
		scanf("%d",a+i);
	}

	shellSort(a,num);

	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	return 0;
}