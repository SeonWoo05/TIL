# 문자열 처리

# BJ 10808
S = input()
D = {'a':0,
     'b':0,
     'c':0,
     'd':0,
     'e':0,
     'f':0,
     'g':0,
     'h':0,
     'i':0,
     'j':0,
     'k':0,
     'l':0,
     'm':0,
     'n':0,
     'o':0,
     'p':0,
     'q':0,
     'r':0,
     's':0,
     't':0,
     'u':0,
     'v':0,
     'w':0,
     'x':0,
     'y':0,
     'z':0}

for i in S:
    D[i] += 1

print(*D.values())


# BJ 10809
S = input()

D = {'a':-1,
     'b':-1,
     'c':-1,
     'd':-1,
     'e':-1,
     'f':-1,
     'g':-1,
     'h':-1,
     'i':-1,
     'j':-1,
     'k':-1,
     'l':-1,
     'm':-1,
     'n':-1,
     'o':-1,
     'p':-1,
     'q':-1,
     'r':-1,
     's':-1,
     't':-1,
     'u':-1,
     'v':-1,
     'w':-1,
     'x':-1,
     'y':-1,
     'z':-1}

for i in range(len(S)):
    if D[S[i]] == -1:
        D[S[i]] += i + 1

print(*D.values())


# BJ 2743
S = input()
print(len(S))


# BJ 10824
A = list(map(str, input().split()))
B = []
B.append(A[0])
B.append(A[1])
C = []
C.append(A[2])
C.append(A[3])

B = "".join(B)
C = "".join(C)

B = int(B)
C = int(C)
print(B+C)


# BJ 11656
S = input()
A = []
for i in S:
    A.append(i)

B = []
for i in range(len(A)):
    C = "".join(A)
    B.append(C)
    A.pop(0)

B.sort()
for i in B:
    print(i)