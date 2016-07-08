#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;


node* createList()
{
	node* head = NULL;
	node* cur;
	puts("先输入链表个数，再依次输入链表元素，完成链表创建：");
	fflush(stdout);
	int num;
	scanf("%d",&num);
	int i;
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			head = (node*)malloc(sizeof(node));
			scanf("%d",&(head->data));
			head->next = NULL;
			cur = head;
		}else
		{
			node* newElement = (node*)malloc(sizeof(node));
			scanf("%d",&(newElement->data));
			cur->next = newElement;
			newElement->next = NULL;
			cur = newElement;
		}
	}
	return head;
}



void printList(node* head)
{
	puts("打印的链表如下所示：");
	node* cur = head;
	while(cur!=NULL)
	{
		printf("%d ",cur->data);
		cur =  cur->next;
	}
	puts("");
}


//在指定位置插入新元素
void insertList(node* head,int insertPos,node* newElement)
{
	if(insertPos<0)
	{
		puts("unsupposrted position");
		return;
	}
	int pos = 0;
	node* cur = head;
	while(cur!=NULL)
	{
		if(insertPos == pos+1 )
		{
			newElement->next = cur->next;
			cur->next = newElement;
			return;
		}
		cur = cur->next;
		pos++;
	}
	if(pos<insertPos)
	{
		puts("unsupposrted position");
		return;
	}
}


void deleteListEleByPos(node* head,int deletePos)
{

}

void deleteListEleByValue(node* head,int delValue)
{

}
/*整个程序结束后，或者专业的说，进程结束后，
申请的内存是会被释放的，但是这要依靠底层操作系统
内存管理模块的实现机制，不同的实现机制释放
内存的时间也不相同。不过，作为一个良好的习惯，
申请内存和释放内存应该成对出现。*/
void deleteList(node* head)
{
	puts("删除链表，防止内存泄漏");
	node* cur = head;
	while(cur!=NULL)
	{
		node* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}



int main()
{
	node* listHead = createList();
	puts("创建的链表为：");
	printList(listHead);

	node* newElement = (node*)malloc(sizeof(node));
	newElement->data = 100;
	newElement->next = NULL;
	int insertPos =  5;
	insertList(listHead,insertPos,newElement);

	puts("插入新元素后链表为：");
	printList(listHead);
	deleteList(listHead);
	return 0;
}






