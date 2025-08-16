#include <stdio.h>
#define MAX 20
struct sparse{
    int row;
    int col;
    int val;
};
int main(){
    int m;
    printf("enter no of nonzero elemnts\n");
    scanf("%d",&m);
    struct sparse[m+1];
    
    printf("enter elements\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&sparse[i][j]);
        }
    }
    printf("Sparse Matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
                printf("%d\t",sparse[i][j]);
            
        }
        printf("\n");
    }
    int row=sparse[0][0];
    int col=sparse[0][1];
    int matrix[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        
    }
}