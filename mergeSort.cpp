#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high){
    int i, j, k;
    int B[high+1];
    i = low;
    j = mid+1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high){
    if (low < high)
    {
        int mid = (low + high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
    
}
int main(){
    int arr[] = {12, 5, 7, 64, 77, 84};
    int size = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = size - 1;
    mergeSort(arr, low, high);
    printArray(arr, size);
    return 0;
}