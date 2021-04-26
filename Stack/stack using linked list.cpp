#include<stdlib.h>
#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node * link;
}*top = NULL;

void push()
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter element to be pushed: ");
	scanf("%d", &new_node->data);
	new_node->link = NULL;
	
	if(top == NULL)
	{
		top = new_node;
	}
	else
	{
		new_node->link = top;
	}
	top = new_node;
	cout << "Element pushed: "<< top->data << endl;
}

void pop()
{
	if(top == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		struct node *temp1 = top;
		
		cout << "Deleted data is: " << temp1->data << endl;
		top = temp1->link;
		free(temp1);
	}
}

void display()
{
	if(top == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		cout << "List is: ";
		while(top != NULL)
		{
			cout << top->data << " ";
			top = top->link;
		}
		
		cout << endl;
	}
}

int main()
{
 	int op;
do{
 	printf("Select operation: \n");
 	printf("1. PUSH kar \n");
 	printf("2. POP kar \n");
 	printf("3. Display kar \n");
 	printf("0. terminate the loop:- ");
 	scanf("%d", &op);
 	
 	switch(op)
 	{
 		case 1:
		{
		 	push();
			 break;	
		}	
		 case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			display();
			break;		
		}
		default:
		{
			printf("enter correct option \n");
		}
	}
}while(op!=0);

}
