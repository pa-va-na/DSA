//in descending order
#include <stdio.h>
void bubbleSort(int array[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(array[j]<array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
        printf("pass %d\t\t",i);
        for(int k=0;k<n;k++){
            printf("%d\t",array[k]);
        }
        printf("\n");
    }
    printf("final sorted list\n");
    for(int k=0;k<n;k++){
            printf("%d\t",array[k]);
        }
}
int main(){
    int n;
    printf("enter the no of ele\n");
    scanf("%d",&n);
    int array[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    bubbleSort(array,n);
    return 0;
}