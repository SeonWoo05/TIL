# BJ 1920
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

C = []

for i in B:
    if i in A:
        print(1)
    else:
        print(0)


# BJ 7785
N = int(input())
A = {}

for i in range(N):
    x,y = input().split() # 나누어 담고
    if y == 'enter': # value가 enter이면 dict에 추가
        A[x] = y # A[key] = value 구조
    elif y == 'leave':
        A.pop(x) # pop(key)로 제거

for i in sorted(A,reverse=True):
    print(i)


# BJ 1026
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)
C = []

for i in range(N):
    C.append(A[i] * B[i])

print(sum(C))


# BJ 1427
A = input()
A = list(map(int,A))
A.sort(reverse=True)
B = []

for i in A:
    B.append(str(i))
C = ''.join(B) # 하나의 문자열로 바꿔놓고 sort() 안됨. 미리 내림차순 만들고 join()
print(C)