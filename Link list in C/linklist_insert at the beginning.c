#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
}*head=NULL;

int main()
{
	int i;
for(i=0;i<5;i++)
{
	struct node* new_node =(struct node*)malloc(sizeof(struct node)*1);
	printf("Enter the data: ");
	scanf("%d",&new_node->data);
	
	if(head==NULL)
	{
		new_node->link = NULL;
		head = new_node;
	}
	
	else
	{
		new_node->link = head;
		head = new_node;
	}
}

while(head != NULL)
{
	printf("%d ", head->data);
	head = head->link;
}
	
}
