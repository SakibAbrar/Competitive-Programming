#include <iostream>

using namespace std;
#define maxN 105

int rowN, colN;
int arr[maxN][maxN]; // main array 0 indexed
long long pref[maxN][maxN]; // all 0 for prefix sum array 1 indexed

void initialize(){

    /// makes every row as a prefix 1D array
    for(int row = 1; row <= rowN; row++ ){
        for(int col = 1; col <= colN; col++){
            pref[row][col] = pref[row][col - 1] + arr[row - 1][col - 1];
            // cout << pref[row][col] << ",";
        }
        // cout << endl;
    }

    // cout << endl << endl;

    /// makes every column as a prefix 1D array 
    /// now, the total thing becomes 2D
    for(int row = 1; row <= rowN; row++ ){
        for(int col = 1; col <= colN; col++){
            pref[row][col] += pref[row - 1][col];
            // cout << pref[row][col] << ",";
        }
        // cout << endl;
    }
}


// 0 indexed query
long long rangeQuery(int x1, int y1, int x2, int y2){
    return pref[x2 + 1][y2 + 1] - pref[x1][y1] - pref[x1][y2 + 1] - pref[x2 + 1][y1];
}

int main(){
    cin >> rowN >> colN;

    for(int row = 0; row < rowN; row++ ){
        for(int col = 0; col < colN; col++){
            cin >> arr[row][col];
        }
    }

    /// preprosessing
    initialize();

    cout << rangeQuery(0, 1, 1, 2) << endl;

    return 0;
}
