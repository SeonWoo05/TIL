### 함수공부 (map)
# map(function, iterable) : 함수는 주어진 iterable의 각 요소에 대해 function을 적용하고, 결과를 새로운 iterable로 반환
# example)
# 제곱 함수
def square(x):
    return x ** 2

# 원본 리스트
numbers = [1, 2, 3, 4, 5]

# map 함수를 사용하여 각 요소에 제곱 함수를 적용
squared_numbers = map(square, numbers) # 결과가 map 객체로 반환됨 / <map object at 0x00000>

print(list(squared_numbers)) #list 씌워주기

### 함수공부 (sort)
# sort() : 메서드는 리스트의 요소들이 오름차순으로 정렬됩니다.
# 원본 리스트를 변경한다: 호출된 리스트 자체를 변경하며, 새로운 리스트를 반환하지 않습니다.
# 기본 정렬 방식은 오름차순. 이는 숫자의 경우 작은 값부터 큰 값 순서로, 문자열의 경우에는 사전순으로 정렬됩니다.
# 내림차순 정렬: reverse 매개변수를 True로 설정하면 내림차순으로 정렬. 즉, 큰 값부터 작은 값 순서로 정렬됩니다.
# exmaple)
numbers = [3, 1, 4, 1, 5, 9, 2, 6, 5]

# 오름차순으로 정렬
numbers.sort()
print(numbers)  # 출력: [1, 1, 2, 3, 4, 5, 5, 6, 9]

# 내림차순으로 정렬
numbers.sort(reverse=True)
print(numbers)

# +) sorted(iterable, key=None, reverse=False)
# sorted() 함수는 원본 자료를 변경하지 않고 정렬된 새로운 리스트를 반환하기 때문에 sort()와는 다름.
sorted_numbers = sorted(numbers)
print(sorted_numbers)  # 출력: [1, 1, 2, 3, 4, 5, 5, 6, 9]

# 내림차순으로 정렬된 새로운 리스트 반환
sorted_numbers_reverse = sorted(numbers, reverse=True)
print(sorted_numbers_reverse)  # 출력: [9, 6, 5, 5, 4, 3, 2, 1, 1]

### 함수공부 (reversed)
# reversed() 함수는 순서가 있는(iterable) 자료형(리스트, 튜플, 문자열 등)의 요소들을 역순으로 반환하는데 사용. 새로운 반복 가능한 객체(iterator)를 반환
reversed(numbers)

# 객체들만 역순으로 추출하고 싶으면 for문에 reversed 사용
numbers = [1, 2, 3, 4, 5]

# 리스트를 역순으로 출력
for num in reversed(numbers):
    print(num)

# +) reverse()
# reverse() 메서드는 리스트의 요소들을 뒤집는 데 사용. 리스트의 요소들의 순서가 거꾸로 되며, 원본 리스트를 변경.

numbers.reverse()
print(numbers)

### 함수공부 (filter)
# filter(function, iterable) : 함수는 주어진 iterable(반복 가능한) 자료형에서 특정 조건을 만족하는 요소들을 걸러내는 데 사용

numbers = [-2, -1, 0, 1, 2, 3, 4, 5]

# 양수를 걸러냄
positive_numbers = filter(lambda x: x > 0, numbers) #list가 아니라 filter 객체가 되었음
# 반환 되는 객체가 filter라서 list(positvie_num) 이나 list(filter()) 등으로 변환 해주어야 함

### 함수공부 (lambda)
# lambda arguments: expression : lambda를 사용하면 함수를 선언할 필요 없이 한 줄로 간단한 함수를 정의. 주로 함수를 간단하게 정의할 때 사용되며, 일반적으로 다른 함수의 인자로 전달되는 작은 함수들에 많이 사용.
# lambda: 익명 함수를 선언하기 위한 키워드.
# arguments: 함수의 매개변수(parameter)를 나타냅니다. 콜론(:)의 왼쪽에 위치.
# expression: 함수의 반환값을 나타내는 표현식(expression). 콜론(:)의 오른쪽에 위치.

add = lambda x, y: x + y
result = add(3, 5) # 함수 호출
print(result)  # 출력: 8


### 함수공부 (split)
# string.split(sep=None, maxsplit=-1) : 문자열을 특정 구분자(delimiter)를 기준으로 분리하는 파이썬의 문자열 메서드 
# sep (선택 사항): 구분자(separator)로 사용할 문자열입니다. 기본값은 공백입니다. 이 구분자를 기준으로 문자열이 분리
# maxsplit (선택 사항): 분리할 최대 횟수입니다. 기본값은 -1이며, 이는 제한이 없음을 의미합니다. 만약 이 값을 설정하면, 문자열이 최대 몇 번 분리될지를 결정

text = "apple,banana,orange,grape"
fruits = text.split(',') # 쉼표를 기준으로 문자열을 분리하여 리스트로 반환
print(fruits)  # 출력: ['apple', 'banana', 'orange', 'grape']


### 함수공부 (join)
# separator.join(iterable) : 주로 리스트나 튜플과 같은 iterable 객체의 요소들을 하나의 문자열로 합치는 데 사용
# separator: 각 요소를 이어붙일 때 사이에 삽입될 문자열.
# iterable: 이어붙일 요소들을 포함하는 iterable 객체.

words = ["apple", "banana", "orange", "grape"]
text = ','.join(words) # 각 요소들을 쉼표로 구분하여 이어붙임
print(text)  # 출력: "apple,banana,orange,grape"
text = ''.join(words) # 각 요소들을 이어붙임
print(text)  # 출력: "applebananaorangegrape"

### 함수공부 (count)
# .count(value) : 주어진 값이 리스트나 문자열 등의 반복 가능한 객체 안에 몇 번 등장하는지를 세는 내장 함수
numbers = [1, 2, 3, 4, 2, 2, 3, 2, 5]

print(numbers.count(2))  # 출력: 4


### 함수공부 (round)
# round(number, ndigits) : 주어진 숫자를 지정한 소수점 자릿수에 맞추어 반올림
pi = round(3.141592, 2)
print(pi)


### 함수공부 (index)
# .index() : 리스트에서 특정 원소의 인덱스를 반환해주는 함수
# 사용 방법
#     ◻ array.index(x) 리스트에서 x의 인덱스 반환
#     ◻ array.index(x, start) 리스트[start:]에서 x의 인덱스 반환
#     ◻ array.index(x, start, stop) 리스트[start:stop]에서 x의 인덱스 반환
#         (stop은 포함되지 않음. 즉 start부터 stop-1까지의 원소들만 포함)
# ◼ 중복된 원소가 있으면 가장 작은 인덱스를 리턴
# ◼ 문자열에서도 인덱스를 찾을 수 있음


### 함수공부 (enumerate)
# enumerate(iterable, start=0) : 순회 가능한(iterable) 객체를 입력으로 받아 각 요소의 인덱스와 값을 포함하는 enumerate 객체를 반환
# start: 인덱스의 시작 값을 지정. 기본값은 0입니다.
# enumerate() 함수는 보통 for 루프와 함께 사용되며, 각 요소의 인덱스와 값을 함께 사용해야 할 때 유용
my_list = ['apple', 'banana', 'orange']

for i, value in enumerate(my_list):
    print(i,value)

# 출력: 0 apple
#       1 banana
#       2 orange
# 인덱스를 순회하면서 출력. 요소와 인덱스를 동시에 얻을 수 있다.
