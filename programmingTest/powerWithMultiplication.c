#include <stdio.h>

void main () {
    int base,power;

    printf("Enter base and power");
    scanf("%d %d",&base,&power);

    int ans = 1;
    for(int i=0;i<power;i++){
        ans *= base;
    }

    printf("%d",ans);
}