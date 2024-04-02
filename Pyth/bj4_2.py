# BJ 2480
map(int, input().split())

if A == B == C:
    print(10000 + (A * 1000))
        
elif A == B != C:        
    print(1000 + (A * 100))

elif A != B == C:        
    print(1000 + (B * 100))

elif A == C != B:        
    print(1000 + (A * 100))

elif A != B != C:
    print(max(A,B,C) * 100)


# BJ 14681
A = int(input())
B = int(input())

if A > 0 and B > 0:
    print(1)

elif A > 0 and B < 0:
    print(4)

elif A < 0 and B > 0:
    print(2)

elif A < 0 and B < 0:
    print(3)

##
A = int(input())
B = int(input())

if A > 0:
    if B > 0:
        print(1)
    else:
        print(4)

if A < 0:
    if B > 0:
        print(2)
    else:
        print(3)


# BJ 2884
H,M = map(int, input().split())

if M >= 45:
    print(H, M - 45)

else:
    if H == 0:
        print(H + 23, M + 15)
    
    else:
        print(H - 1, M + 15)


# BJ 2753
A = int(input())

if (A % 4) == 0:
    if (A % 100) == 0:
        if (A % 400) == 0:
            print(1)
        
        else:
            print(0)

    else:
        print(1)

else:
    print(0)

##
A = int(input())

if(A % 4 == 0 and (A % 100 != 0 or A % 400 == 0)): # 한줄로도 표현 가능
    print(1)

else:
    print(0)


# BJ 2438
A = int(input())

for i in range(1,A+1):
    print('*' * i)


# BJ 2739
N = int(input())

for i in range(1,10):
    print(N, "*", i, "=", N*i)


# BJ 2742
N = int(input())
for i in range(0,N):
    print(N-i)

# BJ 2439
N = int(input())
for i in range(1,N+1):
    print(" " * (N-i) + "*" * i)

# BJ 2440
N = int(input())

for i in range(N):
    print("*" * (N-i))

###### BJ 1924 ###### 못품
# 1. 요일을 담은 리스트 생성
# 2. 월별 총 일수를 담은 리스트 생성
# 3. 값 입력받기
# 4. 입력받은 값의 (월-1) 만큼의 월별 총 일수를 '일' 수에 더하기
# 5. 환산된 총 일수 % 7 을 이용해서 요일의 리스트에 접근

A = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"] # 나머지가 1이어야 월요일 되도록 [0] = "SUN"
B = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] # 각 월의 일 수 리스트

M,D = map(int, input().split())

for i in range(0,M-1): #리스트의 첫번째 변수 0이므로 주의
    D += B[i]

print(A[D%7])
# 총평 : 리스트를 잘 이용하자


# BJ 10817
A,B,C = map(int, input().split())

X = [A,B,C] # X = list[ ] 이게 아니라 바로 X = []
X.sort()
print(X[-2])
