# BJ 2302
N = int(input())
M = int(input())

dp = [0] * 41 ######### 이부분 N+1로 두면
dp[1] = 0
dp[2] = 2  # N=1 일때 여기서 오류
dp[3] = 3  # 값을 대입할 수 가 없다. => 애초에 테이블 크기를 정수로 주자!
for i in range(4,N+1):
    dp[i] = dp[i-1] + dp[i-2]

def index_get(a,b):
    A = [0]
    for i in range(b):
        x = int(input())
        A.append(x)
    A.append(a+1)
    
    B = []
    for i in range(len(A)-1):
        y = A[i+1] - A[i] - 1
        B.append(y)

    cnt = 1
    for i in B:
        if i > 1:
            cnt *= dp[i]

    return cnt

print(index_get(N,M))
        