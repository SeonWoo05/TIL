#include <iostream>
using namespace std;

class Date {
    // private data
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {
        if (month == 2 && day == 29)
            cout << "incorrect date" << endl;
    }

    int Month() {
        return month;
    }

    int Day() {
        return day;
    }

    int Year() {
        return year;
    }

    // 윤년이면 1(TRUE), 아니면 0(FALSE)
    int LeapYear() {
        if (year % 4 != 0)
            return 0;
        else {
            if (year % 100 != 0)
                return 1;
            else if (year % 400 != 0)
                return 0;
            else
                return 1;
        }
    }

    // 해당 월의 날짜 수 반환
    int DaysInMonth() {
        switch (month) {
            case 2:
                return LeapYear() ? 29 : 28;
            case 4: case 6: case 9: case 11:
                return 30;
            default:
                return 31;
        }
    }

    // 날짜를 하루 증가시킴
    void IncreaseDate() {
        if (day < DaysInMonth())
            day++;
        else {
            day = 1;
            if (month != 12)
                month++;
            else {
                month = 1;
                year++;
            }
        }
    }

    // 날짜 출력
    void PrintDate() {
        cout << "Date : " << month << "/" << day << "/" << year << endl;
    }

    // 윤년 여부 출력
    void PrintLeap() {
        cout << "The year " << year;
        if (LeapYear())
            cout << " is a leap-year" << endl;
        else
            cout << " is not a leap-year" << endl;
    }
};

// 테스트 프로그램
int main() {
    // 객체 newYearsDay 정의 및 연산 수행
    Date newYearsDay(1, 1, 2017);
    newYearsDay.PrintDate();

    newYearsDay.IncreaseDate();
    newYearsDay.PrintDate();
    newYearsDay.PrintLeap();

    // 객체 d 생성 및 연산 수행
    Date d(5, 15, 2016);
    d.IncreaseDate();
    d.PrintDate();
    d.PrintLeap();

    // 주어진 날짜부터 증가시켜 출력
    for (Date dd(2, 25, 2017); dd.Day() < 3 || dd.Day() > 10; dd.IncreaseDate()) {
        dd.PrintDate();
    }

    // system("pause");
    return 0;
}
