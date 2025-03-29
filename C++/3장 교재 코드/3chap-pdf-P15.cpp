// [실습예제] 생성자와 소멸자에 대한 실습예제이다.
// 생성자가 없을 때, parameter가 없는 생성자, parameter가 있는 생성자
// 3가지 경우의 차이를 확인해보자

// 생성자 없음 : Date date; 사용 시 컴파일러가 자동 생성자를 만들어주지만, 멤버 변수를 초기화하지 않음 → 쓰레기값 출력
// 기본 생성자 : Date() { month = 1; ... } 를 직접 정의하면 안전하게 초기화됨
// 매개변수 생성자 : Date(int m, int d, int y) → 원하는 날짜로 초기화 가능

#include <iostream>
using namespace std;

// 여러 개의 생성자를 갖는 class Date의 부분 정의
class Date {
    int month;
    int day;
    int year;

public:
    /*
    // parameter가 있는 생성자
    Date(int m, int d, int y) : month(m), day(d), year(y) { }

    // 기본 생성자 (parameter가 없는 경우에 default 값으로 초기화)
    Date() {
        // compiler는 미정의된 내부 데이터 member 값을 초기화하지 않는다.
        // 그래서 다음과 같이 초기값을 사전 설정하는 것이 필요하다.
        month = 1;
        day = 1;
        year = 2000;
    }
    */

    void showDate() {
        cout << year << "년 " << month << "월 " << day << "일" << endl;
    }

    ~Date() {
        cout << "소멸자 호출" << endl;
    }
    // new로 만든 객체는 heap에 할당됨
    // 자동으로 사라지지 않음 → 반드시 delete로 해제해야 소멸자 호출됨
    // 이 코드에는 해당x

};

int main() {
    // 주석1: 생성자가 없을 경우
    Date date;
    // 생성자가 없을 경우 compiler가 자동으로 생성해주지만,
    // 아무런 일을 하지 않기 때문에 쓰레기값이 출력됨
    date.showDate();

    // 주석2: parameter가 없는 생성자
    /*
    Date date1;
    date1.showDate();
    */

    // 주석3: parameter가 있는 생성자
    /*
    Date date2(3, 1, 2017);
    date2.showDate();
    */

    return 0;
}
