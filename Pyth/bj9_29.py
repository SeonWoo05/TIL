N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

dic = {}

for i in A:
  if i in dic:
    dic[i] += 1
  else:
    dic[i] = 1

for j in B:
  if j in dic:
    print(dic[j], end=' ')
  else:
    print(0, end=' ')