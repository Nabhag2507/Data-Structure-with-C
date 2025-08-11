#include <stdio.h>
#include <string.h>
#define size 20

int top = -1;
char strans[size];

void push(char ch){
    if(top >= size){
        printf("Overflow");
    }
    else{
        strans[++top] = ch;
    }
}

int pop(){
    if(top == -1){
        printf("Underflow");
        return -1;
    }
    else{
        return strans[top--];
    }
}

int check(char str[]){
    for(int i = 0;i<strlen(str);i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            push(str[i]);
        }else{
            if(top == -1){
                return 0;
            }
            else if((str[i] == ')' && strans[top] == '(') ||
                    (str[i] == '}' && strans[top] == '{') ||
                    (str[i] == ']' && strans[top] == '[') ){
                        pop();
            }
            else{
                return 0;
            }
        }
    }
    if(top != -1){
        return 0;
    }

    return 1;
}

void main () {
    char str[] = "";

    printf("Enter any string :");
    scanf("%s",&str);

    printf("%d",check(str));
}