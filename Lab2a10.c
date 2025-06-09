#include <stdio.h>

void main () {
    int a;

    printf("Enter any number :");
    scanf("%d",&a);

    int temp = 0,rem;
    while(a!=0){
       rem = a % 10;
       a = a / 10;
       temp = temp*10 + rem;
    }
    printf("%d",temp);
}