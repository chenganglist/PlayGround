# PlayGround
小段代码练习场          
   
##一、插入排序
从0到num，不设置哨兵的插入排序，实现文件为insertSort.c   


##二、希尔排序
从0到num，采用循环嵌套，第一个循环设置gap，实现分组；第二个循环设置分组；   
第三四个循环实现最基本的排序算法   

##三、快速排序
直接利用start和end游标左右回走，实现中间位置的查找；由于每次start<end的时候，   
要么start++，要么end--,终止条件一定是start==end；所以一开始存储的中间元素，   
最后赋值给a[start]或者a[end]都是一样的    

###三个要点
一是要注意边界的处理，整个排序都将采用边界元素加入排序     （即边界值合法且在本次来回查找的比较范围内有值的形式进行）；    
二是中间元素左右回走实现数据交换，将基元素放到合适位置；    
三是在递归时注意上一次的中间元素是有序的，不要将其加入下次排序；  


##四、归并排序
一是写好归并函数，接口形式为func(int a[],int low,int mid,int high),      
整个排序统一采用“有效边界原则”--即high总是指向排序数组最后一个元素，而不是最后一个元素的下标+1；       
二是利用递归进行分组，最后调用归并函数，从而实现归并算法       
   






