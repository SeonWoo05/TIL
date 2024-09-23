// <Problem 1>

#include <stdio.h>

int main(void) {
    int a = 5;
    int b = 3;

    printf("a - b = %d\n", a-b); // c는 줄바꿈 필수
    printf("a / b = %f", (float)a/b);

    return 0;
}


// <Problem 2>
/*
#include <stdio.h>

int main(void) {
    int weightE = 65;
    float perM = 0.17; // 변수선언

    printf("%f", weightE * perM);

    return 0;
}*/

// 변수 선언 : 값을 변경할 수 있는 데이터 저장 공간을 만드는 것
// 상수 선언 : 값을 변경할 수 없는 데이터, 고정된 값
// 상수는 const 또는 #define을 사용해 선언
/*
#include <stdio.h>

#define MOON_GRAVITY 0.17 // 달의 중력 비율을 상수로 정의

int main(void) {
    // const float MOON_GRAVITY = 0.17; 이렇게도 가능

    int EARTH_WEIGHT = 65;
    printf("%f", EARTH_WEIGHT * MOON_GRAVITY);

    return 0;
}*/


// <Problem 3>
/*
#include <stdio.h>

int main(void) {
    float nC;
    int nF;

    printf("Enter Fahrenheit temperature: ");
    scanf("%d", &nF);

    nC = 5.0 / 9.0 * (nF - 32);

    printf("%d degrees Fahrenheit is %f degrees Celsius.\n", nF, nC);

    return 0;
}*/


// <Problem 4>

#include <stdio.h>

int main() {
    int principal, time;
	float rate, interest=0.0;
    
    //printf("Enter the principal amount: ");
    scanf("%d", &principal);
    //printf("Enter the annual interest rate: ");
    scanf("%f", &rate);
    //printf("Enter the time period in years: ");
    scanf("%d", &time);
    
    interest = principal * rate * time;
    
    printf("The simple interest is: %.2f\n", interest);
    return 0;
}