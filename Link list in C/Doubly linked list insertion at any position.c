#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* previous, *next;
}*head = NULL;

void insertion_beginning()
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter data for new node: ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	new_node->previous = NULL;
	
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		head->previous = new_node;
		new_node->next = head;
		head = new_node;
	}
	
}

void insert_end()
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));

	
	printf("Enter data for new node: ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	new_node->previous = NULL;
	
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		temp1 = head;
		while(temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		new_node->previous = temp1;
		temp1->next = new_node;		 
	}

}

void insert_any_position()
{	
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	int position,i;
	
	printf("Enter data for new node: ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	new_node->previous = NULL;
	
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		temp1 = head;
		
		printf("Enter position where you want to insert node: ");
		scanf("%d", &position);
		
		if(position == 0)
		{
			printf("Inserting at the beginning: ");
			head->previous = new_node;
			new_node->next = head;
			head = new_node;
		}
		else
		{
			for(i=0; i<position-1; i++)
			{
				temp1 = temp1->next;
			}
			
		new_node->next = temp1->next;
		temp1->next = new_node;
		new_node->previous = temp1;
			
		}
		
	}
	
}


void delete_element()
{
	struct node *temp1=head, *temp2;
	int del,i,j=0,k=1;
	
	while(temp1 != NULL)
	{
		temp1 = temp1->next;
		j++;
	}
	
	if(head == NULL)
	{
		printf("Linked list is empty ");
	}
	else
	{
		temp1 = head;
		
		printf("\n");
		printf("Enter element you want to delete: ");
		scanf("%d", &del);
		
		while(temp1->data != del)
		{
			if(temp1 == NULL)
			{
				printf("no element is found");
				printf("\n");
			}
			else
			{
				temp1 = temp1->next;
				k++;
			}	
		}
		
		if(temp1 == head)
		{
			head = temp1->next;
			temp1 = NULL;
			free(temp1);
		}
		else if(j==k)
		{
			temp2 = temp1;
			temp2->previous->next = NULL;
			free(temp1);
		}
		else
		{
			temp1->previous->next = temp1->next;
			temp1->next->previous = temp1->previous;
			free(temp1);
		}
		

	}
}




void display_linkedlist()
{
	struct node* temp1 = head;
	printf("\n");
	printf("created LinkedList is: ");
	
	while(temp1 != NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
	printf("\n");
}


void display_linkedList_backwards()
{
	struct node *temp2;
	struct node *temp1 = head;
	
	while(temp1->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp1;
	}
	
	while(temp2 != NULL)
	{
		printf("%d ",temp2->data);
		temp2 = temp2->previous;
	}
	printf("\n");
	
}


int main()
{
	int op;
	
do{
	printf("***Select operation to be performed*** \n");
	printf("1. for Insertion at the beginning \n");
	printf("2. for Insert at the end \n");
	printf("3. for Insert at any position: \n");
	printf("4. for Displaying elements backwards: \n");
	printf("5. for Deleting node: \n");
	printf("6. Enter 0 to terminate the loop \t");

	scanf("%d",&op);
	
	switch(op)
	{
		case 1:
			{
				printf("\n");
				printf("Insertion at the beginning: \n");
				insertion_beginning();
				display_linkedlist();
				break;
			}
		case 2:
			{
				printf("\n");
				printf("Insert at the end: \n");
				insert_end();
				display_linkedlist();
				break;
			}
		case 3:
			{
				printf("\n");
				printf("Insert at any position: \n");
				insert_any_position();
				display_linkedlist();
				break;
			}
		case 4:
			{
				printf("\n");
				printf("Displaying elements backwards: ");
				display_linkedList_backwards();
				break;
			}
		case 5:
			{
				printf("\n");
				printf("Deleting element:");
				printf("\n");
				delete_element();
				display_linkedlist();
			}
			
		default :
			{
				printf("\n");
				printf("Enter correct operation no. \n");
				break;
			}
	}
}
while(op!=0);

return 0;

}
