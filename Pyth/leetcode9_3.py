# leetcode 1945
class Solution(object):
    def getLucky(self, s, k):
        numbers = [str(ord(char) - ord('a') + 1) for char in s]
        numsum = "".join(numbers)
        
        for i in range(k):  
            total_sum = 0  
            for digit in numsum:
                total_sum += int(digit)

            numsum = str(total_sum)

        return int(numsum)


# leetcode 202
'''
각 자리의 수를 나누어 리스트에 저장
원소들을 각각 제곱하여 합하고 set에 저장을 반복
1이 되면 true set에 존재하는 수가 되면 false
'''
class Solution(object):
    def isHappy(self, n):
        A = set()
        while True:
            B = 0
            for i in str(n):
                B += int(i)**2
            
            if B == 1:
                return True
            
            elif B in A:
                return False

            else:  
                A.add(B)
                n = B
'''
시간복잡도, 메모리 사용 모두 하위권
'''
