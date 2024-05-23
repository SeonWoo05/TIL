# 퀴즈에서는 인스턴스를 생성하여 작성한 예제코드는 주어지지 않음.
# 기말고사는 함수 위주로 펠린드롬, 피봇같은 수준 / 객체지향 프로그래밍 나오면 알려주신다 함

# 1. Counter 클래스
class Counter:
    def __init__(self, number=0): # 생성자 함수
        if number >= 100 or number <= -1:
            self.__number = 0
        else:
            self.__number = number
    
    def __str__(self):
        return f"C({self.__number})" # f-string으로 반환
    
    def __add__(self, other):
        new_number = self.__number + other.__number # self, other : 객체 / 그 객체에 number라는 속성 추가
        if new_number >= 100:
            new_number = 0
        return Counter(new_number) # + 기호를 보면 둘이 합친다음 새로운 number 속성으로 바꾸어 적용하는 듯!
    
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

c1 = Counter(n1) # 이렇게 하면 c1 : self, n1 = number // c1 객체의 number는 n1 이다.
c1.inc()
print('c1=',c1)
# print('c1= ' + str(c1)) # 둘중 하나로
# print('c1=' + c1) : 문자열과 'Counter' 객체를 직접 연결할 수는 없음

c2 = Counter()
c2.inc()
c2.inc()
c2.dec()
print('c2=',c2)
c2.reset()
print('c2=',c2)

n2 = int(input())
n3 = int(input())

c1 = Counter(n2)
c2 = Counter(n3)
c3 = c1 + c2 # c1 + c2는 c1.__add__(c2)를 호출
c4 = c1 - c2 # c1 - c2는 c1.__sub__(c2)를 호출 / 각각의 결과를 반환합니다.
print('c3=',c3)
print('c4=',c4)


# 2. BankAccount 클래스
# BankAccount 클래스 정의
class BankAccount:
    def __init__(self, name, account, balance=0):
        self.__name = name
        self.__account = account
        self.__balance = balance

    def __str__(self):
        return f"{self.__name}의 계좌 {self.__account}의 잔고는 {self.__balance}원 입니다."

    def deposit(self, money):
        self.__balance += money
        print(f"{money}원이 입금되었습니다. 잔고는 {self.__balance}입니다.")

    def withdraw(self, money):
        if self.__balance >= money:
            self.__balance -= money
            print(f"{money}원이 출금되었습니다. 잔고는 {self.__balance}입니다.")
        else:
            print(f"계좌 잔고는 {self.__balance}원으로 인출 요구 금액 {money}보다 작습니다.")

# 예제 코드를 통해 BankAccount 클래스 테스트
name = input() #PNU OJ 입력
account = input() #PNU OJ 입력
n1 = int(input()) #PNU OJ 입력
n2 = int(input()) #PNU OJ 입력
n3 = int(input()) #PNU OJ 입력

account1 = BankAccount(name, account) # 3개를 매개변수로 갖는데 하나는 디폴트값으로 사용
print(account1)
account1.deposit(n1)
print(account1)
account1.withdraw(n2)
print(account1)
account1.withdraw(n3)


# 3. Student 클래스
# Student 클래스 정의
class Student:
    def __init__(self, name, student_id, korean_quiz=0, math_quiz=0, science_quiz=0):
        self.__name = name
        self.__student_id = student_id
        self.__korean_quiz = korean_quiz
        self.__math_quiz = math_quiz
        self.__science_quiz = science_quiz

    def __str__(self):
        total_score = self.get_total_score()
        avg_score = self.get_avg_score()
        return (f"이름: {self.__name}, 학번: {self.__student_id}\n"
                f"국어성적: {self.__korean_quiz}, 수학성적: {self.__math_quiz}, 과학성적: {self.__science_quiz}\n"
                f"합계: {total_score}, 평균: {avg_score}") # 여러줄일땐 이렇게

    def set_korean_quiz(self, score):
        self.__korean_quiz = score

    def set_math_quiz(self, score):
        self.__math_quiz = score

    def set_science_quiz(self, score):
        self.__science_quiz = score

    def get_total_score(self):
        total_score = self.__korean_quiz + self.__math_quiz + self.__science_quiz
        return total_score # total_score와 ave_score는 속성값이 아니므로 정의하고 리턴까지
                            # 나중에 불러서 사용할 때도 .()로 불러서 사용
    
    def get_avg_score(self):
        avg_score = self.get_total_score() / 3
        return avg_score # 이부분 연습 필요
    
name = input()
student_id = input()

student = Student(name, student_id) # 점수 0,0,0 으로 일단 객체 생성

korean_quiz = int(input())
math_quiz = int(input())
science_quiz = int(input())

student.set_korean_quiz(korean_quiz) # 함수를 정의해둠 => 매개변수 입력해서 student의 퀴즈 점수 갱신
student.set_math_quiz(math_quiz)
student.set_science_quiz(science_quiz)
print(student)

# 1. 속성값 초기화
# 2. 출력할 __str__부분 작성
# 3. 거기에 새롭게 추가된 변수 있으면 그거에 대한 함수 작성


# 4. TV 클래스
# TV 클래스 정의
class TV:
    MIN_VOLUME = 0
    MAX_VOLUME = 20
    MIN_CHANNEL = 0
    MAX_CHANNEL = 200

    def __init__(self, volume=5, channel=0, is_on=False):
        self.__volume = volume
        self.__channel = channel
        self.__is_on = is_on

    def __str__(self):
        if self.__is_on:
            return f"볼륨 = {self.__volume}, 채널 = {self.__channel}"
        else:
            return "TV가 꺼짐 상태입니다."

    def toggle_power(self):
        self.__is_on = not self.__is_on

    def set_channel(self, channel):
        if TV.MIN_CHANNEL <= channel <= TV.MAX_CHANNEL:
            self.__channel = channel
        else:
            print("채널 오류")

    def set_volume(self, volume):
        if TV.MIN_VOLUME <= volume <= TV.MAX_VOLUME:
            self.__volume = volume
        else:
            print("볼륨 오류")

    def volume_up(self):
        if self.__volume < TV.MAX_VOLUME:
            self.__volume += 1

    def volume_down(self):
        if self.__volume > TV.MIN_VOLUME:
            self.__volume -= 1

    def channel_up(self):
        if self.__channel < TV.MAX_CHANNEL:
            self.__channel += 1

    def channel_down(self):
        if self.__channel > TV.MIN_CHANNEL:
            self.__channel -= 1

# 예제 코드를 통해 TV 클래스 테스트
v1 = int(input())  # PNU OJ 입력
c1 = int(input())  # PNU OJ 입력

my_tv = TV()
print(my_tv)
my_tv.toggle_power()
print(my_tv)
my_tv.set_volume(v1)
print(my_tv)
my_tv.set_channel(c1)
print(my_tv)
my_tv.volume_up()
my_tv.channel_up()
print(my_tv)

v2 = int(input())  # PNU OJ 입력
c2 = int(input())  # PNU OJ 입력

your_tv = TV(v2, c2)
print(your_tv)
your_tv.toggle_power()
print(your_tv)
your_tv.volume_down()
your_tv.channel_down()
print(your_tv)