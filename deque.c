#include <stdio.h>
#define MAX 10
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
void deq(){
    int item;
    if(front==-1 && rear==-1){
        printf("queue empty\n");
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
void enqf(){
    if(((rear+1)%MAX)== front){
        printf("Queue Full\n");
    }
    else{
        int ele;
        printf("enter element to enqueue\t");
        scanf("%d",&ele);
        if(front==0){
            q[MAX-1]=ele;
        }
        else{
            q[--front]=ele;
        }
    }
}
void deqr(){
    int item;
    if(front==-1 && rear==-1){
        printf("queue empty\n");
        
    }
    else{
        item=q[rear];
        if(rear==0){
            rear=MAX-1;
        }
        else{
            if(front==rear){
                front=-1;
                rear=-1;
            } 
            else{
                rear--;
            }
        }
        printf("dequeued element %d\n",item);
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
    int o,t;
    printf("Select \n 1:Input restricted queue\t2:Output restricted queue\n");
    scanf("%d",&t);
    if (t==1){
        printf("Input restricted queue\nOperation\n1:enqueue\t2:Dequeue(front)\t3:Dequeue(rear)\n4:Display\t5:Exit\n");
        while(1){
            printf("enter operation\t");
            scanf("%d",&o);
            switch(o){
                case 1:
                    enq();
                    break;
                case 2:
                    deq();
                    break;
                case 3:
                    deqr();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    printf("exiting..\n");
                    return 0;
                default:
                    printf("invalid input\n");
                    break;    
            }
        }
    }
    else if(t==2){
        printf("Output restricted queue\nOperation\n1:Enqueue(rear)\t2:Enqueue(front)\t3:Dequeue\n4:Display\t5:Exit\n");
        while(1){
            printf("enter operation\t");
            scanf("%d",&o);
            switch(o){
                case 1:
                    enq();
                    break;
                case 2:
                    enqf();
                    break;
                case 3:
                    deq();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    printf("exiting..\n");
                    return 0;
                default:
                    printf("invalid input\n");
                    break;    
            }
        }
    }
}