# Quiz2 카드게임
Acount = 0
Bcount = 0

A = list(map(int, input().split()))
B = list(map(int, input().split()))
	
for j in range(10):
	if A[j] > B[j]:
		Acount +=1
	elif A[j] < B[j]:
		Bcount +=1

if Acount > Bcount:
	print('A')
elif Acount < Bcount:
	print('B')
elif Acount == Bcount:
	print('D')


# 1 ( BJ 3009 )
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
D = []

for i in range(2):
    if A[i] == B[i]:
        D.append(C[i])
    if A[i] == C[i]:
        D.append(B[i])
    if B[i] == C[i]:
        D.append(A[i])

print(*D)


# 2 ( BJ 7785 ) # 딕셔너리로 풀어보기
# 내가 만든 리스트 방식은 enter leave에 따라 반응하지 못함.
N = int(input())

state = {}

for i in range(N):
    A,B = input().split()   ## 문자열을 이렇게 두개 받을 수 있다!
    
    if B == 'enter':
        state[A] = B

    elif B == 'leave':
        del state[A]

for i in sorted(state.keys(), reverse=True):
    print(i)

# 3 ( BJ 10988 )
def fel(X):
    for i in range(len(X)):
        if X[i] == X[-(i+1)]:
            continue
        else:
            return 0
    else:
        return 1

N = input()
print(fel(N))
    

# 4 ( BJ 5597 )
A = [i for i in range(1,31)]
B = []
for i in range(28):
    C = int(input())
    B.append(C)

for i in range(28):
    A.remove(B[i])

for i in range(2):
    print(A[i])


# 5 ( BJ 3052 )
A = set()

for i in range(10):
    N = int(input())
    M = N % 42
    A.add(M)

print(len(A))