#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node    //structure of node
{
	int data;          //data
	struct node *next; //pointer of next node
};
struct node *head;
void main()
{
	int i,flag=0;
	struct node *temp;
	struct node *temp1;
	struct node *slow,*fast;//pointer for checking loop in a linked list
	clrscr();
	head = NULL;
	for(i=0;i<10;i++) //cre4ating 10 node inserting at head
	{
		temp=(struct node *)malloc(sizeof(struct node));
			temp->data=i+1;   //storing data
			temp->next=head;  //pointing to the head node
			head= temp;       //current node become head
	}
	temp1=head;
	printf("befor loop :=");
	while(temp1!=NULL)  //printing of all the node
	{
		printf("%d -> %d,\n",temp1->data,temp1->next->data);
		temp1=temp1->next;
	}
	temp=head;
	for(i=1;i<=5;i++) //externally creating a loop from node 5 to node 3
	{
		if(i==3)
		{
			temp1=temp;//while traversing storing the address of node 3
		}
		if(i==5)
		{
			temp->next=temp1;//copying address of node 3 in next pointer of node 5
		}
		temp=temp->next;
	}
	slow=head;//at start both the node are pointing to head
	fast=head;
	while(1)
	{
		slow=slow->next;//every time slow is increased by 1 node
		fast=fast->next->next; //and fast is increased by 2 node
		if(slow==fast) //true if there is loop
		{
			flag=1; //if there is a loop there will be a instance
				//when slow anf fast object meet each other(crossing point)
			break;
		}
		if(slow==NULL || fast==NULL)//if there is no loop then there will
					    //be a time when both the node will reach
					    //at the end of the list
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nThere is loop");
	}
	else
	{
		printf("\nThere is no loop");
	}
	getch();
}