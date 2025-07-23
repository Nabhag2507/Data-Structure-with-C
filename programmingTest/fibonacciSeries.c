#include <stdio.h>

void main () {
    int n;
    
    printf("Enter number of elements");
    scanf("%d",&n);

    int arr[n];
    arr[0] = 0,arr[1] = 1;

    printf("0 , 1 , ");

    for(int i = 2;i<n-1;i++){
        arr[i] = arr[i-1]+arr[i-2];
        printf("%d , ",arr[i]);
    }
    arr[n] = arr[n-1]+arr[n-2];
    printf("%d",arr[n]);
}