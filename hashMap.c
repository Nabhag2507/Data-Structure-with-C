#include <stdio.h>
#define m 10

struct pair {
    int key;
    int value;
};

struct pair hmap[m];

void init() {
    for (int i = 0; i < m; i++) {
        hmap[i].key = -1;
    }
}

int hash(int key) {
    return key % m;
}

void put(int key, int value) {
    int idx = hash(key);

    if (hmap[idx].key == -1 || hmap[idx].key == key) {
        hmap[idx].key = key;
        hmap[idx].value = value;
        return;
    }

    int i = (idx + 1) % m;
    while (i != idx) {
        if (hmap[i].key == -1 || hmap[i].key == key) {
            hmap[i].key = key;
            hmap[i].value = value;
            return;
        }
        i = (i + 1) % m;
    }
    printf("HashMap is full!\n");
}

void get(int key) {
    int idx = hash(key);
    if (hmap[idx].key == key) {
        printf("Value at key %d: %d\n", key, hmap[idx].value);
        return;
    }
    int i = (idx + 1) % m;
    while (i != idx && hmap[i].key != -1) {
        if (hmap[i].key == key) {
            printf("Value at key %d: %d\n", key, hmap[i].value);
            return;
        }
        i = (i + 1) % m;
    }
    printf("Key %d not found\n", key);
}

void display() {
    printf("HashMap:\n");
    for (int i = 0; i < m; i++) {
        if (hmap[i].key != -1)
            printf("[%d] = (%d, %d)  \n", i, hmap[i].key, hmap[i].value);
        else
            printf("[%d] = (empty)  \n", i);
    }
    printf("\n");
}

int main() {
    init();

    put(1, 100);
    put(11, 1100);
    put(21, 2100);
    display();

    get(11);
    get(2);

    return 0;
}