#include <stdio.h>

void main () {
    int n;
    
    printf("Enter any number :");
    scanf("%d",&n);

    for(int i=1;i<n-1;i++){
        if(n%i == 0){
            printf("%d , ",i);
        }
    }
    printf("%d",n);
}