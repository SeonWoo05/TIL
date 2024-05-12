# # 객체 지향 프로그래밍
# # 예제 해보면서 이해하기
# __ 없이 짜도 되는데되는데 information hiding을 무시하는 것임

# P.1
# class Box:
#     PI = 3.14
#     def __init__ (self, a, b):
#         self.__radius = a
#         self.__height = b
#     def Volume(self):
#         lv = 2 * Box.PI * self.__radius**2 * self.__height
#         return lv

# g_box = Box(3,2)
# r_box = Box(2,5)

# print(f'Volume= {g_box.Volume()}')
# print(f'Volume= {r_box.Volume()}')


# P.2
class Person:
    def __init__(self, h):
        self.height = h

    def __lt__(self, other):
        if (self.height < other.height):
            return "p1 is less than p2"
        else:
            return "p2 is less than p1"
        
p1 = Person(175)
p2 = Person(180)
print(p1 < p2)