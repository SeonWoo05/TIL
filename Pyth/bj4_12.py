# BJ 3033
A = list(map(int, input().split()))
B = [1, 1, 2, 2, 2, 8]
C = []
for i in range(len(B)):
    C.append(B[i] - A[i])
print(*C)


# BJ 2444
N = int(input())

for i in range(1, N+1):
    print(' ' * (N-i) + '*' * (2*i-1))

for i in range(1,N):
    print(' ' * i + '*' * ((2*N-1) -2*i))


# BJ 10988
A = list(input())
B = []
for i in range(0,len(A)):
    if A[i] == A[-(i+1)]:
        B.append(1)
    else:
        B.append(0)
if 0 in B:
    print(0)
else:
    print(1)


# BJ 4673
# 함수를 정의하라고 되어 있다.
def self_num(n): # 생성자 만들기
    x = list(str(n)) # 숫자를 문자열 형태로 저장 => 각 자리수를 따로 저장하고 싶어서! (리스트는 하나의 문자열도 나눠서 한 글자씩 저장하니까)
    result = 0 # 생성되는 숫자를 만들기 위해 변수 설정
    for i in range(len(x)): # 숫자를 나누어 받아서 자리수만큼 반복
        result += int(x[i]) # 자리수 만큼 반복하며 그 자리수 숫자를 결과에 더함
    result = result + n # 원래숫자도 더해서
    return result # 새로운 숫자 생성

results = set() # 중복제거를 위해 set함수 사용
for i in range(10000):
    results.add(self_num(i)) # 0=0 / 1=2 / 2=4 ... 반환되는 값이 집합에 추가됨
    # 집합이라서 .add 메서드 사용!

for m in range(1,10001): # 1~10000 리스트 생성
    if m not in results: # m 중에서 생성자 안에 없다면 셀프넘버
        print(m)
