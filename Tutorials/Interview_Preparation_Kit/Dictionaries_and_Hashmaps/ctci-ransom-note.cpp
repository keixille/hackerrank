#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int MAX_HASH_SIZE = 30000;

struct HashTable {
    bool isExist;
    int count;
    string str;
};

int hashing(string str) {
    long hash = 5381;
    int N = str.length();
    
    for(int i=0; i<N; i++) {
        hash = ((hash << 5) + hash) + str[i];
    }
    return hash%MAX_HASH_SIZE;
}

void init(vector<HashTable> &table) {
    for(int i=0; i<MAX_HASH_SIZE; i++) {
        table[i].count = 0;
        table[i].isExist = false;
        table[i].str = "";
    }
}

void creatingNote(vector<HashTable> &table, vector<string> &note, int nNote) {
    int hashNum;
    
    for(int i=0; i<nNote; i++) {
        hashNum = hashing(note[i]);
        if(!table[hashNum].isExist) { // New note
            table[hashNum].isExist = true;
            table[hashNum].count = 1;
            table[hashNum].str = note[i];
        } else { // Old Note
            if(table[hashNum].str == note[i]) { // Existing note
                table[hashNum].count++;
            } else {
                hashNum++;
                while(table[hashNum].isExist) {
                    if(table[hashNum].str == note[i]) { // Existing note
                        table[hashNum].count++;
                        break;
                    }
                    hashNum++;
                    hashNum %= MAX_HASH_SIZE;
                }
                if(!table[hashNum].isExist) { // New note
                    table[hashNum].isExist = true;
                    table[hashNum].count = 1;
                    table[hashNum].str = note[i];
                }
            }
        }
    }
}

int validateMagazine(vector<HashTable> &table, vector<string> &magazine, int mMagazine) {
    int hashNum, hashCount, count = 0;
    
    for(int i=0; i<mMagazine; i++) {
        hashNum = hashing(magazine[i]);
        hashCount = 0;
        if(table[hashNum].isExist) { // Found note
            if(table[hashNum].str == magazine[i]) { // Same note
                if(table[hashNum].count > 0) {
                    table[hashNum].count--;
                    count++;    
                }
            } else {
                hashCount++;
                hashNum++;
                while(table[hashNum].isExist) {
                    if(hashCount == MAX_HASH_SIZE) break;
                    if(table[hashNum].str == magazine[i]) {
                        if(table[hashNum].count > 0) {
                            table[hashNum].count--;
                            count++; 
                        }
                        break;
                    }
                    hashCount++;
                    hashNum++;
                    hashNum %= MAX_HASH_SIZE;
                }   
            }
        }
    }
    return count;
}

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    int m = magazine.size();
    int n = note.size();
    vector<HashTable> hashTable(MAX_HASH_SIZE);
    int hashNum, validCount = 0, hashCount;
    
    init(hashTable);
    creatingNote(hashTable, note, n);
    validCount = validateMagazine(hashTable, magazine, m);
    
    if(validCount == n) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

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
