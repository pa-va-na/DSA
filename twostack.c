#include <stdio.h>
#define MAX 10
int top1=-1;
int top2=MAX;
int array[MAX];
void push1(){
    if(top1+1==top2){
        printf("Stack overflow\n");
    }
    else{
        int n;
        printf("enter ele to push to st1 \n");
        scanf("%d",&n);
        array[++top1]=n;
    }
}
void push2(){
    if(top1+1==top2){
        printf("Stack overflow\n");
    }
    else{
        int n;
        printf("enter ele to push to st2\n");
        scanf("%d",&n);
        array[--top2]=n;
    }
}
int pop1(){
    if(top1==-1){
        printf("Stack1 underflow\n");
        
    }
    else{
        return array[top1--];
    }
}
int pop2(){
    if(top2==MAX){
        printf("Stack2 underflow\n");
        
    }
    else{
        return array[top2++];
    }
}
void display1(){
    printf("stack1\t");
    for(int i=0;i<=top1;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void display2(){
    printf("stack2\t");
    for(int i=MAX-1;i>=top2;i--){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(){
    int o;
    int item1,item2;
    printf("MENU\n1:push to stack1\t2:push to stack2\n3:pop from stack1\t4:pop from stack2\n5:display s1\t6:display s2\n7:Exit\n");
    while(1){
        printf("enter operation\n");
        scanf("%d",&o);
        switch(o){
            case 1:
                push1();
                break;
            case 2:
                push2();
                break;
            case 3:
                
                item1=pop1();
                if(item1){
                    printf("popped element:%d\n",item1);
                }
                break;
            case 4:
                item2=pop2();
                if (item2){
                    printf("popped element:%d\n",item2);
                }
                break;
            case 5:
                display1();
                break;
            case 6:
                display2();
                break;
            case 7:
            printf("exiting..\n");
                return 0;
            default:
                printf("invalid operation\n");
                break;
            
        }
    }
}