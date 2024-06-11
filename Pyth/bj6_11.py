# BJ 10610
N = input()
A = list(map(int, N))
A.sort(reverse=True)

B = []
for i in A:
    B.append(str(i))

if A[-1] != 0:
    print(-1)

elif sum(A) % 3 != 0:
    print(-1)

else:
    C = "".join(B)
    print(C)  
    

# BJ 1476
A = list(map(int, input().split()))
E = 0
S = 0
M = 0
cnt = 0

while True:
    E += 1
    S += 1
    M += 1
    cnt += 1

    if E == 16:
        E = 1
    if S == 29:
        S = 1
    if M == 20:
        M = 1

    if A[0] == E and A[1] == S and A[2] == M:
        break # while문 벗어나려면 break

print(cnt)