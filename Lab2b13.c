#include <stdio.h>

void main()
{
    int sn, en;

    printf("Enter start number :");
    scanf("%d", &sn);

    printf("Enter end number :");
    scanf("%d", &en);

    for (int i = sn; i <= en; i++)
    {
        int counter =0,j;
        for (j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                counter++;
            }
        }
        if (counter == 2){
            printf("%d ,",i);
        }
    }
}