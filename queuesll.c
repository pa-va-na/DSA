#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enq(){
    int val;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter val\t");
    scanf("%d",&val);
    newnode->data=val;
    if(front==NULL){
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
        return;
    }
    rear->next=newnode;
    newnode->next=NULL;
    rear=newnode;
}
void deq(){
    struct node* temp=front;
    if(front==NULL){
        printf("queue empty\n");
        return;
    }
    printf("%d\n",front->data);
    front=front->next;
    free(temp);
}
void display(){
    if(front==NULL){
        printf("queue empty\n");
        return;
    }
    struct node* temp=front;
    while(temp->next!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
int main(){
    int o;
    printf("Operations \n1:Enqueue\t2:Dequeue\t3:display\n");
    while(1){
        printf("enter op\t");
        scanf("%d",&o);
        switch(o){
            case 1:
             enq();
             break;
            case 2:
             deq();
             break;
            case 3:
             display();
             break;
            default:
             printf("exiting..\n");
             return 0;
        }
    }
}