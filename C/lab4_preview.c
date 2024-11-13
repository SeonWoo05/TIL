// Problem 1
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
/**
* @brief : generate and return a random digit in 0~9
* @return : a digit in 0~9
* @param	 : none
*/
int generate_a_digit(void) {
	return (rand()%10);
}

/**
* @brief : generate a 3-digits target integer for the puzzle
* @return : return an integer with 3 different digits in 0~9
* @param : none
*/
int generate_target_number_approach2(void) { // 이부분이 문제임
	int first, second, third;

    // 첫 번째 숫자를 랜덤하게 생성
    first = generate_a_digit();

    // 두 번째 숫자를 생성 (첫 번째와 다를 때까지 반복)
    do {
        second = generate_a_digit();
    } while (second == first);
    // 세 번째 숫자를 생성 (첫 번째, 두 번째와 다를 때까지 반복)
    do {
        third = generate_a_digit();
    } while (third == first || third == second);

    // 세 자리 숫자를 반환
    return first * 100 + second * 10 + third;
}


// Problem 2
#include <stdio.h> 
/**
* @brief : compare the guessed number with the target and return the match results
* @return : return 2-digits number, 1st digit stands for the number of strikes and 2nd digit stands for the number of balls. For example 11 means 1 strike 1 ball
* @param	 : 	target - 3-digits target integer
			guessed - 3-digits guessed integer
*/
int get_match_result(int target, int guessed) { // 이부분이 문제
	int n_strike=0, n_ball=0;
	
    int target_digits[3] = {target / 100, (target / 10) % 10, target % 10};
    int guessed_digits[3] = {guessed / 100, (guessed / 10) % 10, guessed % 10};

    // Count strikes
    for (int i = 0; i < 3; i++) {
        if (target_digits[i] == guessed_digits[i]) {
            n_strike++;
        }
    }

    // Count balls
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j && target_digits[i] == guessed_digits[j]) {
                n_ball++;
            }
        }
    }
	
	return (n_strike*10 + n_ball);
}


// Problem 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ATTEMPT_LIMIT	9

// Function Prototypes
int generate_target_number(void);
int guess_number(void);
int get_match_result(int target, int guessed);
void receive_match_result(int result, int guessed);

int is_different_digits(int num);
int generate_a_digit(void);

int generate_target_number(void) {
    int first, second, third;

    // 첫 번째 숫자 생성
    first = generate_a_digit();

    // 두 번째 숫자 생성 (중복 제거)
    do {
        second = generate_a_digit();
    } while (second == first);

    // 세 번째 숫자 생성 (중복 제거)
    do {
        third = generate_a_digit();
    } while (third == first || third == second);

    // 세 자리 숫자를 반환
    return first * 100 + second * 10 + third;
}


int get_match_result(int target, int guessed) {
    int n_strike = 0, n_ball = 0;

    int target_digits[3] = {target / 100, (target / 10) % 10, target % 10};
    int guessed_digits[3] = {guessed / 100, (guessed / 10) % 10, guessed % 10};

    // Count strikes
    for (int i = 0; i < 3; i++) {
        if (target_digits[i] == guessed_digits[i]) {
            n_strike++;
        }
    }

    // Count balls
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j && target_digits[i] == guessed_digits[j]) {
                n_ball++;
            }
        }
    }

    return n_strike * 10 + n_ball; // Return result as a 2-digit number
}


int main(void) {
	int n_attempt = 0;
	int target_num, guessed_num, match_result;

	setvbuf(stdout,NULL,_IONBF, 0);

	srand(time(0));
	target_num = generate_target_number();
	do {
		printf("Attempt [%d/%d] ",++n_attempt, ATTEMPT_LIMIT);
		guessed_num = guess_number();
		match_result = get_match_result(target_num, guessed_num);
		receive_match_result(match_result, guessed_num);
	} while (n_attempt <= ATTEMPT_LIMIT && match_result != 30);

	if (match_result == 30)
		printf("Congratulation!!! You Win\n");
	else
		printf("Nice Try!!! But You Lose, The target number is %d\n", target_num);
	return 0;
}

