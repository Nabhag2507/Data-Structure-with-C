#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int stack[100];
int top = -1;
void push(int c){
    stack[++top] = c;
}

int pop(){
    return stack[top--];
}

void evaluate_postfix(char postfix[]){
    int i;
    for(i=0; i<strlen(postfix);i++){
        if(isdigit(postfix[i]))
            push(postfix[i] - '0');
        else{
            int operand2 = pop();
            int operand1 = pop();
            switch(postfix[i]){
                case '+':
                push(operand1 + operand2);
                break;
                case '-':
                push(operand1 - operand2);
                break;
                case '*':
                push(operand1 * operand2);
                break;
                case '/':
                push(operand1 / operand2);
                break;
                case '^':
                push(pow(operand1, operand2));
            }
        }
    }
    
}

void main(){
    char postfix[100];
    printf("Enter a posfix expression :");
    scanf("%s",postfix);
    evaluate_postfix(postfix);
    printf("Answer : %d",pop());
}