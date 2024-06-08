# Power of Two (1)
def isPowerOfTwo(n):
    A = []
    for i in range(-31,31):
        A.append(2**i)

    if n in A:
        print('true')
    else:
        print('false')

n = int(input())
B = isPowerOfTwo(n)

# Power of Two (2)
def isPowerOfTwo(n):
    if n == 1: # 1도 2로 나눈 나머지가 1이지만 2^0 이므로 true로 반환해서 함수 종료
        print('true')
        return # 적어서 함수 종료해줘야함
    
    if n % 2 == 1:
        print('false')
        return
    
    isPowerOfTwo(n//2) # 둘다 아니면 2로 나누어진 것이므로 재귀함수를 통해 다시 반복

n = int(input())
isPowerOfTwo(n)



# Happy Number
def isHappyNum(n):
    visited = set()

    while True: # 무한루프 시작
        ret = 0
        for x in str(n):
            visited.add(int(x))
            ret += int(x)*int(x)
        
        if ret == 1:
            return True
        if ret in visited: # 방문했던 값중에 있으면 무한루프 반복되므로
            return False # False 반환하고 함수 종료
        n = ret # 반복

n = int(input())
result = isHappyNum(n)

if result == True:
    print('true')
else:
    print('false')


# Add Strings
def addStrings(num1, num2):
    # 문자열을 뒤집어서 덧셈을 쉽게 만듭니다
    num1, num2 = num1[::-1], num2[::-1]
    
    carry = 0
    result = []
    
    # 각 자리를 더합니다
    for i in range(max(len(num1), len(num2))):
        digit1 = int(num1[i]) if i < len(num1) else 0
        digit2 = int(num2[i]) if i < len(num2) else 0
        
        # 자릿수와 캐리를 더합니다
        total = digit1 + digit2 + carry
        
        # 새로운 자릿수와 새로운 캐리를 계산합니다
        result.append(total % 10)
        carry = total // 10
    
    # 남은 캐리가 있으면 추가합니다
    if carry:
        result.append(carry)
    
    # 결과를 뒤집어서 최종 합계 문자열을 만듭니다
    return ''.join(map(str, result[::-1]))

a = input()
b = input()
print(addStrings(a,b))