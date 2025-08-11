#include <stdio.h>
#define size 20

int top = -1;
int arr[size][2];

void push(int start, int end) {
    if (top >= size - 1) {
        printf("Overflow\n");
    } else {
        arr[++top][0] = start;
        arr[top][1] = end;
    }
}

void mergeIntervals(int matrix[][2],int rows){
    push(matrix[0][0],matrix[0][1]);
    for (int i = 1; i < rows; i++) {
        int lastStart = arr[top][0];
        int lastEnd = arr[top][1];

        if (matrix[i][0] <= lastEnd) {
            if (matrix[i][1] > lastEnd) {
                arr[top][1] = matrix[i][1];
            }
        } else {
            push(matrix[i][0], matrix[i][1]);
        }
    }
}

void main () {
    int rows;
    printf("Enter rows of 2d matrix :");
    scanf("%d",&rows);

    int matrix[rows][2];

    for(int i=0;i<rows;i++){
        for(int j=0;j<2;j++){
            printf("Enter element no %d %d :",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }

    for(int i=0;i<rows-1;i++){
        for(int j=i+1;j<rows;j++){
            if(matrix[j][0]<matrix[i][0]){
                int temp0 = matrix[i][0];
                int temp1 = matrix[i][1];
                matrix[i][0] = matrix[j][0];
                matrix[i][1] = matrix[j][1];
                matrix[j][0] = temp0;
                matrix[j][1] = temp1;
            }
        }
    }

    mergeIntervals(matrix,rows);
    for (int i = 0; i <= top; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
}