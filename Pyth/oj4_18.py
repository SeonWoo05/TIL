# 1 ( BJ 3009 )

# A = list(map(int, input().split()))
# B = list(map(int, input().split()))
# C = list(map(int, input().split()))
# D = []

# for i in range(2):
#     if A[i] == B[i]:
#         D.append(C[i])
#     if A[i] == C[i]:
#         D.append(B[i])
#     if B[i] == C[i]:
#         D.append(A[i])

# print(*D)


# # 2 ( BJ 7785 )
#### 딕셔너리 해시테이블 공부하기
# N = int(input())

# for i in range(N):


# # 3 ( BJ 10988 )
# def fel(X):
#     for i in range(len(X)):
#         if X[i] == X[-(i+1)]:
#             continue
#         else:
#             return 0
#     else:
#         return 1

# N = input()
# print(fel(N))
    

# # 4 ( BJ 5597 )
# A = [i for i in range(1,31)]
# B = []
# for i in range(28):
#     C = int(input())
#     B.append(C)

# for i in range(28):
#     A.remove(B[i])

# for i in range(2):
#     print(A[i])


# # 5 ( BJ 3052 )
# A = set()

# for i in range(10):
#     N = int(input())
#     M = N % 42
#     A.add(M)

# print(len(A))