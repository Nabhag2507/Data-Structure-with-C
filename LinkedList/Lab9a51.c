// 50. WAP to get and print the array elements using Pointer. 
#include <stdio.h>
#include<stdlib.h>

void main () {
    int n,i,counter=0;

    printf("How many numbers do you want to enter :");
    scanf("%d",&n);
  
    int *arr = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        printf("Emter element no %d :",(i+1));
        scanf("%d",(arr+i));
        counter += *(arr+i);
    }

    printf("%d",counter);
}