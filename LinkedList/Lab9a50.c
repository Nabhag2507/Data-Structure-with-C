// 50. WAP to get and print the array elements using Pointer.
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int size, i;

    printf("Enter size of an array :");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter element no %d :", (i + 1));
        scanf("%d", arr + i);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ,",*(arr+i));
    }
    free(arr);
}