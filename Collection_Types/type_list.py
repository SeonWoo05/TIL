### 리스트의 메서드들

### list에 값을 추가하는 세가지 메서드
# append(), insert(), extend()의 차이점
# append(): 리스트의 끝에 요소를 추가. 추가하려는 요소를 인자로 전달. 리스트에 요소를 하나만 추가할 때 사용.
my_list = [1, 2, 3]

my_list.append(4) # 리스트의 끝에 요소 4를 추가
print(my_list)  # 출력: [1, 2, 3, 4]

# insert(): 리스트의 특정 위치에 요소를 추가. 추가하려는 요소와 위치(인덱스)를 인자로 전달. 다른 요소들을 뒤로 밀어내고 삽입.
my_list = [1, 2, 3]

my_list.insert(1, 4) # 인덱스 1 위치에 요소 4를 추가
print(my_list)  # 출력: [1, 4, 2, 3]

# extend(): 리스트의 끝에 iterable 객체(리스트, 튜플 등)의 모든 요소를 추가. 추가하려는 iterable 객체를 인자로 전달.
my_list = [1, 2, 3]
new_elements = [4, 5]

my_list.extend(new_elements) # 리스트의 끝에 iterable 객체인 new_elements의 모든 요소를 추가)
print(my_list)  # 출력: [1, 2, 3, 4, 5]

# append와 extend의 차이점 :
# append([55,66]) 하면 리스트 안에 리스트가 들어가고,
# extend([55,66]) 하면 리스트 안에 55,66 의 원소로 추가된다.



### list에 값을 삭제하는 세가지 메서드
# remove(), pop(), clear()의 차이점
# remove(): 리스트에서 특정 값을 제거. 제거하려는 값을 인자로 전달. 만약 중복된 값이 있을 경우, 가장 먼저 발견된 값만 제거.
my_list = [1, 2, 3, 2]

my_list.remove(2) # 리스트에서 '값' 2를 제거
print(my_list)  # 출력: [1, 3, 2]

# pop(): 리스트에서 지정된 '인덱스'에 해당하는 요소를 제거, 그 제거된 요소를 반환. '인덱스를 인자'로 전달. 만약 인덱스를 지정하지 않으면 마지막 요소가 제거됨.
my_list = [1, 2, 3]

removed_element = my_list.pop(1) # 인덱스 1 위치에 있는 요소를 제거하고 반환
print(removed_element)  # 출력: 2
print(my_list)          # 출력: [1, 3]

# clear(): 리스트의 모든 요소를 제거. 비어 있는 상태가 됨.
my_list = [1, 2, 3]

my_list.clear() # 리스트의 모든 요소를 제거
print(my_list)  # 출력: []

# +) in 연산으로 존재 여부를 확인하고 True인 경우에만 삭제
# in 연산자 : list 내부에 값이 존재하는지 확인하는 기능

### 리스트 슬라이싱(Slicing)
# 슬라이싱(Slicing)은 리스트의 일부분을 잘라내어 새로운 리스트를 만드는 기법. 리스트에서 특정 범위의 요소들을 선택하는 데 유용.
# new_list = old_list[start:end:step]

# start: 슬라이싱을 시작할 인덱스. 이 인덱스에 해당하는 요소는 포함. 기본값은 0.
# end: 슬라이싱을 끝낼 인덱스. 이 인덱스에 해당하는 요소는 포함되지 않음. 기본값은 리스트의 길이.
# step: 슬라이스의 간격을 나타내는 값. 기본값은 1. 만약 step이 음수라면 리스트를 역순으로 탐색.
my_list = [1, 2, 3, 4, 5]

# 인덱스 1부터 3까지의 요소를 선택
sliced_list1 = my_list[1:4]
print(sliced_list1)  # 출력: [2, 3, 4]

# 리스트의 처음부터 인덱스 3까지의 요소를 선택
sliced_list2 = my_list[:4]
print(sliced_list2)  # 출력: [1, 2, 3, 4]

# 인덱스 2부터 끝까지의 요소를 선택
sliced_list3 = my_list[2:]
print(sliced_list3)  # 출력: [3, 4, 5]

# 리스트의 모든 요소를 역순으로 선택
sliced_list4 = my_list[::-1]
print(sliced_list4)  # 출력: [5, 4, 3, 2, 1]



### 리스트와 연산

# 리스트는 더하기 연산자 사용가능

# 리스트의 곱셈 연산 : 원소 반복

# 리스트는 == 비교연산 가능

# > , < 크기 비교도 가능