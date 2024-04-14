# BJ 1978
N = int(input())
A = list(map(int, input().split()))
sosu = 0

for i in A:
    if i == 1:
        continue # if문 그냥 지나가도록 continue 사용가능
    
    for j in range(2,i):
        if i % j == 0:
            break # if문에 break 걸어서 소수가 아니면 for문 탈출

    else: # for문에서 빠져나오면 시행하지 않음
        sosu += 1

print(sosu)