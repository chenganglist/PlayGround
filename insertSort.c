#include <stdio.h>
#include <stdlib.h>

//ºÚµ•≤Â»Î≈≈–Ú
void insertSort(int a[],int num)
{
	int i,j;
	for(i=0;i<num-1;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(a[j] < a[j-1])
			{
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}else
			{
				break;
			}
		}
	}
}

int main()
{
	int num;
	scanf("%d",&num);
	int i;
	int *a = (int*)malloc( num*sizeof(int) );
	for(i=0;i<num;i++)
	{
		scanf("%d",a+i);
	}

	insertSort(a,num);

	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	return 0;
}