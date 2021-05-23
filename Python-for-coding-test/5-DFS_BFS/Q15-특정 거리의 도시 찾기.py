from collections import deque  # for queue

# 2. BFS 정의
def bfs(graph, start, distance, count):
    queue = deque([start])

    while queue:
        now = queue.popleft()
        # print(now, end=' ')
        for next_node in graph[now]:
            if distance[next_node] == -1:
                # 최단거리 갱신
                distance[next_node] = distance[now] + 1
                queue.append(next_node)
    return distance





# 1. 입력을 바로 하자.

# 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
n, m, k, x = map(int, input().split())

graph = [[] for _ in range(n + 1)]

# 단방향 주소
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

# visited = [False] * (n+1) # 방문 노드 확인
distance = [-1] * (n + 1)
distance[x] = 0 # x는 출발 도시 번호

distance = bfs(graph, x, distance, k)

check = False
for i in range(1, n + 1):
    if distance[i] == k:
        print(i)
        check = True

if check == False:
    print(-1)