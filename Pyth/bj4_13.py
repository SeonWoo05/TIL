# BJ 2579
# 전형적인 점화식을 찾는 Dynamic Programming 문제
N = int(input())
stairs = [0] * 301
for i in range(N):
    stairs[i] = int(input())
    

dp = [0] * 301

dp[0] = stairs[0]
dp[1] = stairs[0] + stairs[1]
dp[2] = max(stairs[0] + stairs[2] , stairs[1] + stairs[2])

for i in range(3,N):
    dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i] , dp[i-2] + stairs[i])

print(dp[N-1])


# BJ 1065
A = int(input())
B = 0

if A <= 99:
    B += A
    print(A)

elif A >= 100:
    for i in range(100,A+1):
        C = list(str(i))
        D = list(map(int,C))
            
        if D[1] - D[0] == D[2] - D[1]:
            B += 1
        else:
            B += 0
    B += 99
    print(B)


# BJ 9012 스택!!
T = int(input())

for i in range(T):
    stack = []
    N = input()

    for j in N:
        if j == '(':
            stack.append(j)
        
        elif j == ')':
            
            if len(stack) != 0:
                stack.pop() # 마지막 원소 없앰

            else:
                print("NO")
                break
        
    else: # for문의 else문!! : for문이 끝까지 실행 되었을 경우 else로 감! 
        if len(stack) == 0:
            print("YES")

        else:
            print("NO")