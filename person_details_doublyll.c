#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first = 0;
int count = 0;
NODE create()
{
    NODE encode;
    encode = (NODE)malloc(sizeof(struct node));
    if (encode == 0)
    {
        printf("running out of memory");
        exit(0);
    }
    printf("\nEnter the ssn ,name , department ,designation, salary,phone number of the employ\n");
    scanf("%s%s%s%s%d%ld", encode->ssn, encode->name, encode->dept, encode->designation, &encode->sal, &encode->phone);
    encode->llink = 0;
    encode->rlink = 0;
    count++;
    return encode;
}
NODE insertfront()
{
    NODE temp;
    temp = create();
    if (first == 0)
    {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;
}
void display()
{
    NODE cur;
    int nodeno = 1;
    cur = first;
    if (cur == 0)
        printf("\n no contains to display in dll");
    while (cur != 0)
    {
        printf("\nENode:d||ssn:%s|NAME:%s|department:%s|designation:%s|salary:%d|phonenumber:%ld", nodeno, cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phone);
        cur = cur->rlink;
        nodeno++;
    }
    printf("\n  no. of employees is %d ", count);
}
NODE deletefront()
{
    NODE temp;
    if (first == 0)
    {
        printf("\ndoubly linked list is empty ");
        return NULL;
    }
    if (first->rlink = 0)
    {
        printf("\nthe employee node with the ssn:%s is deleted ", first->ssn);
        free(first);
        count--;
        return NULL;
    }
    temp = first;
    first = first->rlink;
    temp->rlink = NULL;
    first->llink = NULL;
    printf("\n the employeye node with ssn:%s is deleted ", temp->ssn);
    free(temp);
    count--;
    return first;
}
NODE insertend()
{
    NODE cur, temp;
    temp = create();
    if (first == NULL)
    {
        return temp;
    }
    cur = first;
    while (cur->rlink != 0)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}
NODE deleteend()
{
    NODE prev, cur;
    if (first == 0)
    {
        printf("\n dll is empty");
        return NULL;
    }
    if (first->rlink = 0)
    {
        printf("\n the employ node with the ssn:%s is deleted ", first->ssn);
        free(first);
        count--;
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->rlink != 0)
    {
        prev = cur;
        cur = cur->rlink;
    }
    cur->llink = NULL;
    printf("\n THE Employyee node with the ssn :%s is deleted", cur->ssn);
    free(cur);
    prev->rlink = 0;
    count--;
    return first;
}
void main()
{
    int ch, i, n;
    while (1)
    {
        printf("\n\n~~~~MENU~~~");
        printf("\n1:create dll of employnodes");
        printf("\n2:display status\n3:insertatend\n4:deleteatend\n5:insertatfront\n6:deleteat front\n7:exit\nENTER YOUR CHOICE");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n enter the no. of employees");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                first = insertend();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            first = insertend();
            break;
        case 4:
            first = deleteend();
            break;
        case 5:
            first = insertfront();
            break;
        case 6:
            first = deletefront();
            break;
        case 7:
            exit(0);
        default:
            printf("\n please enter the valid choice ");
        }
    }
}
