#include <stdio.h>
#include <string.h>

char str[100] = "abcbc";
char ans[100];

top = -1;
void push(char n){
    if(top >= strlen(str)-1){
        printf("overflow");
    }
    else{
        ans[++top] = n;
    }
}

int pop(){
    if(top == -1){
        printf("Underflow");
        return -1;
    }
    else{
        return ans[top--];
    }
}

void check(){
    int i=0,j=0;
    while (str[i] != '\0' && str[i] != 'c'){
        push(str[i++]);    
    }
    if(str[i] == '\0'){

    }
    else{
        i++;
        while (str[i] != '\0'){
            if(str[i] != pop()){
                printf("returned");
                return;
            }
            i++;   
        }
        if(top == -1){
            printf("Valid");
        }
        else{
            printf("invalid");
        }
    }

    while(1){
        if(str[j] == ans[j]){
            pop();
        }
        
    }
}

void main () {
    check();
}