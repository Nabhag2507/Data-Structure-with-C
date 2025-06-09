#include <stdio.h>

void main () {
    int a,temp=1;

    printf("Enter a number: ");
    scanf("%d",&a);

    for (int i=1; i<=a; i++){
        temp *= i;
    }

    printf("your answer is %d",temp);
}