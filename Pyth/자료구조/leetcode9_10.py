# LeetCode 136
class Solution(object):
    def singleNumber(self, nums):
        result = 0
        for num in nums:
            result ^= num  # XOR 연산으로 중복 숫자를 제거
        return result
    
# XOR(배타적 논리합) 연산
# 리스트 내에서 동일한 숫자들은 XOR 연산으로 서로 소거되어 0이 됨

# set을 이용한 풀이 => 공간복잡도가 O(n)
'''
def singleNumberHash(nums: List[int]) -> int:
    num_set = set()
    for num in nums:
    if num in num_set:
        num_set.remove(num)
    else:
        num_set.add(num)
    single_num = num_set.pop()
    return single_num
'''


# LeetCode 231
'''
class Solution(object):
    def isPowerOfTwo(self, n):
        if n <= 0:
            return False
        while n % 2 == 0:
            n = n / 2
            if n == 1:
                return True
        return False
'''
# Time Limit

# 비트연산
class Solution(object):
    def isPowerOfTwo(self, n):
        if n <= 0:
            return False
        return (n & (n - 1)) == 0
# n 과 n-1 이 비트 & 연산하면 겹치는 것이 없으면 2의 거듭제곱 수
        