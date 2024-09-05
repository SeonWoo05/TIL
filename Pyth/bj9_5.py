N,M = map(int, input().split())
A = []
B = []
for i in range(N): # N개의 열 입력받아야함
    C = list(map(int, input().split()))
    A.append(C)
for i in range(N):
    C = list(map(int, input().split()))
    B.append(C)

D = [[0] * M for _ in range(N)] # [0]*M => M개의 열, N개의 행

for i in range(N):
    for j in range(M):
        D[i][j] = A[i][j] + B[i][j]

for row in D:
    print(*row)

## 최적화
# 결과 리스트 D를 생성하면서 A와 B의 합을 동시에 계산
D = []
for i in range(N):
    A = list(map(int, input().split()))  # A 행 입력
    B = list(map(int, input().split()))  # B 행 입력
    D.append([A[j] + B[j] for j in range(M)])  # 각 원소를 더해서 D에 추가