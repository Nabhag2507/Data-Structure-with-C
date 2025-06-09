#include <stdio.h>

void main(){
    int size,min=0,max=0,mi=0,mx=0;

    printf("Enter size of an array :");
    scanf("%d",&size);
    int arr[size];

    for (int i=0;i<size;i++){
        printf("Enter element for index %d :",i);
        scanf("%d",&arr[i]);
    }

    max = arr[0];
    min = arr[0];
    for (int i=0;i<size;i++){
        if (arr[i]<min){
            min = arr[i];
            mi=i;
        }
        if (arr[i]>max){
            max = arr[i];
            mx=i;
        }
    }

    printf("Smallest number is %d on index %d and ",min,mi);
    printf("Largest number is %d on index %d",max,mx);
}