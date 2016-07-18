//mergeSort
#include <stdio.h>
#include <stdlib.h>

//merge
void merge(int a[],int start,int mid,int end)
{
	int num = end - start + 1;
	int* tmp = (int*)malloc(num*sizeof(int));
	int i=start,j=mid+1;
	int k = 0;
	while(k<num)
	{
		if(i<=mid && j<=end)
		{
			if(a[i]<a[j])
			{
				tmp[k] = a[i];
				i++;
			}else
			{
				tmp[k] = a[j];
				j++;
			}
		}else if(i<=mid)
		{
			tmp[k] = a[i];
			i++;
		}else if(j<=end)
		{
			tmp[k] = a[j];
			j++;
		}else{
			break;
		}
		k++;
	}
	for(i=0;i<num;i++)
	{
		a[start+i] = tmp[i];
	}
	free(tmp);
}

//mergeSort
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





int main(int argc,char* argv[])
{
	int num;
	puts("请输入排序数组元素个数: ");
	fflush(stdout);
	scanf("%d",&num);

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

	mergeSort(a,0,num-1);
	
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}	
	free(a);
	return 0;
}