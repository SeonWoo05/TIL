# # 객체 지향 프로그래밍
# # 예제 해보면서 이해하기
# __ 없이 짜도 되는데되는데 information hiding을 무시하는 것임

# P.1
class Box: 
    PI = 3.14 # 클래스 변수
    def __init__ (self, a, b): # 생성자 - 이름이 정해진 메서드 __init__
        self.__radius = a # 멤버 변수(= 인스턴스 변수) : init 안에서 정의된 변수 
        self.__height = b
    def Volume(self): # 멤버 메서드
        lv = 2 * Box.PI * self.__radius**2 * self.__height
        return lv

g_box = Box(3,2) # class Box 를 호출 - 생성자를 호출한 것임
r_box = Box(2,5)

# print(f'Volume= {g_box.Volume()}') # Box 클래스 안의 Volume 메서드 적용
# print(f'Volume= {r_box.Volume()}')


# P.2
class Person:
    def __init__(self, h):
        self.height = h

    def __lt__(self, other): # __lt__메서드는 파이썬에서 "less than" (작다) 연산자를 정의하는 특별 메서드.
        if (self.height < other.height): # 두 객체를 비교할 때 < 연산자를 사용할 수 있게 해줍니다.
            return "p1 is less than p2"
        else:
            return "p2 is less than p1"
        
p1 = Person(175)
p2 = Person(180)
print(p1 < p2) # p1 < p2 표현은 내부적으로 p1.__lt__(p2)를 호출한다.
