// Problem 1. k번째 큰 값 찾기
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

    return arr[k-1];
}


// Problem 2. print_local_time_after_kdays
void print_local_time_after_kdays(time_t t, int k) {
    time_t future_time = t + k * 24 * 60 * 60;

    struct tm *local_time = localtime(&future_time);

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


// Problem 3. 구조체 bubble sort
void stud_bubble_sort(STUD *pnucse) {
    STUD *ps_cur = pnucse, *ps_end;

    for (ps_end = stud_get_last(pnucse); ps_end > pnucse; ps_end--) {
        for (ps_cur = pnucse; ps_cur < ps_end; ps_cur++) {
            if (stud_compare_points(ps_cur, ps_cur + 1) < 0) {
                stud_swap(ps_cur, ps_cur + 1);
            }
        }
    }
}


// Problem 4.
// 1. Parsing Date and Time
struct tm parse_datetime(char *datetime_str) {
    struct tm time = {0}; // 구조체 초기화(전부 0으로)
    
    sscanf(datetime_str, "%4d-%2d-%2d %2d:%2d", // %2d 하면 숫자 자체만 저장하므로 앞의 0은 제거
           &time.tm_year, &time.tm_mon, &time.tm_mday,
           &time.tm_hour, &time.tm_min);

    time.tm_year -= 1900; // tm_year는 1900부터 시작
    time.tm_mon -= 1; // tm_mon은 0부터 시작
    return time;
}

// 2. Detecting Overlaps
int detect_schedule_conflict(struct tm *start1, struct tm *end1, struct tm *start2, struct tm *end2) {
    // 이를 Epoch Time(1970년부터 경과된 초)로 변환, 결과는 time_t 타입으로 반환
    time_t t_start1 = mktime(start1);
    time_t t_end1 = mktime(end1);
    time_t t_start2 = mktime(start2);
    time_t t_end2 = mktime(end2);

    // 두 구간이 겹치는지 확인
    return (t_start1 <= t_end2) && (t_start2 <= t_end1);
}

