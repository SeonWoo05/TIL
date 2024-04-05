# BJ 10952
while True:
    A,B = map(int, input().split())
    if A != 0 and B != 0:
        print(A+B)
    elif A == B == 0:
        break

# BJ 10951
# 무한루프라서 종료가 필요함
while True:
    try:
        A,B = map(int, input().split())
        print(A+B)
    except:
        break # try와 except를 이용해서 다른값 들어오면 종료하도록 함

# BJ 25304
total = int(input())
type_num = int(input())
C = 0

for i in range(type_num):
    A,B = map(int, input().split())
    C += A * B

if C == total:
    print('Yes')
else:
    print('No')