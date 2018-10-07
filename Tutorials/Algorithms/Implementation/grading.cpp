#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the gradingStudents function below.
 */
vector<int> gradingStudents(vector<int> grades) {
    /*
     * Write your code here.
     */
    int N = grades.size();
    int difference, round;
    vector<int> roundedGrades(N);
    
    for(int i=0; i<N; i++) {
        round = 10*(grades[i]/10);
        difference = grades[i] - round;
        roundedGrades[i] = grades[i];
        if(grades[i] >= 38) {
            if(difference > 2 && difference <5) roundedGrades[i] = round+5;
            else if(difference > 7 && difference <10) roundedGrades[i] = round+10;
        }
    }
    return roundedGrades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> grades(n);

    for (int grades_itr = 0; grades_itr < n; grades_itr++) {
        int grades_item;
        cin >> grades_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        grades[grades_itr] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

