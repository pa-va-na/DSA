#include <stdio.h>
void insertionSort(int array[],int n){
    for(int i=1;i<n;i++){
        int temp=array[i];
        int j=i-1;
        while(j>=0 && array[j]<temp ){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
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
    insertionSort(array,n);
    return 0;
}