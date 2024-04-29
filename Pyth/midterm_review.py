# BJ 2607 (중간고사 1번)
N = int(input())
target = list(input())
answer = 0

for _ in range(N-1):
    compare = target[:] # target을 복사
    word = input() # 새로운 단어
    cnt = 0

    for w in word: # 새로운 단어에 있는 스펠링이
        if w in compare: # target의 복사에도 있으면
            compare.remove(w) # 제거
        else:
            cnt += 1 # 없으면 카운트

    if cnt < 2 and len(compare) < 2: # 카운트가 2보다 작고(target에 없는 스펠링이 한개이하)
        answer += 1 # target의 복사에도 1개 이하의 스펠링만 남았으면 더하기 1

print(answer)


# BJ 3040 (2번)
A = []

for i in range(9):
    X = int(input())
    A.append(X)

total = 100
B = []

for i in range(len(A)):
    for j in range(i+1,len(A)):
        if A[i] + A[j] + total == sum(A):
            B.append(A[i])
            B.append(A[j])

C = []

for i in A:
    if i not in B:
        C.append(i)

C = sorted(C)

for i in C:
    print(i)