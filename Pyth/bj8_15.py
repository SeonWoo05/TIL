# BJ 2869
# 시간초과 발생 - 반복하지말고 그냥 계산으로
A,B,V = map(int, input().split())

sum = A
cnt = 1
while sum < V:
    sum -= B
    sum += A
    cnt += 1

print(cnt)

# 서칭
A,B,V = map(int, input().split())

days = (V-B) // (A-B) # 올라가서 도착하면 끝 => V-B
if ((V-B) % (A-B)) != 0:
    days += 1

print(days)

# import로도 가능
import math

A, B, V = map(int, input().split())
days = math.ceil((V - B) / (A - B))

print(days)