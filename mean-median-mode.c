#include <stdio.h>
void mean(int array[],int n){
    int sum=0;
    float mean;
    
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    mean=sum/n;
    printf("mean=%2f\n",mean);
}
void median(int array[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
    int a,b;
    int median;
    if(n%2==0){
        float median;
        a=array[(n/2)];
        b=array[(n/2)-1];
        median=(a+b)/2.0;
        
    }
    else{
        int median;
        median=array[n/2];
        
    }
    printf("median=%d\n",median);
}
void mode(int array[],int n){
    int mode=array[0];
    int max=1;
    int present=0;
    for(int i=0;i<n;i++){
        int element=array[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(array[j]==element){
                count++;
            }
        }
        if(count>max){
            max=count;
            mode=element;
            present=1;
        }
    }
    if(max>1){
        printf("mode=%d\n",mode);
    }
    else{
        printf("no mode element\n");
    }
}
int main(){
    int n,element,choice;
    printf("enter the no of ele\n");
    scanf("%d",&n);
    int array[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("1:Mean\n2:Median\n3:Mode\n4:Exit\n");
    printf("Enter Choice\n");
    scanf("%d",&choice);
    while (choice){
        
        if(choice==1){
            mean(array,n);
        }
        else if(choice==2){
            median(array,n);
        }
        else if(choice==3){
            mode(array,n);
        }
        else if(choice==4){
            printf("exiting....\n");
            return 0;
        }
        else {
            printf("invalid choice\n");
        }
        printf("Enter Choice\n");
        scanf("%d",&choice);
    }
    
}