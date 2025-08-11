#include<stdio.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

int stack_precedence(char c){
    if(c == '+' || c == '-')
        return 2;
    else if(c == '*' || c == '/')
        return 4;   
    else if(c == '^')
        return 5;
    else if(c == '(')
        return 0; 
    else
        return 8; 

}

int input_precedence(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 3;   
    else if(c == '^')
        return 6;
    else if(c == '(')
        return 9;
    else if(c == ')')
        return 0;
    else    
        return 7;   

}

int r(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c =='^')
        return -1;
    else
        return 1;
}

void revpol(char infix[]){
    int i = 0;
    char postfix[100];
    int rank = 0;
    int j = 0;
    push('(');
    while(i != strlen(infix)){
        char next = infix[i];
        if(top < 0){
            printf("Invalid Expression.");
            return;
        }
        while(stack_precedence(stack[top]) > input_precedence(next))
        {
            char temp = pop();
            postfix[j++] = temp;
            rank = rank + r(temp);
            if(rank < 1){
                printf("Invalid Expression");
                return;
            }
        }

        if(stack_precedence(stack[top]) != input_precedence(next)){
            push(next);
        }
        else{
            char temp = pop();
        }
        i++;
    }
    postfix[j] = '\0';
    if(top!=-1 || rank != 1)
        printf("Invalid");
    else{
        printf("%s", postfix);
    }
}  

void main(){
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    strcat(infix,")");
    // printf("Postfix expression is: %s ",infix);
    revpol(infix);
}