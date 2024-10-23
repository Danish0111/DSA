#include <iostream>
using namespace std;

int search(int arr[], int element, int s){
    int low = 0, mid, high = s-1;
    while (low<=high)
    {
        mid = (high+low)/2;
        if (arr[mid] == element){
            return mid;
        }
        if (arr[mid] < element){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    return 0;
}
int main(){
    int arr[] = {4, 12, 34, 45, 67, 86, 98, 121, 323, 344};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element, index;
    cout<<"enter element to search: ";
    cin>>element;

    index = search(arr, element, size);
    // cout<<"ELEMENT FOUND AT INDEX "<<index<<endl;
    if (!search(arr, element, size))
    {
        cout<<"ELEMENT NOT FOUND!!"<<endl;
    }
    else
    {
        cout<<"ELEMENT FOUND AT INDEX "<<index<<endl;
    }
    return 0;
}