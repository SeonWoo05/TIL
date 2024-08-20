## Priority Queue

# 각 요소가 우선순위를 가지고 있으며, 우선순위에 따라 요소가 큐에서 처리되는 자료구조
# 힙(Heap) 자료구조로 구현되며, 우선순위가 높은 요소가 먼저 큐에서 제거됨

## 1) 최소 힙(Min-Heap) 기반의 우선순위 큐 :

# 가장 작은 값이 가장 높은 우선순위
# 최솟값을 빠르게 접근하고 제거

# EX 1) N번째 큰 수 찾기
# N×N 크기의 배열에서 N번째로 큰 수를 찾기 위해,
# 최소 힙을 사용하여 N개의 요소를 유지하고, 
# N번째로 큰 수를 찾음
 
# 배열의 각 요소를 힙에 삽입, 
# 힙의 크기가 N을 초과할 때마다 최솟값을 제거
# 마지막에 힙에 남아있는 최솟값이 N번째로 큰 수

import heapq

def find_nth_largest(matrix, N):
    min_heap = []

    for i in range(N):
        for j in range(N):
            if len(min_heap) < N:
                heapq.heappush(min_heap, matrix[i][j])
            else:
                # 현재 원소가 힙의 최솟값보다 크다면 교체
                if matrix[i][j] > min_heap[0]:
                    heapq.heappushpop(min_heap, matrix[i][j])

    return min_heap[0]

N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]

result = find_nth_largest(matrix, N)
print(result)


## 2) 최대 힙(Max-Heap) 기반의 우선순위 큐 :

# 가장 큰 값이 가장 높은 우선순위
# 최댓값을 빠르게 접근하고 제거

## Python의 heapq 모듈은 기본적으로
# **최소 힙(Min-Heap)**만을 제공하기 때문에,
# 이를 이용해 최대 힙을 구현하려면
# 값의 부호를 반대로 하여 최소 힙처럼 동작하게 만들어야 함

# EX 2) k번째 작은 수 찾기
# 배열에서 k번째 작은 수를 찾기 위해
# 최대 힙을 사용하여 k개의 요소를 유지

# 배열의 각 요소를 힙에 삽입하며,
# 힙의 크기가 k를 초과할 때마다 최댓값을 제거
# 마지막에 힙에 남아있는 최댓값이 k번째로 작은 수

import heapq

def find_kth_smallest(nums, k):
    # 최대 힙을 사용하여 k번째 작은 수를 찾음
    max_heap = []

    for num in nums:
        heapq.heappush(max_heap, -num)  # 최대 힙을 위해 -num을 사용
        if len(max_heap) > k:
            heapq.heappop(max_heap)

    return -max_heap[0]

# 입력 받기
nums = list(map(int, input().split()))
k = int(input())

# k번째 작은 수 출력
result = find_kth_smallest(nums, k)
print(result)


## 우선순위 큐의 응용 및 확장

# 1) 다익스트라 알고리즘 (Dijkstra's Algorithm):
# 최소 힙을 사용하여 현재 가장 작은 비용을 가진 경로를 탐색

# 2) A* 알고리즘 (A* Search Algorithm):
# 예상 비용을 우선순위로 설정하여 탐색


## 우선순위 큐의 시간 복잡도
# 삽입 (push 또는 heappush) : O(log n)
# 최소값 또는 최대값 제거 (pop 또는 heappop) : O(log n)
# 최소값 또는 최대값 접근 (peek 또는 min_heap[0]) : O(1)