#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*head = NULL;

int main()
{
	int i,j,size,position;
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	printf("Enter the size of linkList: ");
	scanf("%d", &size);
		
	for(i=0;i<size;i++)
	{
		struct node* new_node = (struct node*) malloc (sizeof(struct node));
		printf("Enter element for the list: ");
		scanf("%d", &new_node->data);
		new_node->link = NULL;
		
		printf("Enter position where you want to insert an element: ");
		scanf("%d", &position);
		
		if(head ==NULL)
		{
			head = new_node;
		}
		else
		{
			temp1 = head;	
					
			if(position==0)
			{				
				printf("Inserting at the beigning \n");
				new_node->link = head;
				head = new_node;
			}
			else		//insertion at any other position except beginning
			{
				for(j=1; j<position; j++)
				{	
					temp1 = temp1->link;
				}
				new_node->link = temp1->link;
				temp1->link = new_node;
			}
		}	
	}
	
	temp1 = head;
	printf("Created linklist is: ");
	while(temp1!= NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->link;
	}
	
	//deletion from any position
	
	printf("\nStarting deletion process: \n");
	
	if(head == NULL)
	{
		printf("List is empty");
	}
	else
	{
		temp1 = head;
		struct node* temp2 = head;
		printf("Enter the no. of node which you want to delete: ");
		scanf("%d", &position);
		
		if(position == 1)	//used for deleting 1st node and moving head to the next position i.e 2nd node becomes the 1st now.
		{
			head = temp1->link;
			free(temp1);
		}
		else
		{
			for(i=1; i<position; i++)	//for accessing node which is next to the node which you want to delete
			{
				temp1 = temp1->link;
			}
			
			for(i=1; i<position-1; i++)	//for accessing node which is at previous position to the node which you want to delete
			{
				temp2 = temp2->link;
			}
			temp2->link = temp1->link;	//linking nodes and skipping the middle one
			free(temp1);
		}
	}
	
	temp1 = head;
	printf("\nDeleted node linklist is: ");		//display linklist except the deleted node
	while(temp1!= NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->link;
	}
	
}
