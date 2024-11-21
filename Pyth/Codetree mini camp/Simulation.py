# https://www.codetree.ai/missions/2/problems/best-place-of-33?&utm_source=clipboard&utm_medium=text
# n = int(input())
# arr = [list(map(int, input().split())) for i in range(n)]

# answer = 0
# for i in range(n-2):
#     for j in range(n-2):
#         total = 0
        
#         for k in range(3):
#             for l in range(3):
#                 total += arr[i+k][j+l]

#         if answer < total:
#             answer = total

# print(answer)


# https://www.codetree.ai/missions/2/problems/conveyor-belt?&utm_source=clipboard&utm_medium=text
# n,t = map(int, input().split())
# arr = list(map(int, input().split())) + list(map(int, input().split()))

# for _ in range(t):
#     temp = arr[2*n -1]
#     for i in range(2*n-1,0,-1):
#         arr[i] = arr[i-1]
#     arr[0] = temp

# print(*arr[:n]) # n-1까지 출력하고
# print(*arr[n:]) # 넘겨서 n부터 2n-1까지 출력


# https://www.codetree.ai/missions/2/problems/conveyor-belt-triangle?&utm_source=clipboard&utm_medium=text
# n, t = map(int, input().split())
# left = list(map(int, input().split()))
# right = list(map(int, input().split()))
# bottom = list(map(int, input().split()))

# # pop 하고 insert 하면 오른쪽으로 한칸씩 이동함함
# for i in range(t):
#     left_pop = left.pop()
#     right_pop = right.pop()
#     bottom_pop = bottom.pop()

#     left.insert(0,bottom_pop)
#     right.insert(0,left_pop)
#     bottom.insert(0,right_pop)

# print(*left)
# print(*right)
# print(*bottom)


# https://www.codetree.ai/missions/2/problems/jenga-1d?&utm_source=clipboard&utm_medium=text
# 1차원 젠가 두번 빼기

# n = int(input())
# arr = [int(input()) for _ in range(n)]
# s1, e1 = map(int, input().split())
# s2, e2 = map(int, input().split())

# temp_row = n - 1 # temp 배열의 마지막 index로 설정해두고
# temp = [0] * n
# for i in range(n - 1, -1, -1):
#     if i < s1 - 1 or i > e1 - 1: # 빼야할 부분이 아니면
#         temp[temp_row] = arr[i] # temp의 마지막 index부터 채워넣고
#         temp_row -= 1 # index 옮겨주고
# arr = temp[temp_row + 1:] # arr 초기화 (가리키고 있는곳은 비어있으니까 temp_row+1부터)

# n = len(arr)
# temp_row = n - 1 # 새롭게 또 arr 배열 크기에 맞는 temp 배열 생성
# temp = [0] * n
# for i in range(n - 1, -1, -1):
#     if i < s2 - 1 or i > e2 - 1:
#         temp[temp_row] = arr[i]
#         temp_row -= 1
# arr = temp[temp_row + 1:]

# print(len(arr))
# for block in arr:
#     print(block)


# https://www.codetree.ai/missions/2/problems/cross-shape-bomb?&utm_source=clipboard&utm_medium=text
# 십자모양 폭발

# n = int(input())
# grid = [list(map(int, input().split())) for _ in range(n)]
# next_grid = [[0 for _ in range(n)] for _ in range(n)]


# def in_bomb_range(x, y, center_x, center_y, bomb_range):
#     return (x == center_x or y == center_y) and abs(x - center_x) + abs(y - center_y) < bomb_range

# def bomb(center_x, center_y):
#     bomb_range = grid[center_x][center_y] # 중심위치의 수가 범위임
    
#     # Step1. 폭탄이 터질 위치는 0으로 채워줍니다.
#     for i in range(n):
#         for j in range(n):
#             if in_bomb_range(i, j, center_x, center_y, bomb_range):
#                 grid[i][j] = 0
	
#     # Step2. 폭탄이 터진 이후의 결과를 next_grid에 저장합니다.
#     for j in range(n):
#         next_row = n - 1
#         for i in range(n - 1, -1, -1):
#             if grid[i][j]: # 터진 부분이 아닌 곳만
#                 next_grid[next_row][j] = grid[i][j] # 아래서부터 채워 받고
#                 next_row -= 1 # index 옮겨줌
                
#     # Step3. grid로 다시 값을 옮겨줍니다.
#     for i in range(n):
#         for j in range(n):
#             grid[i][j] = next_grid[i][j]

# r, c = map(int, input().split())
# bomb(r - 1, c - 1)

# for i in range(n):
#     print(*grid[i])


# https://www.codetree.ai/missions/2/problems/move-to-larger-adjacent-cell?&utm_source=clipboard&utm_medium=text
# 숫자가 더 큰 인접한 곳으로 이동

# def in_range(x,y):
#     return 0 <= x < n and 0 <= y < n

# dx = [-1,1,0,0]
# dy = [0,0,-1,1]

# n,x,y = map(int, input().split())
# arr = [list(map(int, input().split())) for i in range(n)]

# x -= 1
# y -= 1

# while True:
#     print(arr[x][y], end=' ') # 당장의 위치 출력하고
    
#     dir_num = -1
#     for i in range(4): # 반복문 돌면서 자신보다 큰 수가 있는지 탐색
#         nx = x + dx[i]
#         ny = y + dy[i]
        
#         if not in_range(nx, ny):
#             continue
        
#         if arr[nx][ny] > arr[x][y]:
#             dir_num = i # 있으면 이동
#             break

#     if dir_num == -1: # 없으면 while문 탈출
#         break

#     x += dx[dir_num]
#     y += dy[dir_num]
