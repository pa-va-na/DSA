#include <stdio.h>
#include <string.h>
#define MAX 20
int top=-1;
int c=0;
char stack[MAX];
char e[MAX];
void push(char elem){
    stack[++top]=elem;
}
char pop(){
    return stack[top--];
}
char topval(){
    return stack[top];
}
char readsymbol(){
    return e[c++];
}
int operator(int it){
    if(it=='+'||it=='-'||it=='*'||it=='/'||it=='^'||it=='('){
        return 1;
    }
    else 
    return -1;
}
int precedence(char i){
    if(i=='+'||i=='-'){
        return 1;
    }
    else if(i=='*'||i=='/'){
        return 2;
    }
    else if(i=='^'){
        return 3;
    }
    else if(i=='('){
        return 0;
    }
    else if(i==')'){
        return 4;
    }
    else {
        return -1;
    }
}
int main(){
    printf("enter infix expression\n");
    scanf("%s",e);
    push('#');
    int count=0;
    while(count<strlen(e)){
        int p;
        char k,ele;
        char item;
        item=readsymbol();
        switch(item){
            
            case ')':
                while(topval()!='('){
                    int ele=pop();
                    printf("%c",ele);
                }
                //k=pop();
                break;
            case '(':
                push(item);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            
                p=precedence(item);
                if(p > precedence(topval())){
                    push(item);
                }
                else{
                    while(p <=precedence(topval())&&topval()!='#'){
                        ele=pop();
                        printf("%c",ele);
                    }
                    push(item);
                }
                break;
            default:
                printf("%c",item);
                break;
            
        }
        
        count++;
    }
    if(topval()!='#'){
            while(topval()!='#'){
                char y;
                y=pop();
                if(y!='(')
                printf("%c",y);
            }
        }
}