#include <stdio.h>

void main () {
    int base,power;

    printf("Enter base and power");
    scanf("%d %d",&base,&power);

    int ans = 0;
    for(int i=0;i<=power;i++){
        for(int j=0;j<=base;j++){
            ans += base;
        }
    }

    printf("%d",ans);
}