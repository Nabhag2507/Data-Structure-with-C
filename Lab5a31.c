// Read two 2x2 matrices and perform addition of matrices into third matrix and 
// print it 

#include <stdio.h>

void main () {
    int row,column;

    printf("Enter size of matrix :");
    scanf("%d",&row);
    scanf("%d",&column);
    int arr1[row][column];
    int arr2[row][column];

    printf("Enter first matrix :\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("Enter element for index %d %d :",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }

    printf("Enter second matrix :\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("Enter element for index %d %d :",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }

    printf("Your final addition is :\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%d ",(arr1[i][j] + arr2[i][j]));
        }
        printf("\n");
    }
}