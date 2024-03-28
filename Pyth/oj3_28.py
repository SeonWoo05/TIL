# OJ 1
A,B,C,D,E = map(int,input().split())
total = 3000 * (A+B) + 12000 * C + 4000 * (D+E)
print(int(total/6))

# OJ 2 - 구글링했음!
changes = [500,100,50,10,5,1] #리스트 만들어서 반복문에 대입
A = int(input()) 
B = 1000 - A # '1000엔 한 장 냈을 때' 라는 조건 확인
C = 0

for i in changes :
    C += B // i
    B %= i # i로 나눈 나머지를 다시 B에 넣고 다음 잔돈으로 다시 몫 구하기
print(C)

# OJ 3
n = int(input())
print(4*n)

# OJ 4
N,M = map(int, input().split())
if N <= M:
    print((M-1)+(N-1)*M)
if N > M:
    print((N-1)+(M-1)*N)

# OJ 5
a,b = map(int,input().split())
print(abs(((a-1)//4) - ((b-1)//4)) + abs((a-1)%4 - (b-1)%4))