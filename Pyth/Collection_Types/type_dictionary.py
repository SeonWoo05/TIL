### 딕셔너리 기본 구조

# N = int(input())
D = {'A':1 , 'B':2 , 'C':3} # 그냥 {} 생성하면 딕셔너리

# for i in range(N):
#     P,Q = input().split() 
#     A[P] = Q # P : key / Q : value

D_keys = D.keys() # 키가 리스트로 반환됨
D_values = D.values() # 값이 리스트로 반환됨
D_items = D.items() # 딕셔너리 내의 모든 항목을 [키]:[값]으로 반환

print(D_keys) # dict_keys(['A', 'B', 'C']) : 출력값
print(D_values) # dict_values(['1', '2', '3'])
print(D_items) # dict_items([('A', 1), ('B', 2), ('C', 3)])


# 존재 여부 확인
# in, not in 은 key에 대해서 유뮤를 반환 (not value)


# get(key) : 키에 대한 값을 반환 / 키가 없으면 None 반환
print(D.get('A')) # 1
print(D.get('E')) # None

# pop(key) : 키에 대한 값을 반환 / 키가 없으면 KeyError 발생
# print(D.pop('A')) # 1
# print(D.pop('E')) # Error 발생!!

# 반복문
for i in D.keys():
    print(i)
for i in D.values():
    print(i)


# 개수 세기
# X = {'H' : 1, 'J' : 2, 'I' : 1}
# count = 0

# for i in X.values():
#     if i == 1:
#         count += 1

# print(count)