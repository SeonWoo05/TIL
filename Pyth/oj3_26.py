#OJ 2
A = int(input())
B = int(input())
print(A+B)

#OJ 3
A,B = map(int, input().split())
print(A+B)

#OJ 4
A,B = map(int, input().split())
Bb = B
B = A
A = Bb
print(A, B)

#OJ 5
id = input()
print(id+"??!")

#OJ 6 (BJ 1152)
x = list(map(str, input().split()))
print(len(x))
## map : 입력된 값을 여러 변수에 나누어 담아주는 함수
## .split : 어디서 끊을지. ()안이 비어있으면 공백단위
## 리스트에 split으로 끊긴 단어들이 하나씩 들어감

#OJ 7 (BJ 2577)
A = int(input())
B = int(input())
C = int(input())
num = A * B * C
digits = list(map(int, str(num)))
for i in range(10):
    print(digits.count(i))

## 다른 풀이
a = int(input())
b = int(input())
c = int(input())

mul = str(a*b*c)

for i in range(10):
  print(mul.count(str(i)))