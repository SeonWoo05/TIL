import sys

# ---------- 1. 입력 파싱 ----------
data = sys.stdin.read().strip().split()
if not data:
    sys.exit(0)

it = iter(data)
n = int(next(it))                         # 정점 수
INF = 10 ** 9                             # 충분히 큰 값 = 무한대

# distance[i][j] : i -> j 의 현재 최단 거리
distance = [[INF] * n for _ in range(n)]
# next_node[i][j] : i 에서 j 로 갈 때 첫 번째로 밟을 정점
next_node = [[-1] * n for _ in range(n)]

# 인접 행렬 입력
for i in range(n):
    for j in range(n):
        w = int(next(it))
        if w == -1:
            continue                      # 간선 없음
        distance[i][j] = w
        next_node[i][j] = j              # i->j 직접 연결 (출발 다음 정점은 j 자신)
    distance[i][i] = 0                    # 자기 자신까지 비용 0
    next_node[i][i] = i

# 출·도착 정점
u, v = int(next(it)), int(next(it))

# ---------- 2. Floyd‑Warshall 핵심 알고리즘 ----------
# 세 겹 반복문: k(중간) → i(출발) → j(도착)
for k in range(n):
    for i in range(n):
        # 앞으로 j 루프에서 distance[i][k] 값을 여러 번 쓰므로 지역 변수에 저장
        dik = distance[i][k]
        if dik == INF:                    # i→k 갈 수 없으면 건너뜀
            continue
        for j in range(n):
            # 새로운 경로 i‑k‑j 가 기존 i‑j 보다 짧은가?
            if dik + distance[k][j] < distance[i][j]:
                distance[i][j] = dik + distance[k][j]
                next_node[i][j] = next_node[i][k]  # i→j 로 갈 때 첫 발은 i→k 때와 동일

# ---------- 3. 경로 복원 함수 ----------
def reconstruct_path(src: int, dst: int) -> list[int]:
    """src→dst 최단 경로를 [src, …, dst] 형태로 반환. 없으면 빈 리스트."""
    if next_node[src][dst] == -1:         # 도달 불가
        return []
    path = [src]
    while src != dst:
        src = next_node[src][dst]
        path.append(src)
    return path

# ---------- 4. 결과 출력 ----------
if distance[u][v] >= INF:
    # 경로가 존재하지 않을 때
    print(f"Shortest cost from {u} to {v}: INF")
    print("Path from {} to {}: []".format(u, v))
else:
    print(f"Shortest cost from {u} to {v}: {distance[u][v]}")
    print("Path from {} to {}: {}".format(u, v, reconstruct_path(u, v)))
