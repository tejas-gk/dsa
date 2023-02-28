#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 100
char stack[size];
int top=-1;
void push(char x){
    if(top==size-1)
        printf("Stack overflow");
    else
        stack[++top]=x;
}
char pop(){
    if(top==-1)
        printf("Stack underflow");
    else
        return stack[top--];
}
int priority(char x){
    // if(x=='(')
    //     return 0;
    // if(x=='+'||x=='-')
    //     return 1;
    // if(x=='*'||x=='/')
    //     return 2;
    // if(x=='^')
    //     return 3;
    switch(x){
        case '#' : return 0;
        case '(' : return 1;
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' : return 3;
        case '^' : return 4;
        default : printf("Invalid operator");
        exit(0);
    }
}

void main(){
    char infix[100],postfix[100],ch,x;
    int i = 0, k = 0, pr;
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0'){
        if(ch=='(')
            push(ch);
        else if(isalnum(ch))
            postfix[k++]=ch;
        else if(ch==')'){
            while(stack[top]!='('){
                postfix[k++]=pop();
                if(stack[top]=='#'){
                    printf("Invalid expression");
                    exit(0);
                }

            }  
            x=pop();
        }
        else{
            pr=priority(ch);
            if(ch=='^')
                pr++;
            while(priority(stack[top])>=pr)
                postfix[k++]=pop();
            push(ch);
        }
    }
    while(stack[top]!='#')
        postfix[k++]=pop();
    postfix[k]='\0';
    printf("The postfix expression is: %s",postfix);

}
// input : a+b*c-d/e
// output : abc*+de/-