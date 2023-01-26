#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *tail = 0, *head = 0, *newnode = 0;
void create()
{
    int choice = 1, count;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data for the node");
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
        printf("enter the choice for continue enter 1 elsee 0");
        scanf("%d", &choice);
    }
}
int display()
{
    struct node *temp;
    temp = head;
    int count = 0;

    while (temp != 0)
    {
        printf("the value of node is %d\n", temp->data);
        temp = temp->next;
        count++;
    }
    return count;
}
void insertbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node *));
    printf("enter the data for the node");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data for the node");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void inspos()
{
    int pos;
    struct node *temp;
    printf("enter the position");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertbeg();
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d", &newnode->data);
    temp = head;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
}
void delbeg()
{
    struct node *temp;
    temp = head;
    temp->next->prev = 0;
    head = temp->next;
    free(temp);
}
void delend()
{
    struct node *temp;
    temp = tail;
    temp->prev->next = 0;
    tail = temp->prev;
    free(temp);
}
void delpos()
{
    struct node *temp;
    int pos, i = 1;
    printf("enter the pos");
    scanf("%d", &pos);
    temp = head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void reverse()
{
    struct node *current, *after;
    current = head;
    while (current != 0)
    {
        after = current->next;
        current->next = current->prev;
        current->prev = after;
        current = after;
    }
    current = head;
    head = tail;
    tail = current;
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
            create();
            break;
        case 2:
            insertbeg();

            break;
        case 3:
            inspos();

            break;
        case 4:
            insend();
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
            printf("the numver of nodes are %d", display());
            break;
        case 10:
            reverse();
            break;
        default:
            printf("invlaid choice enter choice from 1,2,3 only");
        }
    }
}
