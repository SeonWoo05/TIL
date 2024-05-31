# list comprehension
nums = list(map(int, input().split()))
A = [x for x in nums if nums.count(x) == 1]
print(*A)


# dictionary
nums = list(map(int, input().split()))

freq = {} # 빈도수를 저장할 딕셔너리 생성

for num in nums: # 반복문으로 freq 안에 num이 있으면 value를 +1 / 없으면 value를 =1 로 설정
    if num in freq:
        freq[num] += 1
    else:
        freq[num] = 1


for num in freq: # 빈도수가 1인 원소 찾기
    if freq[num] == 1:
        print(num)
        break