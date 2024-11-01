// 1 배열에서 짝수 홀수 분류하여 출력
#include <stdio.h>

int main() {
    int i, evenCount = 0, oddCount = 0;
    int arr[10], even[10], odd[10];

  
    printf("리스트의 요소 10개를 입력하세요:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }


    for (i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];  
        }
        else {
            odd[oddCount++] = arr[i]; 
        }
    }

    
    printf("\n짝수 리스트:\n");
    for (i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n짝수의 개수: %d\n", evenCount);

    
    printf("\n홀수 리스트:\n");
    for (i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n홀수의 개수: %d\n", oddCount);

    return 0;
}

// 2 계단 오르기 (1칸 or 2칸)
#include <stdio.h>

int climbStairs(int n) {
    if (n <= 1) {
        return 1;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int stairs;
    printf("계단의 개수를 입력하세요: ");
    scanf("%d", &stairs);

    int ways = climbStairs(stairs);
    printf("계단을 오를 수 있는 방법의 수: %d\n", ways);

    return 0;
}

// 3 문자열 받아서 숫자로 변환
#include <stdio.h>

int stringToNumber(char *input) {
    int number = 0;
    int i = 0;

    while (input[i] != '\0') {
        number = number * 10 + (input[i] - '0');
        i++;
    }

    return number;
}

int main() {
    char input[100];
    
    printf("문자열을 입력하세요: ");
    scanf("%s", input);

    int number = stringToNumber(input);
    printf("[%s] = %d\n", input, number);

    return 0;
}

// 4 입력된 문자(아스키코드)를 16진수로 변환하고, 10진수로 출력하라  
#include <stdio.h>

int hexStringToDecimal(char input[]) {  // 포인터 대신 배열 사용
    int result = 0;
    int i = 0;

    while (input[i] != '\0') {
        int value;
        
        if (input[i] >= '0' && input[i] <= '9') {
            value = input[i] - '0';
        }
        else if (input[i] >= 'A' && input[i] <= 'F') {
            value = input[i] - 'A' + 10;
        }

        result = result * 16 + value;
        i++;
    }

    return result;
}

int main() {
    char input[100];
    
    printf("16진수 문자열을 입력하세요: ");
    scanf("%s", input);

    int decimal = hexStringToDecimal(input);
    if (decimal != -1) {
        printf("%d\n", decimal);
    }

    return 0;
}