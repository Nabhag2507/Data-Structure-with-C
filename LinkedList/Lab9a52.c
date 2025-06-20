#include <stdio.h>
#include<stdlib.h>

void main () {
    int size,i;
    
    printf("Enter size of an array :");
    scanf("%d",&size);

    int *arr = (int *)malloc(sizeof(int)*size);

    for(int i=0;i<size;i++){
        printf("Enter element no %d :",(i+1));
        scanf("%d",(arr+i));
    }
    
    int max = *arr;
    for(int i=0;i<size;i++){
        if(*(arr+i) > max){
            max = *(arr+i);
        }
    }
    printf("%d",max);

    free(arr);
}