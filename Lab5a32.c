// Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
// and store result in third matrix and print it.

#include <stdio.h>

void main () {
    int m1row,m1column;

    printf("Enter size of matrix :");
    scanf("%d",&m1row);
    scanf("%d",&m1column);
    int arr1[m1row][m1column];

    printf("Enter first matrix 1:\n");
    for(int i=0;i<m1row;i++){
        for(int j=0;j<m1column;j++){
            printf("Enter element for index %d %d :",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    int m2row,m2column;

    printf("Enter size of matrix 2:");
    scanf("%d",&m2row);
    scanf("%d",&m2column);
    int arr2[m2row][m2column];

    printf("Enter first matrix :\n");
    for(int i=0;i<m2row;i++){
        for(int j=0;j<m2column;j++){
            printf("Enter element for index %d %d :",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    int ansMatrix[m1row][m2column];

    for(int i=0;i<m1row;i++){
        for (int j=0;j<m2column;j++){
            ansMatrix[i][j] =0;
            for(int k=0;k<m1column;k++){
              ansMatrix[i][j] += arr1[i][k]*arr2[k][j];  
            }
        }
        printf("\n");
    }

    for(int i=0;i<m1row;i++){
        for (int j=0;j<m2column;j++){
            printf("%d ",ansMatrix[i][j]);    
        }
        printf("\n");
    }
}