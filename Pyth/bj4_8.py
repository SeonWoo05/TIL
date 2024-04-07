## dp : dynamic programming
# 1. 시각적으로 접근 => 규칙성
# 2. dp[] table 정의, dp[i] 를 어떻게 정의하 것인지(점화식)
# 3. 초기값 설정, 반복처리

# BJ 1463 [dp] # 진짜 어렵네
N = int(input())

dp = [0] * (N+1) # 0~N 까지의 dp table을 만들어두고

for i in range(2,N+1):
    dp[i] = dp[i-1] + 1
    
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i//2]+1)
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i//3]+1)

print(dp[N])


# BJ 1152
N = list(map(str, input().split()))
print(len(N))

# BJ 2577
A = int(input())
B = int(input())
C = int(input())
D = A * B * C

E = list(str(D)) # int 값은 str() 안에 넣어서 list로 만들면 한자리씩 들어감
F = list(map(int, E)) # 다시 int로 변경

for i in range(0,10):
    print(len(list(filter(lambda x: x == i,F)))) # list 안에서 i의 개수 반환

## 다른풀이
A = int(input())
B = int(input())
C = int(input())

mul = str(A*B*C)
for i in range(10):
    print(mul.count(str(i)))

# 내가 푼방식에서 count 이용하면
A = int(input())
B = int(input())
C = int(input())
D = A * B * C

E = list(str(D))
F = list(map(int, E))
for i in range(10):
    print(F.count(i)) # list에 바로 .count()도 가능하다!!!!! 굿!!

