# # 묶인데이터타입 3문제 내고싶은거 있는데 좀 쉽게 - 퀴즈난이도                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
# # 제어문 2문제 어렵게 - 난이도조절


# ### 7주차 실습 복습
# # 1.
# A = list(map(int, input().split()))
# B = list(map(int, input().split()))
# C = list(map(int, input().split()))
# D = []

# for i in range(2):
# 	if A[i] == B[i]:
# 		D.append(C[i])
# 	elif A[i] == C[i]:
# 		D.append(B[i])
# 	elif B[i] == C[i]:
# 		D.append(A[i])

# print(*D)


# # 2.
# N = int(input())
# X = {}

# for i in range(N):
#     A,B = input().split()
#     if B == 'enter':
#         X[A] = B # 원소 추가
#     elif B == 'leave':
#         del X[A]

# for i in sorted(X.keys(), reverse=True):
#     print(i)


# # 3.
# A = list(input())
# B = list(reversed(A))

# for i in range(len(A)):
#     if A[i] == B[i]:
#         continue
#     elif A[i] != B[i]:
#         print(0)
#         break

# else:
#     print(1)


# # 4.
# A = [a for a in range(1,31)]

# for i in range(28):
#     N = int(input())
#     A.remove(N)

# for i in A:
#     print(i)


# # 5.
# A = []

# for i in range(10):
#     N = int(input())
#     A.append(N % 42)

# B = set(A)
# print(len(B))


### 백준 복습

# # BJ 1463
# A = int(input())
# dp = [0] * (A+1)

# for i in range(2,A+1):
#     dp[i] = dp[i-1]+1

#     if i%2 == 0:
#         dp[i] = min(dp[i],dp[i//2]+1)
#     if i%3 == 0:
#         dp[i] = min(dp[i],dp[i//3]+1)

# print(dp[A])

# A = input()
# B = list(map(str, A))
# C = list(A)
# print(B)
# print(C)


# # BJ 11557
# T = int(input())

# for i in range(T):
# 	N = int(input())
# 	A = []
# 	B = []
# 	for i in range(N):
# 		a,b = input().split()
# 		A.append(a)
# 		B.append(int(b))
# 	C = max(B)
# 	D = B.index(C)
# 	print(A[D])


# # BJ 9095     ####### 문제 못풀겠으면 계속 손으로 계산해서라도 입력하기
# T = int(input())
# DP = [0] * 11
# DP[1] = 1
# DP[2] = 2
# DP[3] = 4
# DP[4] = 7
# for i in range(5,11):
# 	DP[i] = DP[i-1] + DP[i-2] + DP[i-3]

# for i in range(T):
# 	A = int(input())
# 	print(DP[A])


# # 2579
# N = int(input())
# stairs = [0] * 300

# for i in range(N):
#     stairs[i] = int(input())

# dp = [0] * 301
# dp[0] = stairs[0]
# dp[1] = stairs[0] + stairs[1]
# dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2])

# for i in range(3,N):
#     dp[i] = max(stairs[i] + stairs[i-1] + dp[i-3] , dp[i-2] + stairs[i])

# print(dp[N-1])