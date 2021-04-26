#include<stdio.h>
#include<stdlib.h>

struct node{	//link list self referncial strcuture
	int data;
	struct node* link;
}*head=NULL;


int main()
{
	int i;
	struct node *temp1 = (struct node*)malloc(sizeof(struct node));	//memory allocation using malloc
	
	//code to create linklist 1st
for(i=0;i<3;i++)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter 3 elements for link list: ");	//taking i/p valus for a link list
	scanf("%d", &new_node->data);
	new_node->link = NULL;	
	
	if(head == NULL)	//as linklist is empty at 1st head node is assigned to a  created node
	{
		head = new_node;
	}
	
	else		//assigning link of previous node to the next node
	{	
		temp = head;
		temp1 = head;
		while(temp->link!=NULL)
		{
			temp = temp->link;
		 }
		temp->link = new_node;	
	}
}

//code to node at any position

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	int position=0;
	printf("\n enter position where you want to insert element: ");
	scanf("%d", &position);
	
	printf("\n Enter the element for new node: ");
	scanf("%d", &new_node->data);
	
	printf("previos linklist: \n");
	while(temp1 != NULL)
	{
		printf("%d  ", temp1->data);
		temp1 = temp1->link;
	}

	
	if(head==NULL)
	{
		head = new_node;
	}
	else
	{
	temp = head;
		if(position==0)
		{
			new_node->link = head;
			head = new_node;
		}
		else
		{
			for(i=0;i<position-1; i++)
			{	
			temp = temp->link;
			}
	new_node->link = temp->link;
	temp->link = new_node;
		}
   }
	
	printf("\n displaying linklist along with newly inserted element: ");
	
	while(head!=NULL)
	{
		printf("%d  ", head->data);
		head = head->link;
	}
	
}
