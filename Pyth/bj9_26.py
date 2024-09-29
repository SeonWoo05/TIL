# BJ 12847
'''
A,B = map(int, input().split())
C = list(map(int, input().split()))

curr_sum = sum(C[:B])
max_sum = sum(C[:B]) # 처음부터 B-1까지 합

for i in range(B,A):
    curr_sum = curr_sum + C[i] - C[i-B]
    max_sum = max(curr_sum, max_sum)

print(max_sum)
'''

# 2557
A,B = map(int, input().split())
C = list(map(int, input().split()))

curr_sum = sum(C[:B])
max_sum = curr_sum

for i in range(B,A):
    curr_sum = curr_sum + C[i] - C[i-B]
    max_sum = max(curr_sum, max_sum)

print(max_sum)