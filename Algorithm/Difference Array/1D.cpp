#include <iostream>

using namespace std;
#define maxN 105

int size;
int arr[maxN];
int diff[maxN];

void initialize(){
    /// calculates differences between arrays
    diff[0] = arr[0];
    diff[size] = 0; /// this must be zero I guess

    for(int idx = 1; idx < size; idx ++){
        diff[idx] = arr[idx] - arr[idx - 1];
    }
}

void rangeUpdate(int left, int right, int value){
    diff[left] += value;
    diff[right + 1] -= value;
}

void readyArray(){
    arr[0] = diff[0];
    for(int idx = 1; idx < size; idx++)
        arr[idx] = diff[idx] + arr[idx - 1];
}

void printArray(){
    for(int idx = 0; idx < size; idx ++)
        cout << arr[idx] << ",";
    cout << endl;
}

/// 0 based indexing
int main(){
    cin >> size;
    for(int idx = 0; idx < size; idx ++){
        cin >> arr[idx];
    }

    //initialize the diff arrays
    initialize();

    //update
    rangeUpdate(0, 1, 10);
    rangeUpdate(1, 3, 20);
    readyArray();
    printArray();
    return 0;
}
