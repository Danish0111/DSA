#include <iostream>
using namespace std;

int search(int a[], int e){
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == e)
        {
            return 1;
        }
        
    }
    return 0;
    
}
int main(){
    int arr[10] = {4, 34, 12, 5, 45, 60, 58, 13, 14, 24};
    int element;
    cout<<"enter the element to search: ";
    cin>>element;

    if (search(arr, element))
    {
        cout<<"ELEMENT FOUND!!"<<endl;
    }
    else
    {
        cout<<"ELEMENT NOT FOUND!!"<<endl;
    }
    
    return 0;
}