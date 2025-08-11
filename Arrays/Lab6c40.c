//vowel anxiety problem
#include <stdio.h>
#define size 20

int top = -1;
int revtop = -1;
char str[size];
char revstr[size];

void push(char ch){
    if(top >= size){
        printf("overflow");
    }
    else{
        str[++top] = ch;
    }
}
void pushRev(char ch){
    if(top >= size){
        printf("overflow");
    }
    else{
        str[++top] = ch;
    }
}

char pop(){
    if(top == -1){
        printf("underflow");
        return '\0';
    }
    else{
        return str[top--];
    }
}

void reverseStack(){
    int temp = top;
    while(temp != -1){
        pushRev(pop());
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty");
    }else{
        for(int i = top;i>=0;i--){
            printf("%c ",str[i]);
        }
    }
}
void displayRev(){
    if(revtop == -1){
        printf("Stack is empty");
    }else{
        for(int i = revtop;i>=0;i--){
            printf("%c ",str[i]);
        }
    }
}


void main () {
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    push('f');

    reverseStack();
    printf("before\n");
    display();
    printf("after\n");
    displayRev();
}