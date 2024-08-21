# BJ 2096
N = int(input())
A = list(map(int, input().split()))
B = A[:] # or A.copy() / 이렇게 안하면 A가 변경되면 B도 변경됨

for i in range(N-1):
    C = list(map(int, input().split()))
    
    A[0] = max(A[0], A[1]) + C[0]
    A[1] = max(A[0], A[1], A[2]) + C[1]
    A[2] = max(A[1], A[2]) + C[2]
    
    B[0] = min(B[0], B[1]) + C[0]
    B[1] = min(B[0], B[1], B[2]) + C[1]
    B[2] = min(B[1], B[2]) + C[2]

print(max(A), min(B))
# 이 코드의 문제점 : A[0] = 설정하고나면 다음 A[1]에서 A[0]가 변경되어있음
# 현재값을 저장해두고 업데이트 해야함

# 수정된 코드
N = int(input())
A = list(map(int, input().split()))
B = A[:]

for i in range(N-1):
    C = list(map(int, input().split()))
    
    temp_A = A[:]
    temp_B = B[:]

    A[0] = max(temp_A[0], temp_A[1]) + C[0]
    A[1] = max(temp_A[0], temp_A[1], temp_A[2]) + C[1]
    A[2] = max(temp_A[1], temp_A[2]) + C[2]
    
    B[0] = min(temp_B[0], temp_B[1]) + C[0]
    B[1] = min(temp_B[0], temp_B[1], temp_B[2]) + C[1]
    B[2] = min(temp_B[1], temp_B[2]) + C[2]

print(max(A), min(B))

# 다 저장해두면 메모리 초과 이슈 발생 => 슬라이딩 윈도우

# 슬라이딩 윈도우란?
# 메모이제이션을 할 때, 사용하지 않는 값을 배열에 저장하지 않고 배열을 새롭게 계속해서 갱신시켜주는 것