#include<iostream>

using namespace std;
int front =-1, rear =-1;

void enqueue(int queue[], int size)
{
	int value; 

		if(rear == size-1)
		{
			cout << "Queue is full" << endl << endl;	
		}
		else
		{
			if(front == -1)
			{
				front = 0;
			}
			
			cout << "Enter element you want to insert: ";
			cin >> value;
			rear++;
			queue[rear] = value;
			cout << "Enqueued element is: " << queue[rear] << endl << endl;
				
		}	
}	



void dequeue(int queue[])
{
	if(front == -1 && rear == -1)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << endl <<"Dequeued element is: " << queue[front] << endl << endl;
			if(front == rear)
			{
				front = -1;
				rear = -1;
			}
			else
			{
				front++;
			}
		
	}
	
}


void display(int queue[])
{
	cout <<endl;
	
	if(front == -1 && rear == -1)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{	
		int front1 = front, rear1 = rear;
		cout << "Elements are: ";
	
		while(front1 != rear1 + 1)
		{
			cout << queue[front1] << " ";
			front1++;
		}
	
		cout << endl;
	}
}


int main()
{
	int op,size,queue[size];
	
	cout << "Enter size of queue you want to create: ";
	cin >> size;
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
				enqueue(queue, size);
				break;
			}
		case 2:
			{
				dequeue(queue);
				break;
			}
		case 3:
			{
				display(queue);
				break;
			}
		default:
			{
				cout << "Enter correct no." << endl;
			}
	}

}while(op!=0);


}
