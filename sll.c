#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;

void insf(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data to enter\t");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void inse(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data to enter\t");
    scanf("%d",&newnode->data);
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}
void inspos(){
    int p;
    int pos=1;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data to enter\t");
    scanf("%d",&newnode->data);
    printf("enter pos\t");
    scanf("%d",&p);
    temp=head;
    while(pos<p){
        temp=temp->next;
        pos++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void delf(){
    struct node* temp;
    temp=head;
    head=head->next;
    free(temp);
}
void dele(){
    struct node* temp;
    struct node* prev;
    temp=head;
    prev=temp;
    while(prev->next->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void delpos(){
    int pos,p=0;
    struct node* temp;
    struct node* prev;
    printf("enter position to delete\n");
    scanf("%d",&pos);
    temp=head;
    while(p<pos){
        prev=temp;
        temp=temp->next;
        p++;
    }
    prev->next=temp->next;
    free(temp);
}
void display(){
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int o;
    printf("Operations \n1:Insert at front \t2:Insert at end\n3:Insert at any pos\t 4:Delete from front\n5:Delete from back\t 6:Delete from any pos\n7:Display\n");
    while(1){
        printf("Enter Operation\t");
        scanf("%d",&o);
        switch(o){
            case 1:
                insf();
                break;
            case 2:
                inse();
                break;
            case 3:
                inspos();
                break;
            case 4:
                delf();
                break;
            case 5:
                dele();
                break;
            case 6:
                delpos();
                break;
            case 7:
                display();
                break;
            default:
                printf("exiting...\n");
                return 0;
        }
    }
}