#include <stdio.h>
void printarray(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int a[], int n){
    int indexOfMin, temp;
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[indexOfMin] > a[j])
            {
                indexOfMin = j;
            }
            
        }
        temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
    }
    
}
int main(){
    int arr[] = {454, 23, 233, 78, 98};
    // int arr[] = {12, 54, 65, 7, 23, 9};
    // int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    printarray(arr, size);
    selectionSort(arr, size);
    printarray(arr, size);
    return 0;
}