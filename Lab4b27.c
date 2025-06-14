#include <stdio.h>

void main () {
    int size,in=-1,n=0;

    printf("Enter size of an array :");
    scanf("%d",&size);

    int arr[size];

    for (int i=0;i<size;i++){
        printf("Enter element no %d :",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("Enter number you want to delete :");
    scanf("%d",&n);
   
    for (int i=0;i<size;i++){
        if(arr[i] == n){
            in = i;
            break;
        }
    }
    if(in == -1){
        printf("Number not found");
    }

    for (int i=in;i<(size-1);i++){
       arr[i]=arr[i+1];
    }

    printf("Your new array: ");
    for (int i=0;i<(size-1);i++){
        printf("%d ,",arr[i]);
    }
}