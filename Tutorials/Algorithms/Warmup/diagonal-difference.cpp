#include <bits/stdc++.h>

using namespace std;

int absoluteValue(int val) {
    return val < 0 ? -val : val;
}

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {
    int nRow = arr.size();
    int nCol = arr[0].size();
    int leftDiagonal = 0, rightDiagonal = 0;
    
    for(int i=0; i<nRow; i++) {
        for(int j=0; j<nCol; j++) {
            if(i==j) leftDiagonal += arr[i][j];
            if(i+j == nRow-1) rightDiagonal += arr[i][j];
        }
    }
    return absoluteValue(leftDiagonal - rightDiagonal);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

