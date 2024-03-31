# BJ 9498
grade = int(input())

if 90 <= grade <= 100:
    print("A")
elif 80 <= grade <= 89:
    print("B")
elif 70 <= grade <= 79:
    print("C")
elif 60 <= grade <= 69:
    print("D")
elif grade < 60:
    print("F")

# BJ 2935
A = int(input())
Operator = input()
B = int(input())

if Operator == '*' :
    print(A*B)
if Operator == "+" :
    print(A+B)

# BJ 11557
T = int(input())

for i in range(T):
    school_list = [] #빈 리스트 하나 생성
    num = int(input()) #각 테스트의 학교 개수를 입력받음
    
    for i in range(num): #학교 개수에 대해서 반복
        school, alcohol = input().split() #학교와 술소비량 입력받고
        school_list.append([school, int(alcohol)]) #만들어둔 리스트에 학교와 술소비량(정수) 추가
    
    school_list.sort(key = lambda x : (x[1], x[0])) #술 소비량을 기준으로 오름차순 정렬. 소비량이 같다면 학교이름으로 정렬
    print(school_list[-1][0]) # 가장 마지막 요소(튜플)의 '[-1]', 첫번째 값(학교) '[0]' 선택 
## 리스트 안에 술 소비량을 기준으로 튜플이 오름차순 정렬되어있음. 가장 마지막 요소(술 소비량이 가장 많은)의 첫번째 값은 학교이름
## sort : 리스트를 정렬. 기준이 되는 값을 지정하는 것이 'key' 매개변수
## lambda : 함수를 인자로 받는 함수나, 간단한 함수를 한 줄로 표현할 때 유용. 여기서는 정렬의 기준을 제공했음