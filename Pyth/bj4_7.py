# BJ 11720
N = int(input())
A = list(input()) # input()을 받고나서
A = map(int, A) # 다음에 나눠서 저장
B = 0

for i in A:
    B += i
print(B)

## 이 방식도 가능
N = int(input())
A = input() # input()을 받고나서
B = list(map(int, A)) # 다음에 나눠서 저장
C = 0

for i in B:
    C += i
print(C)


# BJ 11721
A = input() # 문자열을 입력받고 A[]로 접근 가능하다.

# range(시작,끝,증가값): 증가값을 이용해서 해보자
for i in range(0,len(A),10):
    print(A[i:i+10]) # A[a:b] 에서 b는 포함안한다... 리스트 슬라이싱에서 두번째 인덱스는 포함하지 않는다.


############# 연산횟수에 관한 문제 ##############
# BJ 1110
N = int(input())
num = N
count = 0

while True: # 일련의 과정을 거치면 count를 1 높이도록
    a = num // 10
    b = num % 10
    num = (((a + b) % 10) + b*10)
    count += 1
    if num == N:
        break
print(count)