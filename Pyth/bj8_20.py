# # BJ 2075

## 메모리 초과
# import heapq

# N = int(input())
# matrix = [list(map(int, input().split())) for _ in range(N)]

# min_heap = []

# for i in range(N):
#     for j in range(N):
#         if len(min_heap) < N:
#             heapq.heappush(min_heap, matrix[i][j])
#         else:
#             # 현재 원소가 힙의 최솟값보다 크다면 교체
#             if matrix[i][j] > min_heap[0]:
#                 heapq.heappushpop(min_heap, matrix[i][j])

# print(min_heap[0])


## 개선된 접근
# 행렬 자체를 저장X => 입력받을 때마다 처리함으로써 메모리 사용량 DOWN
import heapq

n = int(input())
min_heap = []

for i in range(n):
	num_list = list(map(int, input().split()))
	if not min_heap: # min_heap에 아무것도 없는 첫번째 입력 시
		for num in num_list:
			heapq.heappush(min_heap, num) # min_heap 채우기
	else:
		for num in num_list: # min_heap에 값이 있을 시 길이를 n으로 유지하기
			if min_heap[0] < num: # min_heap 최솟값보다 현재 숫자가 클 경우 n번째로 큰 수가 바뀌어야 하기 때문에
				heapq.heappush(min_heap, num) # 현재 숫자를 push 하고
				heapq.heappop(min_heap) # 기존 최솟값 pop

print(min_heap[0])