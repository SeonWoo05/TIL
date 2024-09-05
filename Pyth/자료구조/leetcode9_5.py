# leetcode 35
class Solution(object):
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums) - 1
        
        while left <= right: # 중단점
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid  # target을 찾으면 해당 인덱스 반환
            
            elif nums[mid] < target:
                left = mid + 1  # target이 더 크면 오른쪽으로 탐색 범위를 좁힘
            
            else:
                right = mid - 1  # target이 더 작으면 왼쪽으로 탐색 범위를 좁힘
        
        # target이 nums에 존재하지 않는 경우, 삽입될 위치를 반환
        return left
            

# leetcode 66
class Solution(object):
    def plusOne(self, digits):
        for i in range(len(digits)):
            digits[i] = str(digits[i])

        A = "".join(digits)
        A = int(A) + 1

        A = str(A)
        B = []
        for i in A:
            B.append(int(i))
        
        return B

        