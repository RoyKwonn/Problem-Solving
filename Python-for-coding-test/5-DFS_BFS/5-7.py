# 인접 리스트 방식 예제

# 행이 3개인 2차원 리스트
graph = [[] for _ in range(3)]

# 0노드에 연결된 (노드, 간선)
graph[0].append((1, 7))
graph[0].append((2, 5))

graph[1].append((0, 7))

graph[2].append((0, 5))

print(graph)
