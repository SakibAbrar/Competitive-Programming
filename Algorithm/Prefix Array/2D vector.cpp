// suffix array and difference array are opposite concepts
// suffix(diff) = original array
// diff(suffix) = original array
#include <iostream>
#include <vector>

using namespace std;
#define maxN 105

// zero indexed diff return
// nput one indexed arr
vector<vector<int> > diffArrayMaker(vector<vector<int> > arr){
    int rowN = arr.size();
    int colN = arr[0].size();
    // Make an rowN-1 by colN-1 array
    vector<vector<int> > diff(rowN-1, vector<int>(colN-1));
    for (int i = 0; i < rowN-1; i++)
        for (int j = 0; j < colN-1; j++)
            diff[i][j] = arr[i+1][j+1] - arr[i+1][j];
    for (int i = rowN-2; i > 0; i--)
        for (int j = 0; j < colN-1; j++)
            diff[i][j] -= diff[i-1][j];
    return diff;
}

// one indexed update on [r1, r2) x [c1, c2)
void updateDiffArray(vector<vector<int> > &diff, int r1, int c1, int r2, int c2, int val){
    diff[r1-1][c1-1] += val;
    diff[r2-1][c2-1] += val;

    diff[r1-1][c2-1] -= val;
    diff[r2-1][c1-1] -= val;
}


// one indexed pref return
// input zero indexed arr
vector<vector<int> > prefArrayMaker(vector<vector<int> > arr){
    int rowN = arr.size();
    int colN = arr[0].size();
    // Make an rowN+1 by colN+1 array and initialize it with zeroes.
    vector<vector<int> > pref(rowN+1, vector<int>(colN+1, 0));
    for (int i = 1; i <= rowN; i++)
        for (int j = 1; j <= colN; j++)
            pref[i][j] = pref[i-1][j] + arr[i-1][j-1];
    for (int i = 1; i <= rowN; i++)
        for (int j = 1; j <= colN; j++)
            pref[i][j] += pref[i][j-1];
    return pref;
}

// one indexed update on [r1, r2) x [c1, c2)
int rangeSumQuery(vector<vector<int> >pref, int r1, int c1, int r2, int c2){
    return pref[r2][c2] - pref[r1][c1] - pref[r1][c2] - pref[r2][c1];
}

void printArray(vector<vector<int> >anyArray){
    int rowN = anyArray.size();
    int colN = anyArray[0].size();

    for (int i = 0; i < rowN; i++){
        for (int j = 0; j < colN; j++)
            cout << anyArray[i][j] << ",";
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int> > givenArray = {
        {0, 0, 0, 0, 0},
        {0, 1, 2, 3, 4},
        {0, 5, 6, 7, 8},
        {0, 9, 10, 11, 12},
    };

    vector<vector<int> > diffArray = diffArrayMaker(givenArray);
    printArray(diffArray);

    // one indexed [1, 3) x [1, 3)
    updateDiffArray(diffArray, 1, 1, 3, 3, 7);
    printArray(diffArray);

    vector<vector<int> > originalArray = prefArrayMaker(diffArray);
    printArray(originalArray);

    // testing suffix array
    vector<vector<int> > prefArray = prefArrayMaker(givenArray);

    cout << rangeSumQuery(prefArray, 1, 1, 3, 3) << endl;

    return 0;
}
