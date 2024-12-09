// Problem 1. k번째 큰 값 찾기
#include <stdio.h>
#include <stdlib.h>

#define END_MARK -1
#define MAX_SIZE 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 구조체 아니고 배열인 점 주의
int get_kth_largest(int *nums, int k) {
    int arr[MAX_SIZE];
    int count = 0;

    while (nums[count] != END_MARK) { // 배열의 원소 개수가 필요함
        arr[count] = nums[count];
        count++;
    }

    // if (k < 1 || k > count) {
    //     return -1;
    // }

    // 버블정렬
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) { // 이미 큰것은 앞으로 갔음 -> 그 전까지만
            if (arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    // 선택정렬
    for (int i = 0; i < count - 1; i++) {
        int max_index = i; // 처음부터 마지막-1 까지 돌면서
        
        for (int j = i + 1; j < count; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j; // arr[i] 보다 큰 index 저장
            }
        }
        if (max_index != i) { // 가장 큰게 i가 아니라면 i랑 가장 큰것 스왑
            swap(&arr[i], &arr[max_index]);
        }
    }

    // 삽입정렬
    for (int i = 1; i < count; i++) {
        int key = arr[i];
        int j = i - 1;

        // 두번째 원소부터 앞의 원소와 비교하는데 그 앞보다 작다면 while문 종료
        // 바꾼 후에도 더 이전의 원소와 계속 비교, 적절한 위치까지 이동
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return arr[k-1];
}

int main() {
    int nums[] = {3, 1, 4, 1, 5, 9, -1};
    int k = 3;

    int result = get_kth_largest(nums, k);
    printf("The %d-th largest element is: %d\n", k, result);

    return 0;
}


// Problem 2. print_local_time_after_kdays
#include <stdio.h>
#include <time.h>

void print_local_time_after_kdays(time_t t, int k) {
    // 1. k일 후의 시간을 계산
    time_t future_time = t + k * 24 * 60 * 60;

    // 2. 미래 시간을 로컬 시간으로 변환
    // future_time 값을 사람이 읽을 수 있는 시간으로 변환하기 위해
    // localtime 함수를 사용합니다. 이 함수는 time_t 타입을
    // struct tm 포인터로 변환하여 반환합니다.
    struct tm *local_time = localtime(&future_time);

    // localtime 함수는 시스템의 로컬 타임존을 기반으로 시간 데이터를 제공합니다.
    // 변환된 데이터는 다음과 같은 구조체 필드에 저장됩니다:
    // struct tm {
    //     int tm_sec;   // 초 (0-59)
    //     int tm_min;   // 분 (0-59)
    //     int tm_hour;  // 시 (0-23)
    //     int tm_mday;  // 일 (1-31)
    //     int tm_mon;   // 월 (0-11, 0 = January)
    //     int tm_year;  // 연도 (1900년 이후)
    //     int tm_wday;  // 요일 (0-6, 0 = Sunday)
    //     int tm_yday;  // 1년 중 몇 번째 날인지 (0-365)
    //     int tm_isdst; // 섬머타임 여부 (양수, 0, 음수)
    // };

    // 3. 로컬 시간을 읽기 쉬운 문자열로 변환
    printf("%d/%d/%d, %02d:%02d:%02d, ",
           local_time->tm_year + 1900,   // 연도 (tm_year는 1900부터 시작)
           local_time->tm_mon + 1,      // 월 (tm_mon은 0부터 시작하므로 +1)
           local_time->tm_mday,         // 일
           local_time->tm_hour,         // 시
           local_time->tm_min,          // 분
           local_time->tm_sec           // 초   
    );

    switch (local_time->tm_wday) {
        case 0 : puts("Sunday"); break;
        case 1 : puts("Monday"); break;
        case 2 : puts("Tuesday"); break;
        case 3 : puts("Wednesday"); break;
        case 4 : puts("Thursday"); break;
        case 5 : puts("Friday"); break;
        case 6 : puts("Saturday"); break;
        default: break;
    }
}

int main(void) {
    int k = 0;
    time_t now = 1669856792; // 2022/12/01 01:06:32

    scanf("%d", &k);

    print_local_time_after_kdays(now, k);

    return 0;
}


// Problem 3. stud_bubble_sort
#include <stdio.h>

typedef struct student {
    int id;
    char *pname;
    double points;
} STUD;

void stud_print(STUD *ps);
void stud_swap(STUD *a, STUD *b);
STUD * stud_get_last(STUD *ps_array);
int stud_compare_points(STUD *ps1, STUD *ps2);

void stud_bubble_sort(STUD *pnucse) {
    STUD *last = stud_get_last(pnucse); // 배열의 끝 위치를 가져옴

    for (STUD *i = pnucse; i < last; i++) {
        for (STUD *j = pnucse; j < last - i ; j++) { // 만약 어느 중간부터 정렬하는거면 잘 조정하면됨 j < 부분
            // 점수(points)를 기준으로 비교하여 내림차순 정렬
            if (stud_compare_points(j, j + 1) < 0) { // j번째의 points 값이 작으면
                stud_swap(j, j + 1);
            }
        }
    }
}

int main(void) {
    STUD pnucse[] = {{1, "Choi", 9.9}, {2, "Park", 0.1}, 
                     {3, "Kim", 5.0}, {4, "Lee", 3.0}, {5, "Moon", 9.5}, 
                     {6, "Kang", 7.0}, {7, "Jeon", 0.9}, {-1, NULL, 0.0}};

    STUD * ps_cur = pnucse;
    int test_id = 0;
    scanf("%d", &test_id);
    if (test_id) set_values_of_pnucse(pnucse, test_id);

    stud_bubble_sort(pnucse);

    while (ps_cur->id > 0)
        stud_print(ps_cur++);

    return 0;
}


// Problem 4.
#include <stdio.h>
#include <string.h>
#include <time.h>

// 1. Parsing Date and Time
struct tm parse_datetime(char *datetime_str) {
    struct tm time_info = {0}; // 구조체 초기화(전부 0으로)
    
    sscanf(datetime_str, "%4d-%2d-%2d %2d:%2d", // %2d 하면 숫자 자체만 저장하므로 앞의 0은 제거
           &time_info.tm_year, &time_info.tm_mon, &time_info.tm_mday,
           &time_info.tm_hour, &time_info.tm_min);

    // tm_year는 1900부터 시작, tm_mon은 0부터 시작
    time_info.tm_year -= 1900;
    time_info.tm_mon -= 1;

    return time_info;
}

// 2. Detecting Overlaps
int detect_schedule_conflict(struct tm *start1, struct tm *end1, struct tm *start2, struct tm *end2) {
    // time_t로 변환
    time_t t_start1 = mktime(start1);
    time_t t_end1 = mktime(end1);
    time_t t_start2 = mktime(start2);
    time_t t_end2 = mktime(end2);

    // 두 구간이 겹치는지 확인
    return (t_start1 <= t_end2) && (t_start2 <= t_end1);
}

int main() {
    char start1[20], end1[20], start2[20], end2[20];

    // 사용자로부터 입력받기
    printf("Enter the first time period (start and end) in the format YYYY-MM-DD HH:MM:\n");
    printf("Start 1: ");
    fgets(start1, sizeof(start1), stdin);
    start1[strlen(start1) - 1] = '\0'; // 개행 문자 제거

    printf("End 1: ");
    fgets(end1, sizeof(end1), stdin);
    end1[strlen(end1) - 1] = '\0'; // 개행 문자 제거

    printf("Enter the second time period (start and end) in the format YYYY-MM-DD HH:MM:\n");
    printf("Start 2: ");
    fgets(start2, sizeof(start2), stdin);
    start2[strlen(start2) - 1] = '\0'; // 개행 문자 제거

    printf("End 2: ");
    fgets(end2, sizeof(end2), stdin);
    end2[strlen(end2) - 1] = '\0'; // 개행 문자 제거

    // 입력값을 struct tm으로 변환
    struct tm t_start1 = parse_datetime(start1);
    struct tm t_end1 = parse_datetime(end1);
    struct tm t_start2 = parse_datetime(start2);
    struct tm t_end2 = parse_datetime(end2);

    // 겹치는지 확인
    if (detect_schedule_conflict(&t_start1, &t_end1, &t_start2, &t_end2)) {
        printf("Schedule conflict detected\n");
    } else {
        printf("No schedule conflict\n");
    }

    return 0;
}
