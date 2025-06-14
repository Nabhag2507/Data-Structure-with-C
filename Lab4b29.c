#include <stdio.h>

void main () {
    int size1,size2;

    printf("Enter size of array 1:");
    scanf("%d",&size1);

    int arr1[size1];
    
    for (int i=0;i<size1;i++){
        printf("Enter element no %d :",(i+1));
        scanf("%d",&arr1[i]);
    }
    
    printf("Enter size of array 2:");
    scanf("%d",&size2);
    int arr2[size2];

    for (int i=0;i<size2;i++){
        printf("Enter element no %d :",(i+1));
        scanf("%d",&arr2[i]);
    }

    int nsize = size1+size2;

    int narr[nsize];
    for(int i=0;i<size1;i++){
        printf("%d ,",arr1[i]);
    }
    for(int i=0;i<size2;i++){
        printf("%d ,",arr2[i]);
    }
}