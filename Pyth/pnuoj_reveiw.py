# # 3주차 변수
# # 002. A+B 개행 입력
# A = int(input())
# B = int(input())
# print(A+B)

# # 003. A+B 한 줄 입력
# A,B = map(int, input().split())
# print(A+B)

# # 004. A,B SWAP (변수)
# A,B = map(int, input().split())
# A1 = B
# B = A
# A = A1
# print(A,B)150

# # 005. ??! (문자열 덧셈)
# A = input()
# print(A+'??!')

# # 006. 단어의 개수
# A = list(map(str, input().split()))
# print(len(A))

# ################# 007. 숫자의 개수
# A = int(input())
# B = int(input())
# C = int(input())

# D = A*B*C
# E = str(D)
# F = list(map(int, E)) ######## 숫자를 리스트에 넣고 싶을때 => 문자열로 변환한 후 map함수로 다시 int로 받기
# for i in range(10):
#     print(F.count(i))



# # 4주차 연산자
# # 001. 더치페이
# A,B,C,D,E = map(int, input().split())
# total = 3000 * (A + B) + 12000 * C + 4000 * (D + E)
# print(int(total / 6)) # int()는 소수점 아래 버립니다.

# # 002. 거스름돈
# N = int(input())
# M = 1000-N
# A = [500,100,50,10,5,1]
# B = 0

# for i in A:
#     B += M // i
#     M %= i ########## 이거 빼먹지마 나머지 다시 넣어줘야함
# print(B)

# # 003. 수학은 체육과목입니다.
# N = int(input())
# print(4*N)

# # 004. 초콜릿 자르기
# N,M = map(int, input().split())
# A = (min(N,M)-1) + min(N,M) * (max(N,M)-1)
# print(A)

# # 005. 꼬리를 무는 숫자 나열
# N,M = map(int, input().split())
# R = abs((N - 1) // 4 - (M - 1) // 4)
# C = abs(((N - 1) % 4) - ((M - 1) % 4))
# print(R+C)



# # 5주차 제어문
# # 001. 2의 제곱인가?
# N = int(input())
# A = []
# for i in range(10):
#     A.append(2**i)

# if N in A:
#     print(1)

# else:
#     print(0)

# ## 다른 풀이
# N = int(input())
# A = [2**i for i in range(31)] # 리스트 컴프리헨션은 리스트를 만드는 간결하고 효율적인 방법 
# if N in A:
#     print(1)

# else:
#     print(0)

# # 002. 주사위 세개
# A,B,C = map(int, input().split())
# if A == B == C:
#     print(10000 + 1000*A)

# elif A == B or A == C:
#     print(1000 + 100*A)

# elif B == C:
#     print(1000 + 100*B)

# else:
#     print(100*max(A,B,C))

# # 003. A+B 정해진 행 수 입력
# T = int(input())
# for i in range(T):
#     A,B = map(int, input().split())
#     print(A+B)

# # 004. A+B 종료 조건이 있는 입력
# while True:
#     A,B = map(int, input().split())
#     if (A,B) == (0,0):
#         break
#     print(A+B)

# # 005. 구구단
# N = int(input())
# for i in range(1,10):
#     print(N, '*', i, '=', N*i)

# ########### 006. 설탕배달
# N = int(input())
# if N <= 7:
# 	if N == 3 or N == 5:
# 		print(1)
# 	elif N == 6:
# 		print(2)
# 	else:
# 		print(-1)
		
# elif N >= 8:
# 	if N % 5 == 0:
# 		print(N//5)
# 	elif N % 5 == 1:
# 		print((N//5) + 1)
# 	elif N % 5 == 2:
# 		print((N//5) + 2)
# 	elif N % 5 == 3:
# 		print((N//5) + 1)
# 	elif N % 5 == 4:
# 		print((N//5) + 2) # 이 짓거리 할 시간에 알고리즘 생각하기
		
# ## 다른 풀이
# N = int(input())
# A = 0

# while N >= 0: # N이 0보다 크면 반복
#     if N % 5 == 0: # 5로 나누어 떨어지면
#         A += (N // 5) # A에 몫을 더하고
#         print(A)
#         break
    
#     else:
#         N -= 3 # 떨어지지 않으면 N에서 3을 빼고
#         A += 1 # 봉지 수 1개 늘리기
# else:
#     print(-1)

# ########## 007. OX 퀴즈
# T = int(input())

# for i in range(T):
#     N = input()
#     M = list(N) # list(input()) 으로 줄이기
    
#     Bonus = 0
#     Total = 0

#     for i in M:
#         if i == "O":
#             Total += Bonus + 1
#             Bonus += 1 
            
#         else:
#             Bonus = 0
#     print(Total)