#include <stdio.h>

void main () {
    int size,nn,rn;

    printf("Enter size of an array :");
    scanf("%d",&size);
    int arr[size];
    
    for (int i=0;i<size;i++){
        printf("Enter element for index %d :",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter any number you want to replace :");
    scanf("%d",&rn);

    printf("Enter any number you want to add :");
    scanf("%d",&nn);

    printf("Before array : \n");
    for (int i=0;i<size;i++){
        printf("%d ,",arr[i]);
    }

    printf("After array :\n");
    for (int i=0;i<size;i++){
        if(arr[i] == rn){
            arr[i] = nn;
            break;
        }
    }    
    for (int i=0;i<size;i++){
        printf("%d ,",arr[i]);
    }
}