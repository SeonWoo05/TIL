// <Problem 1>
#include <stdio.h>

int main(void) {
    int a,r,n;
    int s,ai,i;

    scanf("%d%d%d", &a,&r,&n);

    ai = a;
    s = a;

    printf("%d", a);
    for (i=2; i<=n; i++) {
        ai = s*r;
        printf(" + %d", ai);
        s += ai;
    }
    
    printf(" = %d\n", s);
    return 0;
}


// <Problem 2>
#include <stdio.h>

int main(void) {
    int X, Y;

    while (1) {
        printf("Enter an integer number no less than 100: ");
        scanf("%d", &X);

        if (X < 100) printf("Sorry, the number you entered is less than 100\n");
        else {
            Y = X / 10 - (X / 100) * 10; // Y = (X / 10) % 10; 이게 더 깔끔
            if (Y % 2 == 0) printf("The 2nd last number of %d is %d and it is even", X, Y);
            else printf("The 2nd last number of %d is %d and it is odd", X, Y);
            return 0;
        }
    }
}


// <Problem 3>
#include <stdio.h>
#include <string.h>

int main(void) {
    int option = -1;

    int a[10] = {3, 7, 8, 9, 2, 3, 4, 6, 1, 7};

    int i;
    {
        int a2[] = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
        int a3[] = {1, 3, 7, 9, 9, 3, 1, 7, 1, 2};

        scanf("%d", &option);
        if (option == 2) 
            memcpy(a, a2, sizeof(a)); // 메모리카피같음
        else if (option == 3) 
            memcpy(a, a3, sizeof(a));

        // 배열을 직접 복사하는 코드 (memcpy 대체)
        if (option == 2) {
            for (i = 0; i < 10; i++) {
                a[i] = a2[i];  // a2의 값을 a로 복사
            }
        } else if (option == 3) {
            for (i = 0; i < 10; i++) {
                a[i] = a3[i];  // a3의 값을 a로 복사
            }
        }

    }

    for (i=9; i>=0; i--) {
        if (a[i] % 2 == 0) {
            printf("Found:a[%d]=%d", i, a[i]);
            return 0;
        }
    }
    
    printf("No even number");
    return 0;
}


// <Problem 4>
#include <stdio.h>

int main() {
    int N = 3;
    int option;
    scanf("%d", &option);

    if (option == 1) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=9; j++){
                printf("%d x %d = %d\n", i, j, i*j);
            }
        }
    }
    else if (option == 2) {
        for (int i=1; i<=N; i++) {
            for (int j=9; j>0; j--){
                printf("%d x %d = %d\n", i, j, i*j);
            }
        }
    }
    else if (option == 3) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=9; j+=2){
                printf("%d x %d = %d\n", i, j, i*j);
            }
        }
    }

    return 0;
}


// <Problem 5> - 공백을 출력해서 마지막 라인을 맞춰야 하는지 모르겠음
#include <stdio.h>

int main() {
    int n, direction;
    
    scanf("%d %d", &n, &direction);

    // Option 1: 별이 증가하는 패턴
    if (direction == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");  // 한 줄 출력 후 줄 바꿈
        }
    }
    // Option 2: 별이 감소하는 패턴
    else if (direction == 2) {
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");  // 한 줄 출력 후 줄 바꿈
        }
    }

    return 0;
}

// 두번째 : 공백으로 끝 열 맞추기
#include <stdio.h>

int main() {
    int n, direction;
    
    scanf("%d %d", &n, &direction);

    // Option 1: 별이 증가하는 패턴
    if (direction == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n-i; j++) {
                printf(" ");
            }
            
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");  // 한 줄 출력 후 줄 바꿈
        }
    }

    // Option 2: 별이 감소하는 패턴
    else if (direction == 2) {
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n-i; j++) {
                printf(" ");    
            }            
            
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");  // 한 줄 출력 후 줄 바꿈
        }
    }

    return 0;
}


// <Problem 6>
#include <stdio.h>

int main() {
    int n = 5;
    int arr[5];
    int k;
    int option;

    scanf("%d", &k);
    scanf("%d", &option);

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (option == 1) {
        for (int i=0; i<k; i++) {
            int temp = arr[n-1];
            for (int j=n-1; j>0; j--) {
                arr[j] = arr[j-1];
            }
            arr[0] = temp;
        }
    } 

    else if (option == 2) {
        for (int i=0; i<k; i++) {
            int temp = arr[0];
            for (int j=1; j<n; j++) {
                arr[j-1] = arr[j];
            }
            arr[n-1] = temp;
        }        
    }

    printf("Rotated array: ");

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}