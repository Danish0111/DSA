#include <iostream>
using namespace std;

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void deletion(int arr[], int *size, int index, int capacity){

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
        for (int i = index; i <= *size; i++)
        {
            arr[i] = arr[i+1];
        }
        (*size)--;
    }
}

int main(){
    int size = 5, capacity = 100, index;
    int arr[capacity] = {5, 6, 2, 8, 4};
    cout<<"enter the index on which you want deletion: ";
    cin>>index;
    deletion(arr, &size, index, capacity);
    cout<<"size of new array: "<<size<<endl;
    display(arr, size);
    return 0;
}