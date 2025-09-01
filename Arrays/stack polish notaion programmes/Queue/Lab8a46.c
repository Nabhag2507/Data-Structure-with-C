#include <stdio.h>

int queue[10];
int rear = -1,front = -1;

void enqueue(int info){
    if(front == -1){
        front = 0;
    }
    if(rear == 19){
        printf("Queue overflow");
    }
    else{
        queue[++rear] = info;
    }
}

int dequeue(){
    if(front ==-1 || front>rear){
        printf("Queue Underflow");
        return -1;
    }
    else{
        return queue[front++];
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

void main () {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    // printf("%d", dequeue());
    dequeue();

    display();
}