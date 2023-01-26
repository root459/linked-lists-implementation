#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newnode;
void display()
{
    // struct node *head=0,*temp=0,*newnode=0;
    int i = 0;

    if (head == NULL)
    {
        printf("the list is empty");
    }
    temp = head;
    while (temp != NULL)
    {
        printf("thd data for node is %d\n", temp->data);
        temp = temp->next;
        i++;
    }
    printf("tne number of nodes are %d\n", i);
}

void insert()
{
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data for node\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("do you wnat to contimue enter 0 for stop\n");
        scanf("%d", &choice);
    }
}
void insert1st()
{
    // inssert at 1st position
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("eneter data for node at 1st position\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
void insertend()
{
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data for node to be displayed at last");
    scanf("%d", &newnode->data);
    temp->next = newnode;
    newnode->next = NULL;
}
void insertpos()
{
    int pos, i = 1;
    if (pos == 1)
    {
        insert1st();
    }
    else
    {
        printf("enter the position u want to enter");
        scanf("%d", &pos);
        // if(pos==1)
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data for node aat a given position");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
// deletion of nodes from linked lists
void delbeg()
{
    temp = head;
    head = temp->next;
    free(temp);
}
void delend()
{
    if (head == NULL)
        printf("there are no elements in the linked list");
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            newnode = temp;
            temp = temp->next;
        }
        newnode->next = NULL;
        free(temp);
    }
}
void delpos()
{
    int pos, i = 1;
    printf("enter the position frome we want to delete node");
    scanf("%d", &pos);
    temp = head;
    if (pos == 1)
        delbeg();
    else
    {
        while (i < pos)
        {
            newnode = temp;
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        free(temp);
    }
}
void reverse()
{
    struct node *prevnode = 0, *currentnode = 0, *nextnode = 0;
    currentnode = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

void main()
{
    int choice;

    while (1)
    {
        printf("choices are 1 for insertion \n2  for insert at beg \n 3 for insert at pos \n 4 for insert at end");
        printf("\n 5 for exit() \n 6 for delete at beg \n 7 for dlete at pos\n 8 for delete at end \n reverse the linked list \n 9 for display ");
        printf("enter the value of choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            insert1st();

            break;
        case 3:
            insertpos();

            break;
        case 4:
            insertend();
            break;
        case 5:
            exit(0);
            break;
        case 6:
            delbeg();
            break;
        case 7:
            delpos();
            break;
        case 8:
            delend();
            break;
        case 9:
            display();
            break;
        case 10:
            reverse();
            break;
        default:
            printf("invlaid choice enter choice from 1,2,3 only");
        }
    }
}
