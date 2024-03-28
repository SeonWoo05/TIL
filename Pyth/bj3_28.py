#BJ 2741
A = int(input())
for i in range(1,A+1):
    print(i)

# BJ 10998
A,B = map(int, input().split()) #이건 좀 외우자
print(A*B)

# BJ 2588
A = int(input())
B = int(input())

print(A * (B % 10))
print(A * ((B//10) - 10 * (B//100))) # B % 100 //10 : 100으로 나눈 나머지를 10으로 나눈 몫
print(A * (B // 100))
print(A * B)

## 다른 풀이 
a = int(input())
b = str(input()) #str으로 형변환을 해주지 않으면 b[2]에서 에러가 난다. 

a1 = int(b[2]) * a
a2 = int(b[1]) * a
a3 = int(b[0]) * a
print(a1, a2, a3, a * int(b))

## 다른 풀이 2
a = int(input())
b = str(input())

for i in range(2, -1, -1): #[2]이하부터 [-1]초과까지 == [2]~[0] 
  print(int(b[i]) * a)
print(a * int(b))

# # range() 함수 이용법
# Python의 range() 함수는 세 가지 매개변수를 가질 수 있습니다.

# start (시작 값, 포함됨)
# stop (종료 값, 포함되지 않음)
# step (증가량 또는 감소량)