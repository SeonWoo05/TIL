nums = list(map(int, input().split()))
A = [x for x in nums if nums.count(x) == 1]
print(*A)