### List Comprehension
# iterable 객체를 for-loop에서 반복하여 한번에 하나씩 요소를 반환하며 리스트를 생성
# newlist = [expression for 변수 in iterable 객체 if 조건식]
result = []
for i in range(5):
    result.append(i**2)
print(result)

# Use list comprehension
result = [i**2 for i in range(10)]
print(result)

# 문자열 각각을 대문자로 반환
st = 'Hello World'
s_list = [x.upper() for x in st] # 반환값이 x.upper 이다다
print(s_list)

# if 조건식을 이용한 필터링
even_num = [x for x in range(1,10) if x % 2 == 0]
print(even_num)

# if 조건식으로 더 많은 조건 추가 가능 - 2,3,5의 배수 구하기
A = [n for n in range(1,61) if n % 2 == 0 if n % 3 == 0 if n % 5 == 0]
print(A)

### Generator : 직접 값을 포함하지 않고 값을 생성하는 방법
# 제너레이터 객체는 모든 값을 메모리에 올려두지 않고, 필요할 때마다 생성해서 반환 - 메모리 효율
# 반복자와 다른 점은 미리 메모리에 만들어 두는 것이 아니라 for문에서 필요로 할때마다 반환해서 사용
def create_gen():
    alist = range(1,4)
    for x in alist:
        yield x # return과 유사한 yield문을 사용하여 generator객체 반환

my_generator = create_gen()
print(my_generator)
for n in my_generator:
    print(n)


### 1. 람다 함수 : 1회용의 간단한 함수를 만드는 것
add = lambda x,y: x+y
print(add(100,200))

# 인라인으로도 가능
print('100 + 200 :', (lambda x,y: x+y)(100,200))


### 2. 필터 함수 : filter(적용시킬 함수, iterable 객체)
ages = [34, 39, 20, 18, 13, 54]
print('성년 리스트 :')
for a in filter(lambda x: x>= 19, ages):
    print(a, end=' ')
print()

# 필터, 람다 함수를 이용한 음수 값 추출기능
n_list = [-30, 45, -5, -90, 20, 53, 77, -36]
minus_list = []

for n in filter(lambda x: x < 0, n_list):
    minus_list.append(n)
print(minus_list)


### 3. 맵 함수 : iterable 객체의 요소들을 함수에 넣어 동시에 적용하여 map object로 반환
# map(적용시킬 함수, iterable, ...)
def square(x):
    return x**2

a = [1,2,3,4,5,6,7]
square_a = list(map(square,a))
print(square_a)

# 람다 함수를 이용하면 간결한 표현식으로 리스트의 요소들을 변환할 수 있다.
square_a = list(map(lambda x: x**2,a))
cubic_a = list(map(lambda x: x**3,a))
print(square_a)
print(cubic_a)


### 리듀스 함수 : iterable의 각 elemet를 왼쪽부터 오른쪽으로 function을 적용하여 하나의 값으로 합친다.
# reduce(적용시킬 함수, iterable)
from functools import reduce
a = [1,2,3,4]

n = reduce(lambda x, y: x * y, a)
print(n)


### 6. 반복자
# iterable : 반복 가능한 객체 / list, dict, set, str, bytes, tuple, range ...

# 리스트와 튜플, 정수 값을 반복자 객체로 변환시키기
try:
    l = [10, 20, 30]
    iterator = iter(l)
except TypeError:
    print('list는 iterable 객체가 아닙니다.')
else:
    print('list는 iterable 객체입니다.')

try:
    t = ('홍길동', 20, 30)
    iterator = iter(t)
except TypeError:
    print('tuple은 iterable 객체가 아닙니다.')
else:
    print('tuple은 iterable 객체입니다.')

try:
    n = 200
    iterator = iter(n)
except TypeError:
    print('int는 iterable 객체가 아닙니다.')
else:
    print('int는 iterable 객체입니다.')


### +) try, except 문
# try와 except 문은 파이썬에서 예외 처리를 위해 사용
try:
    # value = int(input("숫자를 입력하세요: "))
    value = 3
    result = 10 / value
except ValueError as ve:
    print("유효한 숫자가 아닙니다.", ve)
except ZeroDivisionError as zde:
    print("0으로 나눌 수 없습니다.", zde)
else:
    print(result) # try 블록에서 예외가 발생하지 않으면 else 블록이 실행됨

# 모든 예외를 포괄적으로 처리 - 예외 타입 지정x
try:
    result = 10 / 0
except:
    print("예외가 발생했습니다.")


### split(), join() 메서드
# split() : sep으로 구분된 리스트를 만든다
time_str = '2024.05.28'
print(time_str.split('.'))

# join() : sep으로 구분하여 합쳐진 리스트의 원소를 하나로 합친다 / '구분자'.join(리스트)
time_list = ['2024', '05', '28']
print('.'.join(time_list))