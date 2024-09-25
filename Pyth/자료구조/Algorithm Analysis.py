## n개의 정수 중 최대값
'''
def arrayMax(A,n):
    currentMax = A[0]
    for i in range(1,n):
        if currentMax < A[i]:
            currentMax = A[i]
    return currentMax

A = list(map(int,input().split()))
n = len(A)

print(arrayMax(A,n))
'''

## Leetcode 136
# 리스트에 count()가 1인 원소 반환
class Solution(object):
    def singleNumber(self, nums):
        A = set()
        for i in nums:
            if i in A:
                A.remove(i)
            else:
                A.add(i)

        return A.pop()
        
## Leetcode 231

## Leetcode 268
## Leetcode 204