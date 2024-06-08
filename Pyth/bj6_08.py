# BJ 1157
A = input()
A = A.upper()
B = {}

for i in A:
    if i in B:
        B[i] += 1
    else:
        B[i] = 1

max_count = max(B.values())
max_char = [char for char, count in B.items() if count == max_count]

if len(max_char) != 1:
    print('?')

else:
    print(max_char[0])


# BJ 11052
N = int(input())
P = list(map(int, input().split()))
P.insert(0,0)
dp = [0] * (N+1)

for i in range(1,N+1):
    for j in range(1, i+1):
        # 반복하면서 그 전거와 1번 / 그 전전거와 2 더한거 쭉 반복
        dp[i] = max(dp[i], P[j] + dp[i-j])

print(dp[N])


# BJ 10872
def factorial(n):
    B = 1
    if n >= 2:
        for i in range(2,n+1):
            B *= i     
    print(B)

A = int(input())
factorial(A)


def factorial(n):
    B = 1
    if n == 1:
        print(1)
        break # break는 반복문만 가능
    # if문에서 함수 종료하고싶으면 return문 사용해야함!!!!!


