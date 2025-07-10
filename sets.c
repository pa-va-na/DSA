#include <stdio.h>
void intersection(int set1[],int n,int set2[],int m){
    int intersection[n];
    int index=0;
    for(int i=0;i<n;i++){
        int value=set1[i];
        for(int j=0;j<m;j++){
            if(set2[j]==value){
                intersection[index]=value;
                index++;
            }
        }
    }
    printf("intersection :\t");
    printf("{\t");
     for(int k=0;k<index;k++){
            printf("%d\t",intersection[k]);
        }
    printf("}\n");

}
void unionSet(int set1[],int n,int set2[],int m){
    int unionSet[n+m];
    int index=0;
    for(int i=0;i<n;i++){
        unionSet[index]=set1[i];
        index++;
    }
    for(int j=0;j<m;j++){
        int found=0;
        int value=set2[j];
        for(int k=0;k<index;k++){
            if(unionSet[k]==value){
                found=1;
            }
        }
        if(found==0){
            unionSet[index]=value;
            index++;
        }
    }
        
    
    printf("union :\t");
    printf("{\t");
     for(int k=0;k<index;k++){
            printf("%d\t",unionSet[k]);
        }
    printf("}\n");
}
int main(){
    int n;
    printf("enter no of ele in set 1\n");
    scanf("%d",&n);
    int set1[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&set1[i]);
    }
    int m;
    printf("enter no of ele in set 2\n");
    scanf("%d",&m);
    int set2[m];
    printf("enter elements\n");
    for(int i=0;i<m;i++){
        scanf("%d",&set2[i]);
    }
    intersection(set1,n,set2,m);
    unionSet(set1,n,set2,m);
    return 0;
}