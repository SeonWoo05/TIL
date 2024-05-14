## 함수

# 리스트 넣어서 그 안의 원소들을 출력하는 함수
def arg_list(food):
    for x in food:
        print(x)

fruits = ["apple", "banana", "cherry"]
# arg_list(fruits) 


# 0~9까지 담긴 리스트 반환하는 함수
def ret_list():
    list = []
    for i in range(0,10):
        list.append(i)
    return list
# print(ret_list())


# 딕셔너리와 key값을 입력하면 value를 반환하는 함수
def arg_dict(dic,k):
    return dic[k]

majors = {"CS" : "Computer Science",
         "EE" : "Electrical Engineering"}

# print(arg_dict(majors, 'CS'))


# 딕셔너리를 반환하는 함수
def ret_dict():
    d = dict()
    d['str'] = "Tutorialspoint"
    d['x'] = 50
    return d

# print(ret_dict())


## 정의 위치에 따른 변수의 종류

# test() : UnboundLocalError 발생
a = 17
def test():
    print(a)
    a = 13
    print(a)


# Variable scope : 해당 변수가 접근할 수 있는 변수, 객체 그리고 함수의 집합
# Scope resolution : LEGB rule

# Global scope
x = 0
def outer():
    # Enclosed scope : 중첩된 함수가 있을 때 적용되는 scope
    x = 1
    print(f'Enclosed scope : {x}')
    def inner():
        # Local scope
        x = 2
        print(f'Local scope : {x}')
    inner()

# print(f'Global scope : {x}')
# outer()