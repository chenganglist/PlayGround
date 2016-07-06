#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int start,int mid,int end)
{
	int num = end-start+1;
	int* tmp = (int*)malloc(num*sizeof(int));
	int i = 0,j = start,k = mid+1;
	while(i<num)
	{
		if(j<=mid && k<=end)
		{
			if(a[j]<a[k])
			{
				tmp[i] = a[j];
				j++;
			}else
			{
				tmp[i] = a[k];
				k++;
			}
		}else if(j<=mid)
		{
			tmp[i] = a[j];
			j++;
		}else if(k<=end)
		{
			tmp[i] = a[k];
			k++;
		}
		i++;
	}

	for(i=0;i<num;i++)
	{
		a[start+i] = tmp[i];
	}
	free(tmp);
}

void mergeSort(int a[],int start,int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		merge(a,start,mid,end);
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

	mergeSort(a,0,num-1);

	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	return 0;
}