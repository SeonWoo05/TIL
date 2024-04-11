# BJ 2577 숫자의 개수 다시풀기
A = int(input())
B = int(input())
C = int(input())

D = A * B * C
E = str(D)
F = list(map(int,E))
for i in range(10):
    print(F.count(i))


# BJ 5585 거스름돈
N = int(input())
M = 1000-N
A = [500,100,50,10,5,1]
B = 0

for i in A:
    B += M // i
    M = M % i

print(B)


# BJ 2839 설탕배달
N = int(input())
M = 0

while N >= 0:
    if N % 5 == 0:
        M += N // 5
        print(M)
        break
    else:
        N -= 3
        M += 1
else:
    print(-1)


# BJ 8958 OX퀴즈
T = int(input())

for i in range(T):
    A = 0
    B = 0
    C = list(input())
    for i in C:
        if i == 'O':
            A += 1
            B = B + A
        else:
            A = 0
    print(B)


# BJ 9095 123더하기
T = int(input())
dp = [0] * 4
dp[0] = 0
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(4,11):
    D = dp[i-3] + dp[i-2] + dp[i-1]
    dp.append(D)

for i in range(T):
    N = int(input())
    print(dp[N])


# BJ 4344
T = int(input())

for i in range(T):
    A = list(map(int, input().split()))
    avg = sum(A[1:]) / A[0]
    
    cnt = 0
    for i in A[1:]:
        if i > avg:
            cnt += 1
    per = (cnt / A[0]) *100
    print('%.3f' %per + '%')