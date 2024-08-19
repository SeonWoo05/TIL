# LC 80
def removeDuplicates(nums):
    if len(nums) <= 2:
        return len(nums)  # 배열 길이가 2 이하인 경우, 모든 요소는 허용 범위 내에 있음
    
    k = 2  # 첫 두 요소는 항상 유효하므로 k를 2로 설정
    
    for i in range(2, len(nums)):
        # nums[i]가 nums[k-2]와 다를 경우, nums[k]에 nums[i]를 대입
        if nums[i] != nums[k-2]:
            nums[k] = nums[i]
            k += 1  # 유효한 요소 개수를 증가시킴
    
    return k  # 중복이 제거된 후의 길이 반환

# BJ 2003
A, B = map(int, input().split())
C = list(map(int, input().split()))

k = 0
sum = 0
cnt = 0

for i in range(A):
    sum += C[i]

    while sum >= B: # 하나만 뺐을 때 B보다 클수도 있으므로 while로 계속 빼줘야함
        if sum == B:
            cnt += 1
        sum -= C[k]
        k += 1

print(cnt)