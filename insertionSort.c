#include <stdio.h>
void printarray(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int insertionSort(int a[], int n){
    int j, key;
    for (int i = 1; i <= n-1; i++)
    {
        key = a[i];
        j = i-1;
        while (j>= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    // int arr[] = {454, 23, 233, 78, 98};
    int arr[] = {12, 54, 65, 7, 23, 9};
    // int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    printarray(arr, size);
    insertionSort(arr, size);
    printarray(arr, size);
    return 0;
}