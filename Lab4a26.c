//  Write a program to insert a number in an array that is already sorted in an ascending order

#include <stdio.h>

void main()
{
    int size, n, in;

    printf("Enter size of an array :");
    scanf("%d", &size);

    int arr[(size + 1)];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element no %d :", (i + 1));
        scanf("%d", &arr[i]);
    }
    printf("Enter new number :");
    scanf("%d", &n);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= n && arr[i + 1] >= n)
        {
            in = (i + 1);
        }
    }

    for (int i = size; i >= in; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[in] = n;

    printf("Your new array: ");
    for (int i = 0; i <= size; i++)
    {
        printf("%d ,", arr[i]);
    }
}