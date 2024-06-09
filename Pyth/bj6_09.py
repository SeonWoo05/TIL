# BJ 2309
A = []
for i in range(9):
    x = int(input())
    A.append(x)

B = []
for i in range(8):
    for j in range(i+1,9):
        if A[i] + A[j] == sum(A) - 100:
            B.append(A[i])
            B.append(A[j])
            break

A.remove(B[0])
A.remove(B[1])
A.sort()

for i in A:
    print(i)


# BJ 12852
N = int(input())
dp = [0] * (N+1)
path = [0] * (N+1) # 경로 추적하는 리스트

for i in range(2,N+1):
    dp[i] = dp[i-1] + 1
    path[i] = i-1 # 어디서왔는지를 남기기 위한 리스트

    if i % 2 == 0 and dp[i] > dp[i // 2] + 1:
        dp[i] = dp[i//2]+1
        path[i] = i // 2

    if i % 3 == 0 and dp[i] > dp[i // 3] + 1: # &는 비트연산자임;;
        dp[i] = dp[i//3]+1
        path[i] = i // 3

print(dp[N])

#경로추적
result = []
current = N
while current > 0:
    result.append(current)
    current = path[current]

#print(" ".join(result)) # join() : 문자열을 연결하기 위한 함수, 문자열로 변환한 후에 사용해야 함
print(" ".join(map(str, result)))


# BJ 2293
# dp[10] = dp[10] + dp[10-2] + dp[10-5]
n,k = map(int, input().split())

coins = []
for i in range(n):
    coins.append(int(input()))

coins.sort()

DP = [0] * (k + 1)
DP[0] = 1
for c in coins:
    for i in range(c, k + 1):
        DP[i] += DP[i - c]
print(DP[k])