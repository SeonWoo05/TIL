# BJ 2581
N = int(input())
M = int(input())

def Sosu(N,M):
    A = []

    for i in range(N,M+1):
        A.append(i)

    
    for j in range(N,M+1):
        for k in range(2,int(j**(1/2))+1):
            if j % k == 0:    # 나누어 떨어지는지는 % 입니다... //는 몫이에요...
                A.remove(j)
                break
    if 1 in A:
        A.remove(1)

    if len(A) == 0:
        print(-1)
    
    else:
        print(sum(A))
        print(min(A))

Sosu(N,M)


# BJ 3036
N = int(input())

def Ring(N):
    A = list(map(int, input().split()))

    for i in range(1,len(A)):
        B = A[0] / A[i]

        if B % 1 == 0:
            print(str(int(B)) + '/' + str(1)) # B가 3.0 , 4.0 이렇게 소수점 첫째까지 나와있음. 그래서 바로 str(B)하면 오답
            C = []
            for j in range(1,min(A[0],A[i])+1):
                if A[0] % j == 0 and A[i] % j == 0:
                    C.append(j) 
            
            D = max(C)

            print(str(int(A[0] / D)) + '/' + str(int(A[i] / D)))

Ring(N)

## 다른 풀이
def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a%b) # 최대 공약수 구하는 함수

N = int(input())
rings = list(map(int, input().split()))

for i in range(1,N):
    t = gcd(rings[0],rings[i])
    print(f'{rings[0] // t}/{rings[i] // t}')