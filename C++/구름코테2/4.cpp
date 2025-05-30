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

    Student(string n, int a, string subjs[], int scrs[], int fails[]) {
        name = n;
        age = a;
        for (int i = 0; i < SUBJECT_COUNT; ++i) {
            subjects[i] = subjs[i];
            scores[i] = scrs[i];
            passFails[i] = fails[i];
        }
    }

    void printScores() const {
        cout << name << " (" << age << ") 점수: ";
        for (int i = 0; i < SUBJECT_COUNT; ++i)
            cout << subjects[i] << ":" << scores[i] << ' ';
        cout << endl;
    }

	void printPassedSubjects() const {
	    cout << name << " 통과 과목: ";
	    bool found = false;
	    for (int i = 0; i < SUBJECT_COUNT; ++i) {
	        if (scores[i] >= passFails[i]) {
	            cout << subjects[i] << " ";
	            found = true;
	        }
	    }
	    if (!found) cout << "없음";
	    cout << endl;
	}
};

bool compareByName(Student* a, Student* b) {
    return a->name < b->name;
}

int main() {
    const int SUBJECT_COUNT = 5;
    string subjects[SUBJECT_COUNT] = {"수학", "국어", "영어", "과학", "역사"};
    int passFails[SUBJECT_COUNT] = {80, 80, 80, 84, 90};

    int s1[] = {85, 90, 78, 88, 92};
    int s2[] = {75, 82, 90, 85, 84};
    int s3[] = {65, 70, 75, 80, 85};
    int s4[] = {95, 82, 88, 84, 91};
    int s5[] = {88, 76, 86, 79, 90};

    Student* studentSet[5];
    studentSet[0] = new Student("홍길동", 21, subjects, s1, passFails);
    studentSet[1] = new Student("김유신", 22, subjects, s2, passFails);
    studentSet[2] = new Student("계백", 23, subjects, s3, passFails);
    studentSet[3] = new Student("강감찬", 24, subjects, s4, passFails);
    studentSet[4] = new Student("을지문덕", 25, subjects, s5, passFails);

    enum Menu { TopScores = 1, PassFail, Sort, EXIT };

    while (true) {
        int select;
        cin >> select;
        Menu selection = static_cast<Menu>(select);

        switch (selection) {
            case TopScores: {
                cout << "[1] 과목별 최고 점수자:\n";
                for (int i = 0; i < SUBJECT_COUNT; ++i) {
                    int maxScore = -1;
                    string maxName;
                    for (int j = 0; j < 5; ++j) {
                        if (studentSet[j]->scores[i] > maxScore) {
                            maxScore = studentSet[j]->scores[i];
                            maxName = studentSet[j]->name;
                        }
                    }
                    cout << subjects[i] << ": " << maxName << " (" << maxScore << "점)" << endl;
                }
							  cout << endl;
                break;
            }

            case PassFail: {
                cout << "[2] 학생별 통과 과목:\n";
                for (int i = 0; i < 5; ++i)
                    studentSet[i]->printPassedSubjects();
								cout << endl;
                break;
            }

            case Sort: {
                cout << "[3] 이름순 정렬된 학생 정보:\n";
                sort(studentSet, studentSet + 5, compareByName);
                for (int i = 0; i < 5; ++i)
                    studentSet[i]->printScores();
								cout << endl;
                break;
            }

            case EXIT:
                // cout << "프로그램을 종료합니다." << endl;
                for (int i = 0; i < 5; ++i)
                    delete studentSet[i];
                return 0;
        }
    }

    return 0;
}
