#include <stdio.h>
void printarray(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int bubbleSort(int a[], int n){
    int temp, isSorted;
    for (int i = 0; i < n-1; i++)
    {   isSorted = 1;
        printf("Pass no. %d\n", i+1);
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            return -1;
        }
    }
}
int main(){
    int arr[] = {454, 23, 233, 78, 98};
    // int arr[] = {12, 54, 65, 7, 23, 9};
    // int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    printarray(arr, size);
    bubbleSort(arr, size);
    printarray(arr, size);
    return 0;
}