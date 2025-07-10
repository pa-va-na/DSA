#include <stdio.h>
void linearSearch(int array[],int n,int element){
    int found=0;
    for(int i=0;i<n;i++){
        if(array[i]==element){
            printf("element found at index %d\n",i);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("element not found\n");
    }
}
int main(){
    int n,element;
    printf("enter the no of ele\n");
    scanf("%d",&n);
    int array[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("Enter the element to search\n");
    scanf("%d",&element);
    linearSearch(array,n,element);
    return 0;
}