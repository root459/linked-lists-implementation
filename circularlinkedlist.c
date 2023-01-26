#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;
};
struct node *tail,*temp=0,*newnode;
void createcll(){
    int choice=1;
    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=0;
      printf("enter the data for the node");
      scanf("%d",&newnode->data);
      if(temp==0)
      tail=temp=newnode;
      else{
        temp->next=newnode;
        temp=newnode;
        }
        printf("enter 1 for continue else print 0 for stop");
        scanf("%d",&choice);
    }
    temp->next=tail;
    tail=temp;
}
void display(){
    temp=tail->next;
    while(temp!=tail){
        printf("the data of node is  %d\n",temp->data);
        temp=temp->next;

    }
    printf("the data of node is %d\n",temp->data);
}
void insbeg(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data for the node");
    scanf("%d",&newnode->data);
    newnode->next=tail->next;
    tail->next=newnode;
}
void inspos(){
    int pos,i=1;
    printf("enter the position");
    scanf("%d",&pos);
    if(pos==1){
        insbeg();
    }
    else{
    temp=tail->next;
    
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data for the node");
    scanf("%d",&newnode->data);
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
}
void insend(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the value of node");
    scanf("%d",&newnode->data);
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
}
void delbeg(){
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
}
void delpos(){
    temp=tail->next;
    int pos,i=1;
    printf("enter the value of pos");
    scanf("%d",&pos);
    struct node *prev=0;
    while(i<pos){
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);
}
void delend(){
    temp=tail->next;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
  
}
void rev(){
    struct node *currentnode,*nextnode,*prevnode;
    
}
void main(){
    createcll();
    display();
   // insbeg();
  // inspos();
  //insend();
 // delbeg();
 //delpos();
 delend();
    display();
}