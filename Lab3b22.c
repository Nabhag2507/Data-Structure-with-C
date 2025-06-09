#include <stdio.h>

void main () {
    int n;

    printf("Enter any number :");
    scanf("%d",&n);

    int fn=1;
    for (int i=1;i<n;i++){
        for (int j=1;j<i;){
            printf("%d",j);
            j+=fn;
        }
        printf("\n");
    }
}