#include <stdio.h>

void main(){
    int size;

    printf("Enter size of an array :");
    scanf("%d",&size);
    int arr[size];

    for (int i=0;i<size;i++){
        printf("Enter element for index %d :",i);
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<size;i++){
        printf("%d \n",arr[i]);
    }

}