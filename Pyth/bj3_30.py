# BJ 11021
testcase = int(input())

for i in range(1,testcase + 1):
    A,B = map(int, input().split())
    print("Case #" + str(i) + ":", A+B)
## 실수1. A,B를 입력받는 input 함수가 반복문 안으로 들어와야함.
## 실수2. Case #i: 이런식으로 문자열끼리 붙어있다. 그럼 ','가 아니라 '+'를 사용해서 문자열을 붙인다. A+B는 숫자라서 ','로 띄운다.

# BJ 11022
testcase = int(input())

for i in range(1, testcase + 1):
    A,B = map(int, input().split())
    print("Case #" + str(i) + ":", A, "+", B, "=", A+B)

# BJ 2525
#1
H,M = map(int, input().split())
cooktime = int(input())

def update_time():
    global H,M
    M = M + cooktime   
    H += M // 60
    M %= 60

    if H >= 24:
        H -= 24

update_time()
print(H, M)

#2
H,M = map(int, input().split())
cooktime = int(input())

def update_time():
    global H,M
    M = M + cooktime   
    if M >= 60:
        H += M // 60
        M %= 60
        
        if H >= 24:
            H -= 24

update_time()
print(H, M)
## 전역변수로 이용하기 위해 함수 생성 / 그 안에서 값 정리해서 밖으로 꺼내기

# BJ 2914
Song,Mel_med = map(int, input().split())
copyright = (Mel_med - 1) * Song + 1
print(copyright)

# BJ 5355
n = int(input())

for i in range(1, n + 1):
    A = list(map(str, input().split()))
    B = float(A[0])
    for i in range(1, len(A)):
        if A[i] == "@":
            B *= 3
        elif A[i] == "%":
            B += 5
        elif A[i] == "#":
            B -= 7
    print("{:.2f}".format(B))    

## A를 리스트로 받아서 수와 문자를 구분한다.
## str로 받았으니 수는 float으로 바꿔준다.
## 두번째 세번째 ... 원소를 각각 연산자로 지정
## 소수점 둘째자리까지 출력

# "{}".format(B): 이 부분은 문자열 포맷팅을 사용하여 변수 B의 값을 문자열로 변환하는 부분입니다. format() 메서드는 문자열에 중괄호 {}를 사용하여 값을 삽입할 수 있습니다. 여기서는 {} 안에 B 변수를 넣어서 문자열로 변환합니다.
# "{:.2f}".format(B): 이 부분은 문자열 포맷팅을 통해 소수점 이하 두 자리까지의 실수로 변환하는 부분입니다. {} 안에 .2f를 사용하여 소수점 이하 두 자리까지의 실수로 포맷팅합니다. 따라서 이 부분은 B 변수의 값을 소수점 이하 두 자리까지 표시하는 문자열로 변환합니다.
# print("{:.2f}".format(B)): 이 부분은 변환된 문자열을 출력하는 부분입니다. print() 함수를 사용하여 문자열을 출력하고 있습니다.
# 아따 어려브라