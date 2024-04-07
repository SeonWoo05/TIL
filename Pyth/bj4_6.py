# BJ 5597
A = list(range(1,31)) #list() 안에 range() 넣기

for i in range(1,29):
    N = int(input())
    A.remove(N)

print(min(A))
print(max(A))


# BJ 2441
N = int(input())

for i in range(0,N):
    print((' ' * i) + '*' * (N - i))

# BJ 8393
N = int(input())
A = 0

for i in range(1, N+1):
    A += i
    
print(A)


# BJ 10871
N,X = map(int, input().split())

# N개의 정수를 입력받아 리스트를 만드는 과정이 안됨.
A = list(map(int,input().split())) # => list 바로 만들 수 있다!

B = list(filter(lambda x: x < X, A))
print(*B) ################################ 혁명적이다! *B 하면 []없어진다!

# 추가 방법
for i in A:
    if i < X:
        print(i, end = ' ') # 개행하지 않고 end를 공백으로 설정해서 이어서 출력