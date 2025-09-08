#include <stdio.h>

void selectionSort(int arr[]){
    for(int i=0;i<10-1;i++){
        int minIndex = i;
        for(int j = i+1;j<10;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}

void main () {
    int arr[10] = {1,2,5,4,9,3,20,78,55,41};

    selectionSort(arr);
}