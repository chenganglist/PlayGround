# PlayGround
小段代码练习场          
   
##一、插入排序
从0到num，不设置哨兵的简单直接插入排序，实现文件为insertSort.c   


##二、希尔排序
从0到num，采用循环嵌套，第一个循环设置gap，实现分组；第二个循环实现分组；   
第三四个循环实现最基本的插入排序算法   

##三、快速排序
利用start和end游标左右回走，实现中间位置的查找；由于每次start<end的时候，   
要么start++，要么end--,终止条件一定是start==end；所以一开始存储的中间元素，   
最后赋值给a[start]或者a[end]都是一样的    

###三个要点
一是要注意边界的处理，整个排序统一采用“有效边界原则”--
即end总是指向排序数组最后一个元素，而不是数组的最后一个元素的下标+1；       
二是中间元素左右回走实现数据交换，将基元素放到合适位置；    
三是在递归时注意上一次的中间元素是有序的，不要将其加入下次排序；  


##四、归并排序
一是写好归并函数，接口形式为func(int a[],int low,int mid,int high),      
整个排序统一采用“有效边界原则”--即high总是指向排序数组最后一个元素，而不是最后一个元素的下标+1；       
二是利用递归进行分组，最后调用归并函数，从而实现归并算法    

##五、堆排序
一是调整最大堆，ajustHeap(int a[],int i)这是核心函数，用于处理理想化的堆； 
该函数假设堆中只有节点i不满足要求，然后对齐进行调整，这是理解的关键；   
采用理想化条件下的函数，简化问题，从而得到排序算法的最终实现思路  
二是堆的节点关系  a[i]=parent; a[2*i+1]=lchild; a[2*i+2]=rchild;  
下标从“金字塔”塔顶从上到下，从左到右递增；         
三是建立最大堆，建立最大堆后，通过交换堆顶元素与堆底元素，实现排序；        
四是通过循环，不断调用调整最大堆函数，完成排序  
   