/**
* @brief : check digit duplication
* @return : return true if all digits of the number are different, false otherwise.
* @param	 : 	num a 3-digits number to be checked for digit duplication.
*/
int is_different_digits(int num) {
	int digits[3];
	int is_different = 1;

	digits[0] = num%10;
	digits[1] = (num/10)%10;
	digits[2] = (num/100)%10;
	if ((digits[0] == digits[1]) ||
		(digits[0] == digits[2]) ||
		(digits[1] == digits[2]) )
		is_different = 0;

	return is_different;
}

/**
* @brief : generate and return a random digit in 0~9
* @return : a digit in 0~9
* @param	 : none
*/
int generate_a_digit(void) {
	return (rand()%10);
}

/**
* @brief : get a guessed number from the Attacker
* @return : return an integer with 3 different digits in 0~9
* @param	 : none
*/
int guess_number(void) {
	int num;
	while (1) {
		printf("Enter your guess : ");
		scanf("%d",&num);
		if (num < 1000 && is_different_digits(num)) break;
		printf("Input Error !!! Wrong number format\n");
	}
	return num;
}

/**
* @brief : notify the match result of the guessed number to the Attacker
* @return : none
* @param	 : 	result - 2-digits number for the match result, 1st digit stands for the number of strikes and 2nd digit stands for the number of balls.
			guessed - 3-digits guessed integer
*/
void receive_match_result(int result, int guessed) {
	int n_strike = result/10, n_ball = result%10;
	switch (result) {
		case 30 : printf("Congratulation !!!\n");
			break;
		case 0 : printf("Oops !!!\n");
			break;
		default : printf("Nice try !!!\n");
	}
	printf("Your guess %d is [%d] strikes and [%d] balls\n",
		guessed, n_strike, n_ball);
}


// Problem 4
#include <stdio.h>
#include <stdbool.h>

bool isCalibrationMode = false; // 보정모드인지 (보정모드에 치료X)

void beginCalibration() {
    isCalibrationMode = true; // 보정모드
}

void endCalibration() {
    isCalibrationMode = false; // 치료모드
}

void performRadiation(int dose) { // 방사선 투여
    printf("Radiation performed with dose: %d\n", dose);
}

void safeRadiation(int dose) { // 치료모도 + 방사선 용량 확인
    // 치료 모드인지 확인
    if (isCalibrationMode) {
        printf("에러 출력케이스 주어짐\n");
        return;
    }

    // 방사선 용량이 안전한 범위인지 확인
    if (dose < 1 || dose > 10) {
        printf("에러 출력케이스 주어짐\n");
        return;
    }

    // 조건이 모두 충족되면 방사선 투여
    performRadiation(dose);
}

int main() {
    // A technician calibrated the machine but forgot to switch back to treatment mode.
    beginCalibration();
    int calibrationDose = 30;
    performRadiation(calibrationDose);
	
    // The safe range for treatment is (0, 10)
    int patientDose = 15;
    // This should trigger the error message, protecting the patient
    safeRadiation(patientDose);  

    // Switching back to treatment mode and testing again
    endCalibration();
	
    // This should successfully administer radiation
    patientDose = 5;
    safeRadiation(patientDose);

    return 0;
}


// Problem 5
#include <stdio.h>
#define MAX_NUMBER	10000

int d(int n) {
	int sum = n;
	while(n>0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(void) {
	int A[MAX_NUMBER] = {0};

	for (int i=1; i<MAX_NUMBER; i++) {
		if (d(i) < MAX_NUMBER){
			A[d(i)] = 1;
		}
	}

	for (int i=1; i<MAX_NUMBER; i++) {
		if (A[i] == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}