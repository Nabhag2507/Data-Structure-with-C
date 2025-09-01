#include <stdio.h>
#define size 20
int rear = -1,front = -1;

struct queue{
    int info;
    int priority;
};

struct queue Q[size];

void enqueue(int info,int priority){
    if(front == -1){
        front = 0;
    }
    if(rear == 19){
        printf("Queue overflow");
    }
    else{
        Q[++rear].info = info;
        Q[rear].priority = priority;
    }
}

int dequeue(){
    if(front == rear){
        return Q[front].info;
    }
    int maxPr = 0;
    for(int i=0;i<=rear;i++){
        if(Q[i].priority > Q[maxPr].priority)
            maxPr = i;
    }
    int item = Q[maxPr].info;
    for(int i=maxPr;i<rear;i++){
        Q[i] = Q[i+1];
    }
    rear--;
    return item;
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",Q[i].info);
    }
}

void main () {
    enqueue(10,1);
    enqueue(20,5);
    enqueue(30,10);
    enqueue(40,10);
    enqueue(50,8);
    dequeue();

    display();
}