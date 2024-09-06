# # BJ 2563
# N = int(input())
# A = [[0]*100 for _ in range(100)] # _ : 반복 횟수만 필요하고 변수는 사용하지 않음


# for _ in range(N):
#     B,C = map(int, input().split())

#     for i in range(B,B+10):
#         for j in range(C,C+10):
#             A[i][j] = 1

# cnt = 0
# for k in range(100): # 행에 대해 1개수 세기 반복
#     cnt += A[k].count(1)

# print(cnt)


# BJ 2566
A = []

for _ in range(9):
    B = list(map(int, input().split()))
    A.append(B)

maxint = 0
for i in range(9):
    for j in range(9):
        if maxint < A[i][j]:
            maxint = A[i][j]

print(maxint)

for i, row in enumerate(A):  # i는 행의 인덱스, row는 각 행(리스트)
        if maxint in row:
            print(i+1, row.index(maxint)+1)
            break
        
## 최적화 코드
A = [list(map(int, input().split())) for _ in range(9)]

maxint = 0
max_row, max_col = 0, 0

for i in range(9):
    for j in range(9):
        if A[i][j] > maxint:
            maxint = A[i][j]
            max_row, max_col = i + 1, j + 1  # 행과 열을 1부터 시작하는 값으로 저장

print(maxint)
print(max_row, max_col)