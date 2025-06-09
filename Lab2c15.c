#include <stdio.h>
#include <math.h>

void main () {
    int n,counter=0,an=0,temp=0,rem=0;
    printf("Enter any number :");
    scanf("%d",&n);

    int n1=n,n2=n;
    while(n1>0){
        n1/=10;
        counter++;
    }

    while(n2>0){
        rem = n2%10;
        an += pow(rem,counter);
        n2/=10;
    }
    if(an == n){
        printf("Number is armstrong");
    }
    else{
        printf("Number is not armstrong");
    }

}

// for(int i=0;i<1000;i++){

// }