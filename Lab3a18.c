#include <stdio.h>

void main () {
    int n,sum=0;

    printf("Enter any number :");
    scanf("%d",&n);

    for (int i=0;i<=n;i++){
        sum+=i;
    }
    printf("Your answer is %f",(sum/n*1.0));
}