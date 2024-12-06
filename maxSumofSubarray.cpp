#include <iostream>
#include <climits>
using namespace std;

int main(){
    int nums[] = {3, -4, 5, 2, -1, 7, -8};
    int currentSum = 0, maxSum = INT_MIN;
        for(int num  : nums){
            currentSum += num;
            maxSum = max(currentSum, maxSum);
            if(currentSum < 0){
                currentSum = 0;
            }
        }
    cout<<"max Sum is: "<<maxSum<<endl;
    return 0;
}