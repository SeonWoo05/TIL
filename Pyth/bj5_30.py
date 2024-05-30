# BJ 2455
y,z = map(int, input().split())
X = [z]
for i in range(1,4):
    B,C = map(int, input().split())
    D = X[i-1] - B
    D = D + C
    X.append(D)

print(max(X))


# BJ 10953
T = int(input())
for i in range(T):
    a,b = map(int, input().split(","))
    print(a+b)


## BJ 1475
N = list(map(str, input()))
M = [0] * 10  # 0부터 9까지 숫자의 빈도를 저장할 리스트

for i in N:
    p = int(i)
    M[p] += 1 # 이러면 한번에 되네...

A = M[6] + M[9]
M[6] = (A + 1) // 2 # 둘이 더해서 홀 수 이면 두개를 사야하므로 2로 나눈 몫으로.
M[9] = M[6] # 몫은 정수로 나와서 int() 안해줘도됨. 나눗셈이면 int()해주기. 소숫점 자리 나오니까

print(max(M))


# BJ 1065 한수
A = int(input())
B = 0

if A <= 99:
    B += A
    print(B)

elif A >= 0:
    for i in range(100,A+1):
        C = list(str(i))
        D = list(map(int,C))

        if D[1] - D[0] == D[2] - D[1]:
            B += 1
    B += 99
    print(B)