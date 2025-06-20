#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *a = (int *)malloc(sizeof(int));
    float *b = (float *)malloc(sizeof(float));
    char *c = (char *)malloc(sizeof(char));

    if (a && b && c)
    {
        *a = 5;
        *b = 3.32;
        *c = 'd';
        printf("%d %f %c", *a, *b, *c);
    }
    else{
        printf("Memory not allocated :)");
    }
    free(a);
    free(b);
    free(c);
}