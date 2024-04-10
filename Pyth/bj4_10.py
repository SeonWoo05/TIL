# BJ 1546
N = int(input())
A = list(map(int, input().split()))
A.sort() 
B = 0

for i in range(N):
	B += A[i]/A[-1]*100

print(B / N)


# BJ 2750
N = int(input())
A = [0] * N

for i in range(N):
    A[i] = int(input())

A.sort()

for i in A:
    print(i)


# BJ 10039
A = [0] * 5
B = 0

for i in range(5):
    A[i] = int(input())
    
    if A[i] < 40:
        A[i] = 40
    
    B += A[i]

print(int(B/5))


# BJ 10809
A = list(input())
aList = [chr(i) for i in range(ord('a'),ord('z')+1)]
B = []

for i in aList:
    if i in A:
        B.append(A.index(i))
    else:
        B.append(-1)
    
print(*B)


# BJ 9095  ### 머리가 안돌아가요 / 다시 풀어야 함
T = int(input())
A = []

for i in range(T):
    A[i] = int(input())
