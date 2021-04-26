#include<iostream>
#include<stdlib.h>	//necessary for memory allocation function

using namespace std;
struct node		//create structure for front rear
{
	int data;
	struct node *link;
}*front = NULL, *rear = NULL;

void enqueue()		//function to add elements in queue
{
	struct node *new_node =(struct node*)malloc(sizeof(struct node));
	cout << "Enter data to be enqueued: ";		//creating new node and adding data to its data part and pointing its link part to NULL
	cin >> new_node->data;
	new_node->link = NULL;
	
	if(front == NULL && rear == NULL)		//f and r are equal to NULL means queue is empty have assign newly(1st created) node to f and r
	{
		front = new_node;
		rear = new_node;
		
	}
	else	// 2nd node onwards only increment rear i.e. point previous node's link part to the next node
	{
		rear->link = new_node;
		rear = new_node;
	}
	
	cout << "inserted node: " << rear->data << endl;
	
}

void dequeue()
{
	if(front == NULL && rear == NULL)		//its empty
	{
		cout << "Queue is empty" << endl << endl;
		
	}
	else		
	{
		struct node *temp1 = front;		//creating other struct pointer temp1 so that front can be incremented to next node and using temp1 = front, previous value is stored in temp1 and freed using free() function 	
		front = front->link;
		if(front == NULL)	//if front reached at the end update rear == NULL
		{
			rear = NULL;
		}
		
		cout << "Deleted element is: " << temp1->data << endl;
		temp1->link = NULL;
		free(temp1);
	}	
}

void display()
{
	if(front == NULL && rear == NULL)
	{
		cout << "Queue is empty" << endl << endl;
	}
	else
	{
		struct node *temp1 = front;		//purposly created new struct pointer temp1 bez front is global so its value get upadted in every function and that same value gets used in the next function
		cout << "data is: ;
		while(temp1 != NULL)
		{
			cout << " " << temp1->data;
			temp1 = temp1->link;
		}
		
		cout << endl << endl;
	}
}

int main()
{
	int op;
do{

	cout << "Select operation: " << endl;
	cout << "1. for Enqueue operation: " << endl;
	cout << "2. for dequeue operation: " << endl;
	cout << "3. for display : " << endl;
    cout << "0. for terminate loop: " << "  ";
	cin >> op;	
	
	switch(op)
	{
		case 1:
			{
				enqueue();
				break;
			}
		case 2:
			{
				dequeue();
				break;
			}
		case 3:
			{
				display();
				break;
			}
		default:
			{
				cout << "Enter correct no." << endl;
			}
		
	}
	
 } while(op!=0); 
	
	
}
