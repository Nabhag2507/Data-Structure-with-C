#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 20

int top = -1;
char str[size];

void push(char ch){
    if(top >= size){
        printf("overflow");
    }
    else{
        str[++top] = ch;
    }
}

int pop(){
    if(top == -1){
        printf("underflow");
    }
    else{
        return str[top--];
    }
}

void check(char strans[]){
    for(int i=0;i<strlen(strans);i++){
        if(isalpha(strans[i])){
            push(strans[i]);
        }else if(strans[i] == '*' && top != -1){
            pop();
        }
    }
    for(int i=0;i<=top;i++){
        printf("%c",str[i]);
    }
}

void main () {
    char str[] = "";

    printf("Enter any string :");
    scanf("%s",&str);

    check(str);
}