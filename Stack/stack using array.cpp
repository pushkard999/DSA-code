#include<iostream>
#include<stdlib.h>

using namespace std;

int top =-1;

int push(int stack[], int size)	//push function 
{
	int value;
	
	if(top == size-1)	//check if the stack overflow happens
	{
		cout << endl;
		cout << "Stack is full" << endl;
	}
	else	//else keep on adding values on the stack means increment array index and add value to the next index
	{
		cout << endl;
		cout << "Enter a value which you want to push: ";
	    cin >> value;
	    
		top++;
		stack[top] = value;
		cout << "value pushed is:  " << stack[top] << endl;
	}
	return top;
}


int pop(int top, int stack[])
{
	if(top == -1)		//check if stack is empty
	{
		cout << "Stack is empty" << endl;
	}
	else		// else delete element which is lastly added to the stack
	{
		cout << endl;
		cout << "Deleted element is: " << stack[top] << endl;
		top--;
		
	}
	
	return top;
	
}

void display(int top, int stack[])
{
	if(top == -1)		//check if stack is empty
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		while(top != -1)		//else display all the elements of stack last to first
		{
			cout <<"Stack elements are: " <<stack[top];	
			top--;
	}
	cout << endl;
	
   }
}


int main()
{
	int size,op;
	
	cout << "Enter size of stack: ";
	cin >> size;
	
	int stack[size];
	
do{
	cout << endl;		// select operation
	cout << "Select operation: " << endl;
	cout << "1. PUSH KAR" << endl;
	cout << "2. POP kar" << endl;
	cout << "3.Display kar	";
	
	cin >> op;
	
	switch(op)
	{
		case 1:
			{
				push(stack, size);
				break;
			}
		case 2:
			{
				top = pop(top, stack);
				break;
			}
		case 3:
			{
				display(top, stack);
				break;
			}
		default:
			{
				cout << "Enter correct no." << endl;
			}
			
	}
}
while(op!=0);
	
	
}
