/*
#include <stdio.h>
#define MAX 10
int q[MAX];
int front=-1,rear=-1;
void enq(int ele){
    if(rear== MAX-1){
        printf("Queue Full\n");
    }
    else{
        if(front==-1 && rear==-1){
            front=0;
            q[++rear]=ele;
        } 
        else{
            q[++rear]=ele;
        }
    }
}
int deq(){
    int item;
    if(front==-1 || front>rear){
        return -1;
    }
    else{
        item= q[front++];
        return(item);

    }

}
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d",q[i]);
    }
    printf("\n");
}
void readq(){
    int n,e;
    printf("enter tot ele\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&e);
        enq(e);
    }
}
int main(){
    int max,temp;
    readq();
    max=deq();
    temp=max;
    while(temp!=-1){
        temp=deq();
        if(temp>max){
            max=temp;
        }
    }
    printf("max elem is %d",max);
}
*/
#include <stdio.h>
#define MAX 5
int q[MAX];
int front=-1,rear=-1;
void enq(int ele){
    if(((rear+1)%MAX)== front){
        printf("Queue Full\n");
    }
    else{
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
        return -1;
    }
    else{
        item= q[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%MAX;
        }
        return item;
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
void readq(){
    int n,e;
    printf("enter tot ele\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&e);
        enq(e);
    }
}
int main(){
    int max,temp;
    readq();
    max=deq();
    temp=max;
    while(temp!=-1){
        temp=deq();
        if(temp>max){
            max=temp;
        }
    }
    printf("max elem is %d",max);
}
