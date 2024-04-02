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
#
numbers = [-2, -1, 0, 1, 2, 3, 4, 5]

# 양수를 걸러냄
positive_numbers = filter(lambda x: x > 0, numbers) #list가 아니라 filter 객체가 되었음
