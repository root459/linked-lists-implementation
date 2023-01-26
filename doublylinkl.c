#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
// if we declare and initialize a variable outside the fun and change in a fun its value will bechanged or not?//
//  struct node *head=0,*tail=0,*newnode=0;

struct node *head, *tail, *newnode,*temp;


 void insert()
{
   // struct node *head=0, *tail=0, *newnode=0;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data ");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if (head == 0)
        {
            tail = head = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("enter 1 to continue or 0 for stop");
        scanf("%d", &choice);
    }
    
    
}

int display()
    
{   int count=0;
    
    temp = head;
    while (temp!= 0)
    {
        printf("the node element is %d\n", temp->data);
        temp = temp->next;
        count++;

        
    }
    return count;
}
void insertbeg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for node 1");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insertend(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data for the last node");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;

}
void insertpos(){
    
}
void main()


{ int count=0;
    insert();
    count=display();
   // insertbeg();
   insertend();
    count=display();

    printf("the total numver of nodes are %d",count);}