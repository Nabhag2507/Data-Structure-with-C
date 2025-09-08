#include <stdio.h>
#define SIZE 10

void printList(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int swapped = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}

int main() {
    int arr[SIZE] = {10,2,5,4,9,3,20,78,55,41};

    bubbleSort(arr, SIZE);
    printList(arr, SIZE);

    return 0;
}