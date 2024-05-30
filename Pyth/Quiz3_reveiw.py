def pivotIndex(nums):
	A = 0
	B = []
	for i in range(len(nums)):
		if sum(nums) - nums[i] == 2*A:
			B.append(i)
		A += nums[i]
	if len(B) != 0:
		print(min(B))
	else:
		print(-1)

nums = list(map(int, input().split()))
pivotIndex(nums)