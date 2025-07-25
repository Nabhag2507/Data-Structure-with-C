#include <stdio.h>
#define size 10

int top = -1;
int arr[size];

void push(int arr[],int n){
    if(top >= size){
        printf("overflow");
    }
    else{
        arr[++top] = n;
    }
}

int pop(int arr[]){
    if(top == -1){
        printf("underflow");
        return -1;
    }else{
        return arr[top--];
    }
}

int peep(int index){
    if(top == -1){
        printf("Underflow");
        return -1;
    }
    else if(top-index+1 < 0){
        printf("Overflow");
        return -1;
    }
    else{
        return arr[top-index+1];
    }
}

void change(int index, int value){
    if(top == -1){
        printf("Underflow");    
    }
    else if(top-index+1 < 0){
        printf("Overflow");
    }
    else{
        arr[top-index+1] = value;
    }
}

void display(int arr[]){
    if(top == -1){
        printf("Stack is empty");
    }else{
        for(int i = top;i>=0;i--){
            printf("%d ",arr[i]);
        }
    }
}

void main () {
    push(arr,1);
    push(arr,2);
    push(arr,3);
    push(arr,4);
    push(arr,5);
    push(arr,6);

    printf("Original array:\n");
    display(arr);
    
    printf("\nArray after pop :\n");
    pop(arr);
    display(arr);

    printf("\nPeeped element\n");
    printf("%d",peep(3));

    printf("\nafter changing any element :\n");
    change(3,10);
    display(arr);
}