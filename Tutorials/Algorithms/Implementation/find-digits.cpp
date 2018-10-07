#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    int nTemp = n;
    int divisibleDigitCount = 0;
    int digit;
    
    while(nTemp > 0) {
        digit = nTemp%10;
        if(digit != 0) {
            if(n%digit == 0) divisibleDigitCount++;  
        }
        nTemp /= 10;
    }
    return divisibleDigitCount;
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

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
