#include <stdio.h>
void  selectionSort(int array[],int n){
    for(int i=0;i<n-1;i++){
        int max=array[i];
        int maxindex=i;
        for(int j=i;j<n;j++){
            if(array[j]>max){
                max=array[j];
                maxindex=j;
            }
        }
        int temp=array[i];
        array[i]=max;
        array[maxindex]=temp;
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
    selectionSort(array,n);
    return 0;
}