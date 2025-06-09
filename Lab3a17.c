#include <stdio.h>

void main () {
    int m,n,sum=0;

    printf("Enter any two numbers :");
    scanf("%d %d",&m,&n);

    int max = ((m>n) ? m :n);
    int min = ((m<n) ? m :n);

    for (int i=min;i<=max;i++){
        sum+=i;
    }
    printf("Sum of numbers between %d and %d is %d",min,max,sum);
}