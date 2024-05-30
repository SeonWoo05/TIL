### 문자열의 다양한 메서드

# str.capitalize() : 문자열의 첫 번째 문자를 대문자로, 나머지 문자를 소문자로 변환
text = "hello world"
capitalized_text = text.capitalize()
print(capitalized_text)  # "Hello world"

# str.upper() : 대문자로 변환
# str.lower() : 소문자로 변환

# str.count(substring) : 문자열에서 특정 부분 문자열의 발생 횟수를 반환
text = "banana"
count = "banana".count("na")
print(count) # 2

# str.find(substring) :  특정 부분 문자열의 첫 번째 발생 위치를 반환 / 부분 문자열이 없으면 -1을 반환
text = "hello"
position = text.find("e")
print(position)  # 1

# str.isalnum() : 문자열이 알파벳 문자 또는 숫자로만 구성되어 있는지 확인 / 특수 문자나 공백이 있으면 False를 반환
text = "Hello123"
result = text.isalnum()
print(result)  # True

# str.isdecimal() : 문자열이 0-9 사이의 숫자만으로 구성되어 있는지 확인
text = "12345"
result = text.isdecimal()
print(result)  # True

# str.join(iterable) : 하나의 문자열로 결합
words = ["Hello", "world"]
joined_text = " ".join(words)
print(joined_text)  # "Hello world"

# str.replace(old, new, count=-1) : 모든 old 부분 문자열을 new 부분 문자열로 바꿈 / 선택적으로 count를 지정하여 바꿀 횟수를 제한할 수 있음
text = "Hello world"
replaced_text = text.replace("world", "Python")
print(replaced_text)  # "Hello Python"

text = "apple apple apple"
replaced_text = text.replace("apple", "orange", 1) # 특정 횟수만큼 교체
print(replaced_text)  # "orange orange apple"

# str.split(separator=None) : 구분자를 기준으로 나누어 '리스트'로 반환
text = "Hello world"
split_text = text.split()
print(split_text)  # ["Hello", "world"]

text = "apple,orange,banana"
split_text = text.split(",") # 특정 구분자로 나누기
print(split_text)  # ["apple", "orange", "banana"]