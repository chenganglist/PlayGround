#include <stdio.h>
#include <stdlib.h>

void ajustMaxHeap(int a[],int i,int num)
{
    int lchild = 2*i + 1;
    int rchild = 2*i + 2;
    while(lchild<num)
    {
        if(rchild<num)
        {
            if(a[lchild]>a[i] && a[lchild]>=a[rchild])
            {
                int tmp = a[i];
                a[i] = a[lchild];
                a[lchild] = tmp;
                i = lchild;
                lchild = 2*i + 1;
                rchild = 2*i + 2;               
            }else if(a[rchild]>a[i] && a[rchild]>=a[lchild])
            {
                int tmp = a[i];
                a[i] = a[rchild];
                a[rchild] = tmp;
                i = rchild;
                lchild = 2*i + 1;
                rchild = 2*i + 2;    
            }else
            {
                break;
            }
        }else
        {
            if(a[lchild]>a[i])
            {
                int tmp = a[i];
                a[i] = a[lchild];
                a[lchild] = tmp;
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

void buildMaxHeap(int a[],int num)
{
    int i = num-1;
    for(;i>0;i--)
    {
        ajustMaxHeap(a,i,num);
    }
}

void maxHeapSort(int a[],int num)
{
    buildMaxHeap(a,num);
    int i = num-1;
    for(;i>0;i--)
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
    scanf("%d",&num);
    int i,*a = (int*)malloc(num*sizeof(int));

    for(i=0;i<num;i++)
    {
       scanf("%d",a+i); 
    }

    maxHeapSort(a,num);
    
    for(i=0;i<num;i++)
    {
       printf("%d ",a[i]); 
    }
    puts("");
    free(a);
    return 0;
}