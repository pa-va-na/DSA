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
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
    }
    else{
        struct node* temp=head;
        do{
            temp=temp->next;
        }while (temp->next!=head);
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }
    
}
void inse(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    printf("enter data to enter\t");
    scanf("%d",&newnode->data);
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
    }
    else{
        temp=head;
        
        do
        {
            temp=temp->next;
        }while (temp->next!=head);
        temp->next=newnode;
        newnode->next=head;
    }
}
void inspos(){
    int p;
    int pos=1;
    printf("enter pos\t");
    scanf("%d",&p);
    
    if(pos==0){
        insf();
        return;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    printf("enter data to enter\t");
    scanf("%d",&newnode->data);
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
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
   /* do{
        temp=temp->next;
    }while(temp->next!=head);
    free(head);
    head=head->next;
    temp->next=head;*/
    struct node* last;
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;     
    last->next = head;     
    free(temp);    
    
}
void dele(){
    struct node* temp;
    struct node* prev;
    temp=head;
    prev=temp;
    if(head->next==head){
        free(head);
        return;
    }
    while(prev->next->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
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
    if(head==NULL){
        printf("empty list\n");
        return;
    }
    do{
        
        printf("%d->",temp->data);
        temp=temp->next;
    }while (temp!=head);
    printf("\n");
}
int main(){
    int o;
    printf("CLL Operations \n1:Insert at front \t2:Insert at end\n3:Insert at any pos\t 4:Delete from front\n5:Delete from back\t 6:Delete from any pos\n7:Display\n");
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