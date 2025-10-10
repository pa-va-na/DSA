#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int exp;
    struct  node* next;
};
struct node* p1;
struct node* p2;
struct node* sum;
void create(struct node** p,int n){
    int c,e;
    printf("enter coeff and exp in descending order\n");
    struct node* temp=*p;
    
    for(int i=0;i<n;i++){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        printf("term%d\t",i+1);
        scanf("%d%d",&c,&e);
        newnode->coeff=c;
        newnode->exp=e;
        if(*p==NULL){
            newnode->next=NULL;
            *p=newnode;
        }
        else{
            temp=*p;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=NULL;
        }
        }
}
void display(struct node* head){
   
    struct node* temp=head;
    while(temp!=NULL){
        printf("%dx^%d ",temp->coeff,temp->exp);
        temp=temp->next;
    }
    printf("\n");
}
void insertend(struct node** head,struct node* newnode){
    if(*head==NULL){
        newnode->next=NULL;
        *head=newnode;
        return;
    }
    struct node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    
}
void add(struct node* p1,struct node* p2,int n1,int n2){
    while(p1!=NULL &&p2!=NULL){
        if(p1->exp>p2->exp){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=p1->coeff;
            newnode->exp=p1->exp;
            insertend(&sum,newnode);
            p1=p1->next;
        }
        else if(p2->exp>p1->exp){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=p2->coeff;
            newnode->exp=p2->exp;
            insertend(&sum,newnode);
            p2=p2->next;
        }
        else{
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=p1->coeff+p2->coeff;
            newnode->exp=p1->exp;
            insertend(&sum,newnode);
            p2=p2->next;
            p1=p1->next;
        }
        
    }
    while(p1!=NULL){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=p1->coeff;
            newnode->exp=p1->exp;
            insertend(&sum,newnode);
            p1=p1->next;
        }
        while(p2!=NULL){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=p2->coeff;
            newnode->exp=p2->exp;
            insertend(&sum,newnode);
            p2=p2->next;
        }
}
int main(){
    int n1,n2;
    printf("enter total no of terms in p1\n");
    scanf("%d",&n1);
    create(&p1,n1);
    printf("enter total no of terms in p2\n");
    scanf("%d",&n2);
    create(&p2,n2);
    printf("poly1\t");
    display(p1);
    printf("poly2\t");
    display(p2);
    add(p1,p2,n1,n2);
    printf("sum\t");
    display(sum);
}