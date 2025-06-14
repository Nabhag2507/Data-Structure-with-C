#include <stdio.h>

void main () {
    int size,in;

    printf("Enter size of an array :");
    scanf("%d",&size);

    int arr[size];

    for (int i=0;i<size;i++){
        printf("Enter element no %d :",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("At what index do you want to remove :");
    scanf("%d",&in);
   
    for (int i=in;i<(size-1);i++){
       arr[i]=arr[i+1];
    }

    printf("Your new array: ");
    for (int i=0;i<(size-1);i++){
        printf("%d ,",arr[i]);
    }
}