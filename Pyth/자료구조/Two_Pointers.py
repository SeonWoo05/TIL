## Two Pointers

# 배열이나 리스트 같은 자료구조에서 자주 사용되는 효율적인 탐색 기법
# 두 개의 포인터(인덱스)를 사용하여 데이터를 탐색하거나 처리

## (1) 양 끝에서 시작하는 포인터:

# 두 수의 합 (Two Sum II - Input Array Is Sorted):
# 배열이 정렬되어 있을 때, 두 포인터를 양 끝에서 시작하여
# 두 수의 합이 목표 값과 일치하는지 확인합니다.
# 만약 합이 너무 크면 오른쪽 포인터를 왼쪽으로,
# 너무 작으면 왼쪽 포인터를 오른쪽으로 이동시킵니다.

## (2) 한쪽 끝에서 시작하는 포인터:

# 중복 요소 제거 (Remove Duplicates from Sorted Array):
# 정렬된 배열에서 중복 요소를 제거할 때,
# 두 포인터 중 하나는 현재 요소를 가리키고,
# 다른 하나는 유효한 요소를 저장할 위치를 가리킵니다.

# 특정 요소 제거 (Remove Element):
# 특정 값을 가진 요소를 제거할 때,
# 한 포인터는 배열을 순회하고,
# 다른 포인터는 유효한 요소를 저장할 위치를 가리킵니다.

# EX 1) Two Sum II - Input Array Is Sorted
def twoSum(nums, target):
    left, right = 0, len(nums) - 1
    while left < right:
        current_sum = nums[left] + nums[right]
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            left += 1
        else:
            right -= 1

# EX 2) Remove Duplicates from Sorted Array
def removeDuplicates(nums):
    if not nums:
        return 0
    k = 1  # 첫 번째 요소는 항상 유효하므로 k를 1로 초기화
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[k] = nums[i]
            k += 1
    return k  # 중복이 제거된 후의 길이 반환


## Two Pointers 기법의 확장

# 슬라이딩 윈도우 (Sliding Window):
# 두 포인터를 사용하여 윈도우를 이동시키면서
# 배열이나 문자열의 서브 배열/서브 문자열을 처리하는 기법입
# 주로 부분합, 최대/최소 길이 등의 문제에서 사용

# 투 포인터와 함께 사용하는 알고리즘:
# (1) 분할 정복:
# 배열의 양쪽을 분할하여 정복하는 방식에서 투 포인터를 사용하여 효율적으로 배열을 병합
# (2) 투 포인터와 이진 탐색:
# 특정 조건을 만족하는 요소를 찾을 때,
# 이진 탐색과 함께 투 포인터를 사용하여 문제를 해결