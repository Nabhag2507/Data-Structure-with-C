//  prime number
#include <stdio.h>

void main () {
    int n,counter = 0;
    
    printf("Enter any number :");
    scanf("%d",&n);

    for (int i=1;i<=n;i++){
        if(n%i == 0){
            counter++;
        }
    }

    if(counter == 2){
        printf("Number is prime :)");
    }

    else{
        printf("Number is not prime :)");
    }
}