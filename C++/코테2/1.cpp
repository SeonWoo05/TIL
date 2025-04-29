#include <iostream>
#include <cstring>
using namespace std;

// 메뉴 enum 정의
enum Menu {
    INPUT = 1,
    INSERT,
    DELETE_STUDENT,
    UPDATE,
    EXIT
};

class Student {
private:
    int id;
    char* name;
    int age;
    static int count;

public:
		Student() {
			id = 0;
			name = new char[20];
			strcpy(name,"unknown");
			age = 0;
		}

		Student(const char* n, const int i, const int a) { // 여기도 id부터 name age
			name = new char[20];
			name = n;
			id = i;
			age = a;
		}

		~Student() {
			
		}

		const Student& setName(char& name) const {
			delete []this->name;
			this->name = new char[20];
			strcpy(this->name,name);
			
			return *this;
		}

		const Student& setId(int& id) const {
			this->id = id;

			return *this;
		}

		const Student& setAge(int& age) const {
			this->age = age;
		}

		void print() {

		}

		char* getName() {
			return name;
		}
};

int Student::count = 0;

// 함수 정의 (파라미터 전달 방식)

void inputStudents(Student* table[], int& size) { // 참조변수라 size로 변경하고 count를 size를 이용하여 변경시킴킴
	  // names[], ids[], ages[]를 사용하여 5명의 객체를 생성하여 테이블을 만든다 
    const char* names[5] = { "강감찬", "이순신", "신사임당", "김유신", "윤봉길" };
    int ids[5] = { 101, 102, 103, 104, 105 };
    int ages[5] = { 20, 21, 22, 23, 24 };

	for (int i = 0; i < 5; i++) {
		table[i] = new Student(ids[i], names[i], ages[i])
		// table[i].setName(names[i]).setId(ids[i]).setAge(ages[i]); 
		count++;
	}
	size 
	/*
	for () {
	names[i] = new student(names[i], ids[i], );
	}
	*/
    cout << "[5명의 학생이 자동으로 입력되었습니다.]" << endl;
}

void showStudents(Student* table[], int& count) {
	cout << "[현재 등록된 학생 목록]" << endl;
	
	for (int i=0; i<count; i++) {
		table[i]->print();
	}
}

void insertStudent(Student* table[], int& count) {
	int id;
	// char * name;
	char name[20];
	int age;
	cin >> id >> name >> age;
	// Student *p = new Student(id, name, age); // 그냥 6번째 넣으면 돼서
	table[++count] = new Student(id, name, age); // 이렇게 해도 됨
	// 참조변수로 해야 main에서 한게 여기서 변경됨
}

void deleteStudent {
	char delName[20];
	cout << "삭제할 이름:";
	cin delName;
	for (int i = 0; i < 5; i++) {
		if (strcmp) // 여기서 getter setter 필요 => 생성하러 ㄱㄱ
	}
}


// main 함수
int main() {
    Student* table[10] = { nullptr };
    int count = 0;
    int choice;

    while (true) {
        cout << "\n1. INPUT\n2. INSERT\n3. DELETE\n4. UPDATE\n5. EXIT\n";
        cout << "Select menu: ";
        cin >> choice;

		Menu selection = static_cast<Menu>(choice);
			
		switch (selection) {
			// 1. INPUT 2. INSERT 3. DELETE 4. UPDATE 5. EXIT
		case INPUT: {
			inputStudents(table, count);
			showStudents(table, count);
			cout << table << endl;
			break;
		}

		case INSERT: {
			insertStudent(table, count);
		}
					
		}
				//2번 INSERT시에 입력 데이터: 106 유관순 25
			  //3번 DELETE시에 김유신 삭제
			  //4번 UPDATE시에 신사임당 변경
			  //출력 내용은 실행 화면 예시를 보고 출력 내용을 정해야 한다!!!
       
    }
}
carsetgetshowsort