# BJ 1003
T = int(input())

dp = [[]] * 41
dp[0] = [1,0]
dp[1] = [0,1]
dp[2] = [1,1]

for i in range(T):
    N = int(input())

    for i in range(3,N+1):
        dp[i] = [dp[i-1][0] + dp[i-2][0] , dp[i-1][1] + dp[i-2][1]]
    
    print(dp[N][0],dp[N][1]) # 리스트에 0,1을 다 더해서 개수세기보다 개수 자체를 계속 더하는게 메모리가 적게 든다.


# BJ 2920
A = list(map(int, input().split()))
B = [1,2,3,4,5,6,7,8]
C = [8,7,6,5,4,3,2,1]

if A == B:
    print('ascending')

elif A == C:
    print('descending')

else:
    print('mixed')
        

# BJ 2609
A,B = map(int, input().split())
C = []

for i in range(1,min(A,B)+1):
    if A % i == 0:
        if B % i == 0:
            C.append(i)
    else:
        continue

D = max(C) * (A / max(C)) *(B / max(C)) # 혹시나 문제에 곱이나 나누기 있으면 정수로 꼭 바꿔주기

print(max(C))
print(int(D))