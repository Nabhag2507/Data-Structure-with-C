#include <stdio.h>

void main () {
    int size = 10;

    int arr[10] = {1,2,3,14,19,23,30,52,55,91};
    int start = 0,end = 9,target = 55,flag = 1;

    while(start<=end){
        int mid = (start + end) / 2;
        if(arr[mid] == target){
            printf("index found on %d",mid);
            flag = 0;
            break;
        }else if(arr[mid] < target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    if(flag == 1){
        printf("Index not found");
    }
}