#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *link;		//self referencial structure
} *head = NULL;

int main ()
{
  struct node *new_node, *temp;
  temp = (struct node *) malloc (sizeof (struct node) * 1);

 int i;
for (i = 0; i < 3; i++)
{
  new_node = (struct node *) malloc (sizeof (struct node) * 1);
  printf ("Enter data for new node: ");
  scanf ("%d", &new_node->data);
  //printf(": %d", new_node->data );
  new_node->link = NULL;
  
    if (head == NULL)
	{
	  head = new_node;
	}
    
	else
	{
	  temp = head;
	  while (temp->link != NULL)
	    {
	      temp = temp->link;
	    }
	  temp->link = new_node;
	}
}

  while (head != NULL)
    {
      printf ("%d  ", head->data);
      head = head->link;
    }

}

