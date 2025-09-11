#include <stdio.h>
#define m 10
int hset[m];

void init(){
    for(int i=0;i<m;i++){
        hset[i] = -1;
    }
}

int f(int key){
    return key%m;
}

void add(int key){
    int index = f(key);    
    if(hset[index] == -1){
        hset[index] = key;
        return;
    }
    
    int i = (index + 1) % m;
    while(i != index){
        if(hset[i] == -1){
            hset[i] = key;
            return;
        }
        i = (i + 1) % m;
    }
    printf("Hash Set is full!\n");
}

void contains(int key){
    int index = f(key);
    
    if(hset[index] == key){
        printf("Found at index %d\n", index);
        return;
    }
    
    int i = (index + 1) % m;
    while(i != index && hset[i] != -1){
        if(hset[i] == key){
            printf("Found at index %d\n", i);
            return;
        }
        i = (i + 1) % m;
    }
    printf("Not found\n");
}

void display(){
    printf("Hash Set: ");
    for(int i = 0; i < m; i++){
        printf("%d ", hset[i]);
    }
    printf("\n");
}

void main(){
    init();
    
    add(5);
    add(15);
    add(25);
    display();
    
    contains(15);
    contains(10);
}