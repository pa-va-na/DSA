#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int exp;
    struct  node* next;
};
struct node* p1;
struct node* p2;
struct node* mul;
void insertend(struct node** head,struct node* newnode){
    if(*head==NULL){
        newnode->next=NULL;
        *head=newnode;
        return;
    }
    else{
        struct node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}
void create(struct node** p){
    int n;
    int c,e;
    printf("enter no of terms\t");
    scanf("%d",&n);
    printf("enter coeff and exp in descending order\n");
    for(int i=0;i<n;i++){
        printf("term%d\t",i+1);
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d%d",&c,&e);
        newnode->coeff=c;
        newnode->exp=e;
        insertend(p,newnode);

    }
}

void display(struct node* head){
    struct node* temp=head;
    if(temp->next==NULL){
        printf("%dx^%d",temp->coeff,temp->exp);
        return;
    }
    while(temp->next!=NULL){
        printf("%dx^%d+ ",temp->coeff,temp->exp);
        temp=temp->next;
    }
    printf("%dx^%d ",temp->coeff,temp->exp);


}
void multiply(struct node* pol1,struct node* pol2){
    struct node* temp1=pol1;
    while(temp1!=NULL){
        struct node* temp2=pol2;
        while(temp2!=NULL){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            int co,ex;
            co=temp1->coeff*temp2->coeff;
            ex=temp1->exp+temp2->exp;
            newnode->coeff=co;
            newnode->exp=ex;
            insertend(&mul,newnode);
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    

}
void check(){
    struct node* temp=mul;
    while(temp!=NULL){
        struct node* tempnew=temp->next;
        struct node* prev=temp;
        while(tempnew!=NULL){
            if(temp->exp==tempnew->exp){
                temp->coeff+=tempnew->coeff;
                prev->next=tempnew->next;
                struct node* del=tempnew;
                tempnew=tempnew->next;
                free(del);
            }
            else{
                prev=tempnew;
                tempnew=tempnew->next;
            }
        }
        temp=temp->next;
    }
}
int main(){
    printf("polynomial1\n");
    create(&p1);
    printf("polynomial2\n");
    create(&p2);
    printf("poly1\t");
    display(p1);
    printf("\n");
    printf("poly2\t");
    display(p2);
    printf("\n");
    multiply(p1,p2);
    printf("result\t");
    check();
    display(mul);
    return 0;
}
