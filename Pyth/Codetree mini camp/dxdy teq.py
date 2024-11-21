# # https://www.codetree.ai/missions/5/problems/move-in-direction?&utm_source=clipboard&utm_medium=text

# N = int(input())

# dx = [1,0,-1,0] # 배열이 아니므로 동쪽이 x+1
# dy = [0,1,0,-1] # // 북쪽이 y+1

# dict = {"E":0, "N":1, "W":2, "S":3}

# x, y = 0, 0
# for i in range(N):
#     dir, k = input().split()
#     k = int(k)

#     x = x + k * dx[dict[dir]]
#     y = y + k * dy[dict[dir]]

# print(x,y)


# https://www.codetree.ai/missions/5/problems/text-based-commands2?&utm_source=clipboard&utm_medium=text

# x,y = 0, 0

# dx = [0,1,0,-1]
# dy = [1,0,-1,0]
# dir = 0

# A = input()

# for i in A:
#     if i == 'L':
#         dir = (dir + 3) % 4
#     elif i == 'R':
#         dir = (dir + 1) % 4
#     else:
#         x = x + dx[dir]
#         y = y + dy[dir]

# print(x,y)


# https://www.codetree.ai/missions/5/problems/place-more-than-3-ones?&utm_source=clipboard&utm_medium=text
# n = int(input())
# A = []

# for _ in range(n):
#     A.append(list(map(int, input().split())))

# dx = [0, 1, 0, -1]
# dy = [1, 0, -1, 0]

# count = 0

# for x in range(n):
#     for y in range(n):     
#         cnt = 0
#         for dir_num in range(4):
#             nx = x + dx[dir_num]
#             ny = y + dy[dir_num]

#             if 0 <= nx < n and 0 <= ny < n and A[nx][ny] == 1:
#                 cnt += 1
        
#         if cnt >= 3:
#             count += 1

# print(count)


# https://www.codetree.ai/missions/5/problems/small-marble-movement?&utm_source=clipboard&utm_medium=text
# n, t = map(int, input().split())
# x, y, dir = input().split()

# # 좌표평면이 아닌 배열에서는 x가 행, y가 열이라고 생각하고
# # 내려가는 것이 +1 올라가는 것이 -1 로 설정해두면 편함함
# dict = {
#     'R': 0,
#     'D': 1,
#     'U': 2,
#     'L': 3
# }

# # x,y 가 시작위치가 1,1 이라 하면 배열상에서는 0,0이 됨
# x, y, move_dir = int(x) - 1, int(y) - 1, dict[dir]

# dx = [0, 1, -1,  0]
# dy = [1, 0,  0, -1]

# # if 문으로 작성해도 되지만 함수로 정리해두면 깔끔
# def in_range(x, y):
#     return 0 <= x < n and 0 <= y < n

# for _ in range(t):
#     # t초 동안 nx, ny(이동할 위치)
#     nx, ny = x + dx[move_dir], y + dy[move_dir]
    
#     # 배열 밖으로 벗어나는지 확인
#     if in_range(nx, ny):
#         x, y = nx, ny

#     # 움직인것이 배열 밖이면 = 벽에 부딛히면 => 방향 변경
#     else:
#         move_dir = 3 - move_dir # 현재 바라보는 방향의 반대를 바로 구하기 위해
#         # dx, dy를 R,L / U,D 을 각각 3에서 빼면 반대방향이 되도록 설정

# # 최종 위치는 다시 index에서 위치 돌려주기
# print(x + 1, y + 1)


# https://www.codetree.ai/missions/5/problems/snail-number-square?&utm_source=clipboard&utm_medium=text
# 빙빙 돌며 숫자 사각형 채우기

# n,m = map(int, input().split())

# arr = [[0 for i in range(m)] for i in range(n)]

# def in_range(nx, ny):
#     return 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 0

# dx = [0,1,0,-1]
# dy = [1,0,-1,0]

# x, y = 0, 0
# dir = 0

# for i in range(1, n*m+1):
#     arr[x][y] = i
    
#     nx = x + dx[dir]
#     ny = y + dy[dir]

#     if in_range(nx,ny):
#         x = nx
#         y = ny

#     else:
#         dir = (dir + 1) % 4 
#         x = x + dx[dir]
#         y = y + dy[dir]

# for i in range(n):
#     print(*arr[i])


# # https://www.codetree.ai/missions/5/problems/add-all-the-numbers-on-the-path?&utm_source=clipboard&utm_medium=text
# # test 문제
# N, T = map(int, input().split())
# A = input()
# arr = []

# for i in range(N):
#     arr.append(list(map(int, input().split())))

# def in_range(nx,ny):
#     return 0 <= nx < N and 0 <= ny < N

# dx = [-1,0,1,0]
# dy = [0,1,0,-1]
# dir = 0
# x = N // 2 # N개의 행, 열에서 중앙 인덱스 = (N-1)/2
# y = N // 2 

# summ = arr[x][y]

# for i in A:
#     if i == "L":
#         dir = (dir + 3) % 4
    
#     elif i == "R":
#         dir = (dir + 1) % 4
    
#     else:
#         nx = x + dx[dir]
#         ny = y + dy[dir]

#         if in_range(nx,ny):
#             x = nx
#             y = ny

#             summ += arr[x][y]

# print(summ)