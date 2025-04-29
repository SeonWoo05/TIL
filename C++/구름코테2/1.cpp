#include <iostream>
#include <cstring>
using namespace std;

// 메뉴 enum 정의
enum Menu { INPUT = 1, INSERT, DELETE, UPDATE, EXIT };

// Student 클래스
class Student {
private:
    int id;
    char* name;
    int age;

public:
    static int count;

    Student() {
        id = 0;
        age = 0;
        name = new char[20];
        strcpy(name, "unknown");
        ++count;
    }

    Student(int id, const char* name, int age) {
        this->id = id;
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        ++count;
    }

    ~Student() {
        delete[] this->name;
        --count;
    }

    void setId(int id) {
        this->id = id;
    }

    void setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setAge(int age) {
        this->age = age;
    }

    void incAge() {
        this->age++;
    }

    int getId() const {
        return this->id;
    }

    const char* getName() const {
        return this->name;
    }

    int getAge() const {
        return this->age;
    }

    void print() const {
        cout << "ID: " << this->id
             << ", Name: " << this->name
             << ", Age: " << this->age << endl;
    }
};

int Student::count = 0;

// 함수 선언
void inputStudents(Student* table[], int& size);
void showStudents(Student* table[], int size);
void insertStudent(Student* table[], int& size);
void deleteStudent(Student* table[], int& size);
void updateStudent(Student* table[], int size);

// 학생 5명 자동 입력
void inputStudents(Student* table[], int& size) {
    const char* names[5] = { "강감찬", "이순신", "신사임당", "김유신", "윤봉길" };
    int ids[5] = { 101, 102, 103, 104, 105 };
    int ages[5] = { 20, 21, 22, 23, 24 };

    for (int i = 0; i < 5; i++) {
        table[i] = new Student(ids[i], names[i], ages[i]);
    }
    size = 5;

    cout << "[5명의 학생이 자동으로 입력되었습니다.]" << endl;
    showStudents(table, size);
}

// 학생 목록 출력
void showStudents(Student* table[], int size) {
    cout << "[현재 등록된 학생 목록]" << endl;
    for (int i = 0; i < size; i++) {
        table[i]->print();
    }
}

// 학생 추가
void insertStudent(Student* table[], int& size) {
    int id, age;
    char name[100];
    cout << "Enter ID Name Age: ";
    cin >> id >> name >> age;

    table[size] = new Student(id, name, age);
    size++;

    cout << "[학생이 추가되었습니다.]" << endl;
    showStudents(table, size);
}

// 학생 삭제
void deleteStudent(Student* table[], int& size) {
    char name[100];
    cout << "Enter name to delete: ";
    cin >> name;

    int idx;
    for (int i = 0; i < size; i++) {
        if (strcmp(table[i]->getName(), name) == 0) {
            idx = i;
            break;
        }
    }
	
    delete table[idx];
    for (int i = idx; i < size - 1; i++) {
        table[i] = table[i + 1];
    }
    table[size - 1] = nullptr;
    size--;

    cout << "[" << name << " 님의 정보가 삭제되었습니다.]" << endl;
    showStudents(table, size);
}

// 학생 나이 업데이트
void updateStudent(Student* table[], int size) {
    char name[100];
    cout << "Enter name to update: ";
    cin >> name;

    for (int i = 0; i < size; i++) {
        if (strcmp(table[i]->getName(), name) == 0) {
            table[i]->incAge();
            cout << "[" << name << " 님의 나이가 1 증가했습니다.]" << endl;
            showStudents(table, size);
            return;
        }
    }
    cout << "[" << name << " 님을 찾을 수 없습니다.]" << endl;
}

// 메인 함수
int main() {
    Student* table[10] = { nullptr };
    int size = 0;
    int choice;

    while (true) {
        cout << "\n1. INPUT\n2. INSERT\n3. DELETE\n4. UPDATE\n5. EXIT\n";
        cout << "Select menu: ";
        cin >> choice;

		Menu selection = static_cast<Menu>(choice);
			
        switch (selection) { // 1. INPUT 2. INSERT 3. DELETE 4. UPDATE 5. EXIT
            case INPUT:
                inputStudents(table, size);
                break;
            case INSERT:
                insertStudent(table, size);
                break;
            case DELETE:
                deleteStudent(table, size);
                break;
            case UPDATE:
                updateStudent(table, size);
                break;
            case EXIT:
                for (int i = 0; i < size; i++) {
                    delete table[i];
                }
                cout << "[모든 메모리 해제 완료]" << endl;
                cout << "[프로그램 종료]" << endl;
                return 0;
            default:
                cout << "[잘못된 메뉴입니다.]" << endl;
        }
    }
}

/*
// sort 와 search 추가
void sortByName(Student* table[], int size) {
    for (int i = 0; i < size - 1; i++) {           // 총 (n-1)번 반복
        for (int j = 0; j < size - i - 1; j++) {    // 매 반복마다 범위 줄어듦
            if (strcmp(table[j]->getName(), table[j + 1]->getName()) > 0) {
                // table[j]와 table[j+1]의 이름이 순서가 잘못되었으면 swap
                Student* temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
    cout << "[이름 기준으로 정렬 완료]" << endl;
}

case SORT:
    sortByName(table, size);
    showStudents(table, size);
    break;

int searchByAge(Student* table[], int size, int age) {
    for (int i = 0; i < size; ++i) {
        if (table[i]->getAge() == age)
            return i;                  // 찾으면 인덱스 반환
    }
    return -1;                         // 못 찾으면 –1
}

case SEARCH: {
    int target;
    cout << "Enter age to search: ";
    cin >> target;
    int idx = searchByAge(table, size, target);
    if (idx == -1) cout << "[나이가 " << target << "인 학생 없음]\n";
    else {
        cout << "[검색 결과]\n";
        table[idx]->print();
    }
    break;
}
*/