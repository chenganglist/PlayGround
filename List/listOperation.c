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


//在指定位置插入新元素,需要考虑替换头结点的情况
node* insertListByPos(node* head,int insertPos,node* newElement)
{
	if(insertPos<0)
	{
		puts("unsupposrted position");
		return head;
	}
	int pos = 0;
	node* cur = head;
	if(insertPos == 0)
	{
		newElement->next = head;
		return newElement;
	}

	while(cur!=NULL)
	{
		if(insertPos == pos+1 )
		{
			newElement->next = cur->next;
			cur->next = newElement;
			return head;
		}
		cur = cur->next;
		pos++;
	}
	if(pos<insertPos)
	{
		puts("unsupposrted position");
		return head;
	}
}

//需要考虑头结点被删除的情况
node* deleteListEleByPos(node* head,int deletePos)
{
	node* cur = head;
	int pos = 0;
	if(deletePos<0)
	{
		puts("out of range");
		return head;
	}

	if(deletePos == 0)
	{
		node* newHead = head->next;
		free(head);
		return newHead;
	}
	while(cur!=NULL)
	{
		if( deletePos == pos+1 && cur->next != NULL)
		{
			node* mcur = cur->next->next;
			node* curNext = cur->next;
			cur->next = mcur;
			free(curNext);
			return head;
		}
		cur = cur->next;
		pos++;
	}

	if(deletePos == pos)
	{
		free(cur);
		cur = NULL;
		return head;
	}
	if(deletePos>pos)
	{
		puts("out of range");
		return head;
	}
}


//需要考虑头结点被删除的情况
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
	fflush(stdout);
	printList(listHead);


	puts("插入链表测试：");
	node* newElement = (node*)malloc(sizeof(node));
	fflush(stdout);
	puts("请输入插入元素：");
	fflush(stdout);
	scanf("%d",&newElement->data);

	newElement->next = NULL;

	puts("请输入链表元素插入位置：");
	fflush(stdout);
	int insertPos;
	scanf("%d",&insertPos);

	insertListByPos(listHead,insertPos,newElement);

	puts("插入元素后链表为：");
	fflush(stdout);
	printList(listHead);

	puts("删除链表，请输入删除链表位置：");
	fflush(stdout);
	int deleteListPos;
	scanf("%d",&deleteListPos);
	deleteListEleByPos(listHead,deleteListPos);

	puts("删除元素后链表为：");
	fflush(stdout);
	printList(listHead);

	deleteList(listHead);

	return 0;
}






