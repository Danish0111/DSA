#include <iostream>
using namespace std;

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void insertion(int arr[], int *size, int index, int value, int capacity){

    if (index > capacity)
    {
        cout<<"you exceded the capacity of array"<<endl;
    }
    if (index >= *size)
    {
        cout<<"you exceded the size of array"<<endl;
    }
    
    if (index < *size)
    {
        for (int i = *size; i >= index; i--)
        {
            arr[i+1] = arr[i];
        }
        (*size)++;
        arr[index] = value;
    }
}

int main(){
    int size = 5, capacity = 100, index, value;
    int arr[capacity] = {5, 6, 2, 8, 4};
    cout<<"enter the index on which you want insertion: ";
    cin>>index;
    cout<<"enter value: ";
    cin>>value;
    insertion(arr, &size, index, value, capacity);
    cout<<"size of new array: "<<size<<endl;
    display(arr, size);
    return 0;
}