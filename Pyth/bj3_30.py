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