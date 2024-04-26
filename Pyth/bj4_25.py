# BJ 2745
N, b = input().split()
ary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" # 값과 인덱스를 이용하자

N = N[::-1] #### 뒤집기 => 자릿수를 맞추기 위해
result = 0

for i,j in enumerate(N): # i : index , j : value
    result += (int(b)**i)*ary.index(j) # 진수계산방법

print(result)

# ABCDE 라고 한다면 b진법에서 지수가 0부터 커지므로 E를 앞으로 가져오고,
# (그 E의 ary에서의 index 값)과 (b의 i승)을 곱해주면 된다.

