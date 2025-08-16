#include <stdio.h>
#define MAX 5
int q[MAX];
int front=-1,rear=-1;
void enq(){
    if(((rear+1)%MAX)== front){
        printf("Queue Full\n");
    }
    else{
        int ele;
        printf("enter element to enqueue\t");
        scanf("%d",&ele);
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        } 
        else{
            rear=(rear+1)%MAX;
        }
        q[rear]=ele;
    }
}
int deq(){
    int item;
    if(front==-1 && rear==-1){
        printf("queue empty\n");
        return -1;
    }
    else{
        item= q[front];
        printf("dequeued element %d\n",item);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%MAX;
        }
    }

}
void display(){
    if(front==-1 && rear==-1){
        printf("queue empty\n");
    }
    else {
        if(front<rear){
            for(int i=front;i<=rear;i++){
                printf("%d\t",q[i]);
            }
            printf("\n");
        }
        else{
            int i=front;
            while(i<=MAX){
                printf("%d\t",q[i]);
                i++;
            }
            for(int j=0;j<=rear;j++){
                printf("%d\t",q[j]);
            }
            printf("\n");
        }
    }
}
int main(){
    int o;
    int item;
    printf("operations\n1:Enqueue\t2:Dequeue\n3:Display\t4:exit\n");
    while (1){
       printf("enter operation\n");
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
        case 4:
            printf("exiting..\n");
            return 0;
        default:
            printf("invalid operation\n");
            break;
       }
    }
    
}