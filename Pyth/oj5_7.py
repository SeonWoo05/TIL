# 1.숫자 놀이
num = input()

def iter_sum(num):
    A = list(map(int, num))
    while len(A) >= 1:
        A = str(sum(A))
        A = list(map(int, A))
        if len(A) == 1:
            result = sum(A)
            return result
    
B = iter_sum(num)
print(B)


# 2.시험기간 술
N = int(input())
A = int(input())
B = int(input())
C = int(input())
D = int(input())

def caculate_days(a,b):
    daay = a / b
    if daay % 1 != 0:
        daay = int(daay)+1
    return int(daay)

maxday = N - max(caculate_days(A,C),caculate_days(B,D))
print(maxday)


# 3.이상한 연산자
T = int(input())

def at(m):
    A = m * 3
    return A

def per(m):
    A = m + 5
    return A

def hash(m):
    A = m - 7
    return A

for i in range(T):
    n, oper = map(str,input().split())

    if oper == '@':
        A = at(float(n))
        print(f'{A:.2f}')

    elif oper == '%':
        A = per(float(n))
        print(f'{A:.2f}')

    elif oper == '#':
        A = hash(float(n))
        print(f'{A:.2f}')


## 4.깨진 바이오 리듬
# 계획
# 1. 입력부터 받음 / cu,th를 입력 받는데 이건 diff 함수의 매개변수 => diff 내에 to_second 들어감
# 2. 함수 정의
# 3. diff() 함수 내에서 to_second()를 불러와서 초로 결과를 내보냄
# 4. print_time() 함수로 다시 시:분:초 로 되돌려 출력 

#[1] : 시간(hms)을 초(n)로 환산하는 함수
def to_second(hms):
    h, m, s = map(int, hms.split(':'))
    return h * 3600 + m * 60 + s

#[2] : 수면 시작 시간(cu)과 기상 시간(th)을 입력 받아 두 시간의 차이(ans)를 계산하는 함수
def diff(cu, th):
    n = to_second(cu)
    m = to_second(th)

    ans = m - n
    if ans <= 0:
        ans += 24 * 3600  # 음수나 0이면 24시간을 더해준다.
    return ans

#[3] : 초(sec)를 입력받아, 출력 양식에 맞게(시간, 분, 초 - H, M, sec) 출력하는 함수
def print_time(sec):
    H = sec // 3600
    sec %= 3600
    M = sec // 60
    sec %= 60
    print("{0:02d}:{1:02d}:{2:02d}".format(H, M, sec))
    # print(f'{H:02d}:{M:02d}:{sec:02d}')

# 함수 정의는 다 건너띄고 이쪽 먼저 옴.
cu = input().strip()
th = input().strip()

difference = diff(cu, th)

print_time(difference) # 두 시간의 차이(초)를 print_time에 넣어 시간으로 바꾸어 출력



# 5.팩토리얼(재귀함수)
N = int(input())

def factorial(n):
    if n == 0: # 베이스 케이스를 잡아줘야 무한루프에 빠지지 않는다
        return 1
    elif n > 0 :
        result =  n * factorial(n-1)
    return result

print(factorial(N))