## Leetcode 125
# two pointers tecq
# 알파벳/숫자 이외의 문자 무시
# 대소문자 무시
# 이외 문자 무시한 index까지 이동 -> 비교 -> 다르면 False 같으면 이어서
class Solution(object):
    def isPalindrome(self, s):
        i = 0
        j = len(s) - 1

        while i < j:
            while i < j and not s[i].isalnum(): #알파벳/숫자가 아니면 i +1
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1
            
            if s[i].lower() != s[j].lower():
                return False
            
            i += 1
            j -= 1
        return True            


## Leetcode 209
# Sliding window ( 리스트의 원소가 모두 양의 정수 )
# 양의 무한대 => 현재값을 최소값으로 갱신가능 / 최소값을 찾는 알고리즘에서 초기값으로 자주 설정
# 만약 sum이 target보다 작거나 해서 갱신이 안되면, min_len을 0으로 처리하기 위한 알고리즘 필요
# => 그냥 float('inf') 과 비교
class Solution(object):
    def minSubArrayLen(self, target, nums):
        min_len = float('inf')
        left = 0
        sum = 0

        for i in range(len(nums)):
            sum += nums[i]

            while sum >= target:
                min_len = min(min_len,i - left + 1)
                sum -= nums[left]
                left += 1
        
        return min_len if min_len != float('inf') else 0

## Leetcode 724
# 부분합과 구간합
class Solution(object):
    def pivotIndex(self, nums):
        s = sum(nums)
        leftsum = 0
        
        for i, x in enumerate(nums):
            if leftsum == (s- leftsum- x):
                return i
            leftsum += x
        
        return -1
        

## Leetcode 1480
# 슬라이딩 윈도우?
class Solution(object):
    def runningSum(self, nums):
        A = [nums[0]]
        for i in range(1,len(nums)):
            A.append(nums[i] + A[i-1])
        
        return A
    
## Leetcode 560
# 작으면 i 이동해서 더하기만 / 크면 left 이동해서 빼기만 / 같으면 cnt +1 하고 둘다 이동
# 슬라이딩 윈도우 방식은 부분 배열의 합이 양수일 때 유효 => 음수가 섞여있거나 while 안에서 left옮겨서 모든 경우 탐색하지 못할 수 있음
'''
class Solution(object):
    def subarraySum(self, nums, k):
        left = 0
        sum = 0
        cnt = 0
        for i in range(len(nums)):
            sum += nums[i]

            while sum > k:
                sum -= nums[left]
                left += 1

            if sum == k:
                cnt += 1
                sum -= nums[left]
                left += 1

        return cnt
'''
# 해시테이블? 맵? == '딕셔너리'
# **키-값 쌍(key-value pair)**으로 데이터를 저장하는 자료구조
# 빠른 검색, 삽입, 삭제를 가능하게 하는 매우 유용한 자료구조
class Solution(object):
    def subarraySum(self, nums, k):
        sum_counts = {0: 1}  # 부분합이 0인 경우 1번 카운트 (빈 배열의 경우 처리)
        curr_sum = 0  # 현재까지의 누적합
        cnt = 0  # 부분 배열의 개수
        
        for num in nums:
            curr_sum += num  # 현재 값을 더해 누적합을 구함
            
            # 현재 누적합에서 k를 뺀 값이 해시맵에 있으면, 그 수만큼 부분 배열이 존재함
            if (curr_sum - k) in sum_counts:
                cnt += sum_counts[curr_sum - k]
            
            # 현재 누적합을 해시맵에 저장하여 이후 부분 배열 계산에 사용
            sum_counts[curr_sum] = sum_counts.get(curr_sum, 0) + 1
                # sum_counts에서 curr_sum이라는 키를 찾아 curr_sum이 등장한 횟수를 가져옴
                # 두번째 인자는 curr_sum이라는 키가 없으면 0을 반환
        
        return cnt                


## Leetcode 728
class Solution(object):
    def selfDividingNumbers(self, left, right):
        C = []
        for num in range(left,right+1):
            str_num = str(num)
            if '0' in str(num):
                continue # 다음 반복으로 넘어감
            
            E = True

            for i in str_num:
                if num % (int(i)) != 0:
                    E = False
            
            if E:
                C.append(num)
        
        return C


## Two pointers technique
# : 주로 정렬된 배열을 대상으로 함

# Opposite directional : 양 끝에서 출발
# 문제 : 125, 167, 283, 344, 27

# Equi-directional : slow-runner and fast-runner
# 문제 : 234, 141, 3, 26

# Sliding window : 고정 사이즈의 윈도우가 이동
# 문제 : 209, 239, 76, 424