#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int N = s.length();
    int camelCaseCount = 1;
    
    for(int i=0; i<N; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') camelCaseCount++;
    }
    return camelCaseCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
