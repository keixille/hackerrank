#include <bits/stdc++.h>

using namespace std;

string intToString(int val) {
    string result;
    
    while(val > 0) {
        result = (char)((val%10)+'0') + result;
        val /= 10;
    }
    return result;
}

// Complete the solve function below.
string solve(int year) {
    string yearString = intToString(year);
    
    if(year <= 1917) {
        if(year%4 == 0) return "12.09." + yearString;
    } 
    if(year == 1918) return "26.09." + yearString;
    if(year >= 1919) {
      if(year%400 == 0) return "12.09." + yearString;
      if(year%4 == 0 && year%100 != 0) return "12.09." + yearString; 
    } 
    return "13.09." + yearString;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int year;
    cin >> year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = solve(year);

    fout << result << "\n";

    fout.close();

    return 0;
}
