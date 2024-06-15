# 백설공주 난쟁이 pop이용 index 제거로 풀이
A = []
for i in range(9):
    A.append(int(input()))

found = False
for i in range(8):
    for j in range(i+1,9):
        if A[i] + A[j] == sum(A) - 100:
            A.pop(i) # B = A.pop(i) 해서 제거된 원소도 확인가능
            A.pop(j-1)
            found = True
            break
    if found:
        break

for i in A:
    print(i)


# 딕셔너리
N = int(input())
A = {}
for i in range(N):
    a,b = input().split()
    A[a] = b

for i,j in enumerate(A):
    i = int(i)
    j = int(j)
    print(i+j)

# 딕셔너리로 개수세기
S = input()
A = {}
for i in S:
    if i in A:
        A[i] += 1
    if i not in A:
        A[i] = 1

print(A)


# 함수 실습
# 숫자 놀이
def iter_sum(num):
	B = []
	for i in num:
		B.append(int(i))
	if sum(B) <= 9:
		return sum(B)
	else:
		C = sum(B)
		C = str(C)
		return iter_sum(C) # else: 문에도 return 해주는거 잊지말기

A = input()
print(iter_sum(A))


# 시험기간에 술
# 변수를 입력해서 값을 얻어야할 때 함수 유용
def caculate_days(a,b):
	if a % b == 0:
		need_day = a // b
		return need_day
	else:
		need_day = a // b +1
		return need_day

N = int(input())
A = int(input())
B = int(input())
C = int(input())
D = int(input())
free_sozu = N - max(caculate_days(A,C) , caculate_days(B,D))
print(free_sozu)


# 이상한 연산자
def at(m):
    return 3*m

def per(m):
    return 5+m

def hash(m):
    return m-7

T = int(input())
for i in range(T):
    a,b = input().split()
    a = float(a) # 다시 할당해줘야함. float(a)만 적으면 그냥 하나의 값일 뿐
    
    if b == '@':
        A = at(a)
        print(f'{A:.2f}')
        
    elif b == '%':
        A = per(a)
        print(f'{A:.2f}')

    elif b == '#':
        A = hash(a)
        print(f'{A:.2f}')


# 팩토리얼
def fac(n):
	A = 1
	while n>0:
		A *= n
		n -= 1
	return A
n = int(input())
print(fac(n))


# 깨진 바이오 리듬
def to_second(hms):
	A = hms.split(":")
	h = int(A[0])
	m = int(A[1])
	s = int(A[2])
	n = 0
	n += 3600*h
	n += 60*m
	n += s
	return n

def diff(cu,th):
	n = to_second(cu)
	m = to_second(th)
	diff = m-n
	if diff <= 0:
		diff = 24*3600 + diff
	return diff 


def print_time(sec):
	h = sec // 3600
	sec = sec % 3600
	m = sec // 60
	sec = sec % 60
	s = sec
	print(f'{h:02d}:{m:02d}:{s:02d}')

cu= input()
th = input()
print_time(diff(cu,th))


# 펠린드롬인지 확인하기
A = input()
B = []
for i in A:
    B.append(i)
if B == list(reversed(B)):
    print(1)

else:
    print(0)


# 소수 - 항상 1생각 / 자신의 양의 제곱근 이하의 배수만 다 제거
a,b = map(int, input().split())
for i in range(a,b+1):
    if i == 1: # 1은 소수가 아니므로 제거
        continue
    for j in range(2,int(i**(1/2))+1):
        if i % j == 0: # 자신의 양의 제곱근 이하의 배수만 다 제거
            break # 약수 있으면 바로 for문 탈출
    else:
        print(i)

# 함수를 이용한 풀이
def find_sosu(a,b):
    C = []
    for i in range(a,b+1):
        if i == 1:
            continue
        else:
            C.append(i)
    B = []

    for i in C:
        for j in range(2,int(i**(1/2))+1):
            if i % j == 0:
                break
        else:
            B.append(i)
    return B
                

a,b = map(int, input().split())
for i in find_sosu(a,b):
    print(i)


# BJ 10799
N = input()
arr = []
cnt = 0

for i in range(len(N)):
    if N[i] == "(":
        arr.append(i)

    else:
        if N[i-1] == "(":
            arr.pop()
            cnt += len(arr)
        else:
            arr.pop()
            cnt += 1
print(cnt)