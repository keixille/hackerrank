#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string substring(string s, int start, int end) {
    int len = s.length();
    string result = "";
    
    for(int i=start; i<end; i++) {
        result += s[i];
    }
    return result;
}

string timeConversion(string s) {
    /*
     * Write your code here.
     */
    int strLen = s.length();
    int hours = (s[0]-'0')*10 + s[1]-'0';
    
    if(s[strLen-2] == 'P') {
        if(hours == 12) {
            s[0] = '1';
            s[1] = '2';
        }
        else {
            hours = (hours+12)%24;
            s[0] = hours/10 + '0';
            s[1] = hours%10 + '0';
        } 
    } else {
        if(hours == 12) {
            s[0] = '0';
            s[1] = '0';
        }
    }
    return substring(s, 0, strLen-2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

