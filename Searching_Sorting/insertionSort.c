#include <stdio.h>

void insertionSort(int arr[]){
    int key,j;

    for(int i=0;i<10;i++){
        key = arr[i];
        j = i-1;
        while(j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}

void main () {
    int arr[10] = {10,2,5,4,9,3,20,78,55,41};

    insertionSort(arr);
}