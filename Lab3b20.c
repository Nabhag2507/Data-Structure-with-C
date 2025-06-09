#include <stdio.h>

void main () {
    int size,counter=0;

    printf("Enter size of an array :");
    scanf("%d",&size);
    int arr[size];

    for (int i=0;i<size;i++){
        printf("Enter element for index %d :",i);
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<size;i++){
        if(arr[i] == arr[i+1]){
            counter++;
        }
        // for (int j=0;j<size;j++){
        // } 
    }

    if (counter >= 1){
        printf("Array contains duplicate numbers");
    }
    else{
        printf("Array does not contains duplicate numbers");
    }
}