# # OJ 1 / BJ 11966
# # 1번 if in
# N = int(input())
# A = []

# for i in range(0,31): # 0부터면 range()에 끝값만 입력하면됨
#     A.append(2**i)
    
# if N in A:
#     print(1)
# else:
#     print(0)

# # 2번 비트연산
# N = int(input())

# if N > 0 and (N & (N - 1)) == 0: # 컴퓨터 2진수 표현으로 N과 N-1을 비트연산하면 AND 값이라 무조건 0나옴
#     print(1)
# else:
#     print(0) 

# # OJ 2 / BJ 2480
# A,B,C = map(int, input().split())

# if A == B == C:
#     print(10000 + A*1000)

# elif A == B != C:
#     print(1000 + A*100)

# elif A != B == C:
#     print(1000 + B*100)

# elif A == C != B:
#     print(1000 + A*100)

# elif A != B != C:
#     print(100*max(A,B,C))

# # OJ 3
# T = int(input())

# for i in range(0,T):
#     A,B = map(int, input().split())
#     print(A+B)

# # OJ 4
# while True:
#     A,B = map(int, input().split())
#     if A == B == 0:
#         break
#     else:
#         print(A+B)

# # OJ 5 / BJ 2739
# N = int(input())

# for i in range(1,10):
#     print(N, "*", i, "=", N*i)

# # OJ 6 / BJ 2839
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
 
# # OJ 7 / BJ 8958
# N = int(input())

# for i in range(N):
#     A = list(input())
#     B = 0 # 총점적립
#     C = 0 # 추가점수 적립
#     for i in A: # A 안의 i에 대해서
#         if i == 'O':
#             C += 1
#             B = B + C
#         elif i == 'X':
#             C = 0
#     print(B)

# # 입력받은 각 문자를 리스트의 요소로 변환
# A = list(input())
# # 공백을 기준으로 입력받은 문자를 리스트의 요소로 변환
# A = list(map(str, input().split()))