#include <stdio.h>
#define MAX 10
int sorted_stack[MAX];
int input_stack[MAX];
int top=-1;
int topnew=-1;

void push(int s[],int *top,int val){
    if(*top==MAX-1){
        printf("Stack Overflow \n -------------\n");
    }
    else {
        s[++ *top]=val;
    }
}
int pop(int s[],int *top){
    if (*top==-1){
        printf("Stack Underflow\n--------------\n");
        return -1;
    }
    else {
        int item=s[(*top) --];
        return item;
    }
    
}
int peek(int s[],int *top){
    if(*top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        return s[*top];
    }    
}
void stack_read(int no){
    int val;
    printf("enter values\n");
    for(int i=0;i<no;i++){
        scanf("%d",&val);
        push(input_stack,&top,val);
    }
} 
void sort(){
    while(top!=-1){
        int temp=pop(input_stack,&top);
        printf("temp is now %d\n",temp);
        if (topnew==-1){
            push(sorted_stack,&topnew,temp);
        }
        else{
            while(topnew!=-1 && temp<peek(sorted_stack,&topnew)){
                int del=pop(sorted_stack,&topnew);
                push(input_stack,&top,del);
            }
            
            push(sorted_stack,&topnew,temp);
        }
    }
}
void display(){
    for(int i=0;i<=topnew;i++){
        printf("%d\t",sorted_stack[i]);
    }
}
int main(){
    // int no,val;
    //printf("enter total element\n");
    //scanf("%d",&no);
    //int stack[no];
    //stack_read(no);
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    printf("enter ele\n");
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        push(input_stack,&top,val);
    }
    sort();
    display();
    return 0;

}