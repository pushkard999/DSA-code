#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
}*head=NULL;

int main()
{
	struct node *temp1 = (struct node*) malloc (sizeof(struct node));
	int i,size;
	printf("Enter the size of linklist: ");
	scanf("%d",&size);
	//create a linklist
	for(i=0;i<size;i++)
	{
		struct node* new_node = (struct node*) malloc (sizeof(struct node));	//allocate memory for new node when for loop get executed every time
		
		printf("Enter element for creating a linklist:	");
		scanf("%d",&new_node->data);
		new_node->link = NULL;
		
		if(head==NULL)
		{
			head = new_node;
		}	
		else
		{
			temp1 = head;	//make a copy of head pointer, it should point to the 1st node and also after creating a copy you use that for other operations as well
			while(temp1->link!= NULL)
			{
				temp1 = temp1->link;		//traverse till the last inserted node
			}
			temp1->link = new_node;	//last node's link point should point to the newly created node
		}
	}
	
	temp1 = head;
	printf("Your created linklist is: ");
	while(temp1 != NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->link;
	}	
	
	//deletion at the begining
	printf("\n Starting deletion operation:	\n");
	struct node* temp2;
	
	if(head == NULL)
	{
		printf("list is already empty!!!	\n");
	}
	else
	{
		temp1 = head;
		if(temp1->link==NULL)
		{
			temp1 = NULL;
		}
		else
		{
			head = temp1->link;
		}
		free(temp1);
	}
	
	printf("Displaying list after deletion: ");
	temp1 = head;
	while(temp1 != NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->link;
	}
	
}
