##链表
针对头结点不为空的链表，进行链表的创建和增删查改实现    

整个链表要特别注意将链表尾节点设置为NUL         
这是链表打印、删除遍历的条件      

###链表的创建
1、通过元素个数设置，实现链表创建函数退出，完成创建链表       

2、通过指定的输入，比如0，实现创建函数退出，不方便      

3、创建时要注意：  
一是要将头结点作为返回值，实现创建链表的对外可访问性 

二是要设置cur游标，记录链表最新元素位置    

4、整个链表创建的头结点有实际元素     


###链表的打印
通过设置链表游标cur，以游标指针为NULL作为结束条件       



###链表的删除
通过设置链表游标cur，在free当前节点时，先保存下一个节点， 

然后删除当前节点；每次删除前判断cur是否为NULL，如果cur为      

NULL就结束删除     


###链表的插入
通过指定链表插入位置进行元素插入   

需要设置计数变量curPos与插入位置insertPos进行比较    

要考虑越界的问题


###链表的删除
一是通过指定位置进行删除，需要设置位置变量，要考虑越界的问题   

二是通过指定元素值进行删除，有两种方案，一种是每次删除第一个   

匹配的值，另一种是删除所有匹配的值     