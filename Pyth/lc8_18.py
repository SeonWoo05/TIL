# LC 26
nums = list(map(int, input().split()))

def removeDuplicates(nums):
    k = 1  # 첫 번째 요소는 항상 유효하므로 k를 1로 설정합니다.
    
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[k] = nums[i]
            k += 1
    
    return k  # 중복이 제거된 후의 배열 길이를 반환합니다.

result = removeDuplicates(nums)
print(f"Result: {result}, nums after modification: {nums[:result]}")