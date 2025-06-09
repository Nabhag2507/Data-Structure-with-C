#include <stdio.h>

void main () {
    int n;
    
    printf("Enter any number :");
    scanf("%d",&n);

    for (int i=1;i<=n;i++){
        if(n%i == 0){
            printf("%d , ",i);
        }
    }
}