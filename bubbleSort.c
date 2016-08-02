#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[],int n)
{
    int i,j;
    //最外部的循环是为了对趟次进行计数
    for(i=n-1;i>0;i--)
    {
        //每跑一趟，数组前n个多一个有序元素；
        //跑多少趟，就有多少有序元素（不必加入比较的元素）
        for(j=n-1;j>(n-1-i);j--)
        {
            if(a[j-1]>a[j])
            {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

int main(int argc,char* argv[])
{
    int num;
    puts("请输入数组元素个数：");
    fflush(stdout);
    scanf("%d",&num);

    puts("请依次数组元素个数：");
    fflush(stdout);

    int * a = (int *)malloc(sizeof(int)*num);
    int i = 0;
    for(i=0;i<num;i++){
        scanf("%d",a+i);
    }


    bubbleSort(a,num);

    puts("冒泡排序后的结果：");
    fflush(stdout);

    for(i=0;i<num;i++)
    {
        printf("%d ",a[i]);
    }
    puts("");

    free(a);
    return 0;
}