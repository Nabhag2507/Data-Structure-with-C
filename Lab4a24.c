//  Write a program to insert a number at a given location in an array. 

#include <stdio.h>

void main () {
    int size,n,in;

    printf("Enter size of an array :");
    scanf("%d",&size);

    int arr[(size+1)];

    for (int i=0;i<size;i++){
        printf("Enter element no %d :",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("At what index do you want to enter number :");
    scanf("%d",&in);
    
    printf("Enter new number :");
    scanf("%d",&n);

    for (int i=size;i>=in;i--){
       arr[i+1]=arr[i];
    }
    
    arr[in]=n;

    printf("Your new array: ");
    for (int i=0;i<=size;i++){
        printf("%d ,",arr[i]);
    }
}