/*
enum이란?
"enumeration(열거형)"의 줄임말,
"의미 있는 이름에 숫자를 자동으로 붙여주는 사용자 정의 자료형"
*/

#include <iostream>
using namespace std;

// 열거형(enum) Menu 정의
enum Menu { ADD = 1, DELETE, SEARCH, PRINT, EXIT };

int main() {
    int choice;
    while (true) {
        // 메뉴 출력
        cout << "\n===== Menu =====\n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Print\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // 사용자가 입력한 값은 int, 그걸 enum 타입으로 바꾸는 과정이 필요
        Menu selectedMenu = static_cast<Menu>(choice);

        // switch 문으로 메뉴 선택
        switch (selectedMenu) {
        case ADD:
            cout << "You selected ADD.\n";
            break;
        case DELETE:
            cout << "You selected DELETE.\n";
            break;
        case SEARCH:
            cout << "You selected SEARCH.\n";
            break;
        case PRINT:
            cout << "You selected PRINT.\n";
            break;
        case EXIT:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            break;
        }
    }
    return 0;
}