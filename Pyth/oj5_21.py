# 퀴즈에서는 인스턴스를 생성하여 작성한 예제코드는 주어지지 않음.
# 기말고사는 함수 위주로 펠린드롬, 피봇같은 수준 / 객체지향 프로그래밍 나오면 알려주신다 함

# 1. Counter 클래스
class Counter:
    def __init__(self, number=0):
        if number >= 100 or number <= -1:
            self.__number = 0
        else:
            self.__number = number
    
    def __str__(self):
        return f"C({self.__number})"
    
    def __add__(self, other):
        new_number = self.__number + other.__number
        if new_number >= 100:
            new_number = 0
        return Counter(new_number)
    
    def __sub__(self, other):
        new_number = self.__number - other.__number
        if new_number <= -1:
            new_number = 0
        return Counter(new_number)
    
    def reset(self):
        self.__number = 0
    
    def inc(self):
        self.__number += 1
        if self.__number >= 100:
            self.__number = 0
    
    def dec(self):
        self.__number -= 1
        if self.__number <= -1:
            self.__number = 0

# 예제 코드를 통해 Counter 클래스 테스트
n1 = int(input()) #PNU OJ 입력

c1 = Counter(n1)
c1.inc()
print('c1=', c1)

c2 = Counter()
c2.inc()
c2.inc()
c2.dec()
print('c2=', c2)
c2.reset()
print('c2=', c2)

n2 = int(input()) #PNU OJ 입력
n3 = int(input()) #PNU OJ 입력

c1 = Counter(n2)
c2 = Counter(n3)
c3 = c1 + c2
c4 = c1 - c2
print('c3=', c3)
print('c4=', c4)