# https://www.codetree.ai/missions/2/problems/n-permutations-of-k-with-repetition?&utm_source=clipboard&utm_medium=text
# k개 중에 1개를 N번 뽑기

# K, N = map(int, input().split())

# arr = [i + 1 for i in range(K)]
# ans = [0] * N

# def recur(depth):
#     if depth == N:
#         for i in range(N):
#             print(ans[i],end=' ')
        
#         print()
#         return
    
#     for i in range(K):
#         ans[depth] = arr[i]
#         recur(depth + 1)

# recur(0)


# https://www.codetree.ai/missions/2/problems/beautiful-number?&utm_source=clipboard&utm_medium=text
# 아름다운 수 - 1~4 사이의 수로 n자리 생성
# 해당 숫자만큼 연달아 같은 숫자가 나오는지

# n = int(input())
# ans = 0
# seq = []

# def is_beautiful(): 
#     i = 0
#     while i < n:
#         if i + seq[i] > n: # 배열의 시작 index와 그 값이 n을 넘어가면 바로 return
#             return False # n = 5 일때 index가 4, 값이 4면 이미 불가능

#         for j in range(i, i + seq[i]): # 그 index의 값만큼 반복 할동안
#             if seq[j] != seq[i]: # 계속 같은 숫자여야만 통과
#                 return False

#         i += seq[i] # 그 값만큼 검사했으니 index 이동시킴
#     return True

# def count_beautiful_seq(depth):
#     global ans
#     if depth == n: # 종료 조건
#         if is_beautiful():
#             ans += 1
#         return
    
#     for i in range(1, 5):
#         seq.append(i)
#         count_beautiful_seq(depth + 1)
#         seq.pop() # 이전문제와 다르게 대입하는 방식이 아니고 추가하는 방식이라서 pop 해줘야함

# count_beautiful_seq(0)
# print(ans)