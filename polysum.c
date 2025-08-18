#include <stdio.h>
#define MAX 20
struct poly{
    int coef;
    int exp;
};
int main(){
    int n1;
    printf("enter no of terms in poly 1\t");
    scanf("%d",&n1);
    struct poly p1[n1];
    printf("enter poly in coef and exp in ascending order\n");
    for(int i=0;i<n1;i++){
        int c,e;
        scanf("%d%d",&c,&e);
        p1[i].coef=c;
        p1[i].exp=e;
    }
    int n2;
    printf("enter no of terms in poly 2\t");
    scanf("%d",&n2);
    struct poly p2[n2];
    printf("enter poly in coef and exp in ascending order\n");
    for(int i=0;i<n2;i++){
        int c,e;
        scanf("%d%d",&c,&e);
        p2[i].coef=c;
        p2[i].exp=e;
    }
    printf("polynomial-1\n");
    for(int i=0;i<n1;i++){
        printf("%dx^%d",p1[i].coef,p1[i].exp);
        if(i!=n1-1){
            printf("+");
        }
    }
    printf("\n");
    printf("polynomial-2\n");
    for(int i=0;i<n2;i++){
        printf("%dx^%d",p2[i].coef,p2[i].exp);
        if(i!=n2-1){
            printf("+");
        }
    }
    printf("\n");
    int i=0,j=0,k=0;
    struct poly res[20];
    while(i<n1 && j<n2){
        if(p1[i].exp == p2[j].exp){
            int sum;
            sum=p1[i].coef+p2[j].coef;
            res[k].coef=sum;
            res[k].exp=p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp>p2[j].exp){
            res[k]=p1[i];
            k++;
            i++;
        }
        else {
            res[k]=p2[j];
            k++;
            j++;
        }

    }
    while(i<n1){
        res[k]=p1[i];
        k++;
        i++;
    }
    while(j<n2){
        res[k]=p2[j];
        k++;
        j++;
    }
    /*for(int i=0;i<k;k++){
        int ex=
        for(int j=i;j<k;j++){

        }
    }*/
    printf("result\n");
    for(int i=0;i<k;i++){
        printf("%dx^%d",res[i].coef,res[i].exp);
        if(i!=k-1){
            printf("+");
        }
    }
    printf("\n");
    return 0;
}