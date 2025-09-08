#include <stdio.h>

int LinearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

void main() {
    int size = 10;

    int arr[10] = {1,2,5,4,9,3,20,78,55,41};
    printf("Index found on %d",LinearSearch(arr,10,9));
    if(LinearSearch(arr,10,9) == -1){
        printf("Target not found");
    }
}
