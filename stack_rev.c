#include <stdio.h>
#define MAX 10
int top=-1;
char s[MAX];
char temp[MAX];
void push(char c){
    if (top==MAX-1){
        printf("Stack overflow");
    }
    else {
        temp[++top]=c;
    }
}
void pop(){
    if (top==-1){
        printf("Stack underflow");
    }
    else {
        char e= temp[top--];
        printf("%c",e) ;
    }
}
void display(){
    for (int i=0;i<=top;i++){
        printf("%c",temp[i]);
    }
    printf("\n");
}
int main() {
    printf("enter str\n");
    scanf("%s",s);
    int i=0;
    while(s[i]!='\0'){
        push(s[i]);
        i++;
    }
    while(top!=-1){
        pop();
    }
    
    return 0;
}