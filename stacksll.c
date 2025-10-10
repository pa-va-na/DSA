#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(){
    int val;
    printf("enter value\t");
    scanf("%d",&val);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
        return;
    }
    else{
        newnode->next=top;
        top=newnode;
        
    }
}
void pop(){
    if(top==NULL){
        printf("stack underflow\n");
        return;
    }
    struct node* temp=top;
    printf("%d\n",temp->data);
    top=top->next;
    free(temp);

}
void peek(){
    if(top==NULL){
        printf("stack empty\n");
        return;
    }
    printf("%d\n",top->data);
}
void display(){
    if(top==NULL){
        printf("stack empty\n");
    }
    else{
        struct node* temp=top;
        while(temp->next!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("\n");
    }
}
int main(){
    int o;
    printf("Operations \n1:Push\t2:Pop\t3:Peek\n4:Display\n");
    while(1){
        printf("enter op\t");
        scanf("%d",&o);
        switch(o){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("exiting...\n");
                return 0;
        }
    }
}