# 그리디

# BJ 11047
N, K = map(int, input().split())
A = []
for i in range(N):
    x = int(input())
    A.append(x)

A.sort(reverse=True)

cnt = 0

# for i in A:
#     while K >= i:
#         K -= i
#         cnt += 1 # 정답은 나오는데 시간초과 뜸 => while로 계속 반복하지말고 최대로 뺄 수 있는만큼 한번에 빼기

for i in A:
    if K == 0:
        break
    
    if K >= i:
        cnt += K // i # 몫은 cnt에 더하고
        K %= i # 나머지는 다시 K에

print(cnt) 


# BJ 2875
A,B,C = map(int, input().split())

team = 0

while True:
    A -= 2
    B -= 1
    if A < 0 or B < 0 or A+B < C:
        break
    team += 1

print(team)
