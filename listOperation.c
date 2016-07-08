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
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head =  head->next;
	}
}


int main()
{
	node* listHead = createList();
	printList(listHead);
	return 0;
}






