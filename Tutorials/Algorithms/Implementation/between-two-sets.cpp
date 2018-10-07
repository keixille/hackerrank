#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int computeGcd(int x, unsigned long long y) {
    while(x != 0 && y != 0) {
        if(x > y) x %= y;
        else y %= x;
    }
    if(x == 0) return y;
    else return x;
}

bool checkFactor(vector<int> arr, int nArr, int factor) {
    for(int i=0; i<nArr; i++) {
        if(arr[i] % factor != 0) return false;
    }
    return true;
}

int computeFactors(vector<int> arrB, int nB, int lcm) {
    int count = 0;
    int n = 1;
    
    while(lcm*n <= arrB[0]) {
        if(checkFactor(arrB, nB, lcm*n)) count++;
        n++;
    }
    return count;
}

/*
 * Complete the getTotalX function below.
 */
int getTotalX(vector<int> a, vector<int> b) {
    /*
     * Write your code here.
     */
    int n = a.size();
    int m = b.size();
    int gcd;
    unsigned long long lcm;
    
    gcd = a[0];
    lcm = (unsigned long long) a[0];
    for(int i=1; i<n; i++) {
        gcd = computeGcd(a[i], lcm);
        lcm = lcm*a[i]/gcd; 
    }
    return computeFactors(b, m, lcm);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int a_itr = 0; a_itr < n; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int b_itr = 0; b_itr < m; b_itr++) {
        int b_item = stoi(b_temp[b_itr]);

        b[b_itr] = b_item;
    }

    int total = getTotalX(a, b);

    fout << total << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
