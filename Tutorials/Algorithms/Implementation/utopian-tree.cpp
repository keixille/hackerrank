#include <bits/stdc++.h>

using namespace std;

int growth[61];
int growthCount = 0;

void initGrowth() {
    for(int i=0; i<=60; i++) {
        growth[i] = -1;
    }
}

void setGrowth(int start, int end) {
    for(int i=start; i<=end; i++) {
        if(i % 2 == 1) growth[i] = growth[i-1]*2;
        else growth[i] = growth[i-1]+1;
        growthCount++;
    }
}

// Complete the utopianTree function below.
int utopianTree(int n) {
    if(growthCount == 0) {
        initGrowth();
        growth[0] = 1;
        setGrowth(1, n);
    } else {
        if(growth[n] == -1) setGrowth(growthCount+1, n);
    }
    return growth[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
