#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    int space = n;
    
    for(int row=1; row<=n; row++) {
        for(int col=1; col<=space-1; col++) {
            cout << " ";
        }
        for(int col=1; col<=n-space+1; col++) {
            cout << "#";
        }
        cout << endl;
        space--;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}

