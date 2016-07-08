#include <stdio.h>
#inlcude <stdlib.h>

typedef struct node
{
	int data;
	node *next;
}node;

node* create()
{
	node* head = (node*)malloc(sizeof(node));

	while(1)
	{
		printf("Please input data,input 'e' to exit create");
		int data;
		scanf("%d",&data);


	}

	return head;
}






