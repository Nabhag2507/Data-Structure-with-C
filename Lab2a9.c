#include <stdio.h>

void main () {
    int b,p;

    printf("Enter base :");
    scanf("%d",&b);
    printf("Enter power :");
    scanf("%d",&p);

    int ans = 1;
    for (int i=0;i<p;i++){
        ans = ans * b;
    }
    printf("%d",ans);
}