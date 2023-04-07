#include<stdio.h>
#include<ctype.h>
#include<math.h>
int stack[100],top=-1;
void push(int x){
    stack[++top]=x;
}
void main(){
    char postfix[100], ch;
    int i=0,op1,op2;
    printf("Enter the postfix expression: ");
    scanf("%s",postfix); // get the expression
    while((ch=postfix[i++])!='\0'){ // repeat until the end of the expression
        if(isalpha(ch)){ // check for alphabets
            printf("invalid expression");
            return;
        }
        if(isdigit(ch)) // check for digits
            push(ch-'0'); // push the digit into the stack
        else{
            op2=stack[top--]; // get the top element of the stack
            op1=stack[top--]; // get the next element of the stack
            switch(ch){ // check the operator
                case '+': push(op1+op2); // add the two elements and push the result into the stack
                    break;
                case '-': push(op1-op2); // subtract the two elements and push the result into the stack
                    break;
                case '*': push(op1*op2); // multiply the two elements and push the result into the stack
                    break;
                case '/': push(op1/op2); // divide the two elements and push the result into the stack
                    break;
                case '^': push(pow(op1,op2)); // find the power of the two elements and push the result into the stack
                    break;
            }
        }
    }
    if(top==0) // check if the stack has only one element
        printf("The result is: %d",stack[top--]); // print the result
    else
        printf("Invalid expression"); // print error message
}

// input: 23+4*5-6/2^3
// output: 23+4*5-6/2^3 = 23+20-6/8 = 43-6/8 = 43-0 = 43