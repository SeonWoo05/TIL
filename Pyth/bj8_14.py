# BJ 11653
N = int(input())

A = []
for i in range(2,N+1):
    A.append(i)

B = []
for i in A:
    if N % i == 0:
        while N % i == 0:
            N = N / i
            B.append(i)

for i in B:
    print(i)

## 서칭
N = int(input())

if N == 1:
    print('')

for i in range(2, N+1):
    if N % i == 0:
        while N % i == 0:
            print(i)
            N = N / i


# BJ 10214
T = int(input())

for i in range(T):
    A,B = 0,0
    for i in range(9):
        a,b = map(int, input().split())
        A += a
        B += b   
    if A > B:
        print('Yonsei')
    elif A == B:
        print('Draw')
    elif A < B:
        print('Korea')