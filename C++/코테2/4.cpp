#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int SUBJECT_COUNT = 5;

class Student {
public:
    string name;
    int age;
    string subjects[SUBJECT_COUNT];
    int scores[SUBJECT_COUNT];
    int passFails[SUBJECT_COUNT];

};

enum Menu {
    TopScores = 1,
    PassFail,
    Sort,
    EXIT
};

int main() {
    const int SUBJECT_COUNT = 5;
    string subjects[SUBJECT_COUNT] = {"수학", "국어", "영어", "과학", "역사"};
    int passFails[SUBJECT_COUNT] = {80, 80, 80, 84, 90};
    int select;

    Student* studentSet[5];
    cin >> select;


        case TopScores:

            break;
        case PassFail:

            break;
        case Sort:

            break;
        case EXIT:
            cout << "프로그램을 종료합니다." << endl;
            break;


    return 0;
}