#include <stdio.h>
#include <math.h>

void main () {
    int n;
    
    printf("Enter any number :");
    scanf("%d",&n);

    int tempC = n,digits = 0;

    while(tempC > 0){
        tempC /= 10;
        digits++;
    }

    int newN = 0,rem = 0,temp = n;

    while(temp > 0){
        rem = temp%10;
        newN += pow(rem,digits);
        temp /= 10;
    }
    if(newN == n){
        printf("Number is armstrong ");
    }
    else{
        printf("Number is not armstrong ");
    }
}