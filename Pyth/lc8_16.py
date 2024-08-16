# nums1의 앞 부분에는 유효한 m개의 숫자가 있습니다.
# nums1의 뒤쪽에는 n개의 0이 있습니다. 이 0들은 nums2의 값들을 병합하기 위한 빈 공간을 의미합니다.

# 88
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        # 포인터를 nums1과 nums2의 마지막 요소에 설정
        i, j, k = m - 1, n - 1, m + n - 1
        
        # nums1과 nums2를 뒤에서부터 비교하여 병합
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]: # i와 j는 리스트의 마지막 원소의 인덱스
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        
        # nums2에 남아 있는 요소들 처리 (nums1의 앞부분이 남아 있는 경우는 이미 자리에 있음)
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1

# 27
# nums를 조작해야함
class Solution(object):
    def removeElement(self, nums, val):
        k = 0  # 유효한 요소의 개수를 나타내는 포인터
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]  # val이 아닌 요소를 앞으로 옮김
                k += 1  # 유효한 요소 개수를 증가시킴
        return k  # 유효한 요소의 개수 반환
    
# 27-2
class Solution:
    def removeElement(self, nums, val):
        for i in range(len(nums)):
            if nums[0] != val:
                nums.append(nums[0]) # val과 다르면 뒤에추가하고 제거
                del nums[0]
            else:
                del nums[0]
        return len(nums)