#include<stdio.h>
#include<stdlib.h>

struct node
{						//link list self referncial strcuture
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

	
	//deletion at the end code
	struct node *temp2 = (struct node*)malloc(sizeof(struct node));
		
	if(head == NULL)
	{
		printf("linklist is already empty");	//checked whether the link list is empty or not
	}	
	else
	{
		if(head->link == NULL)	//checked whether linklist has only 1 element to delete if yes then do it..
		{
			head = NULL;
		}
		else			// for deleting elements at the end
		{
			while(temp1->link != NULL)	
			{
				temp2 = temp1;
				temp1 = temp1->link;
			}
			temp2->link = NULL;
		}
		free(temp1);
	}
	
		
	printf("\ndisplaying linklist after deletion of element: ");
	temp1 = head;
	while(temp1!=NULL)
	{
		printf("%d  ", temp1->data);
		temp1 = temp1->link;
	}
	
	
}
