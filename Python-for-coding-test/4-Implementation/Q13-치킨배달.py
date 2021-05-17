# 크기가 N X N
# 도시는 1 X 1
# 치킨거리는 집과 가장 가까운 치킨집 사이의 거리
# 도시의 치킨거리는 모든 집의 치킨 거리의 합
# d = |r1 - r2| + |c1 - c2|
# 0 : 빈칸, 1 : 집, 2 : 치킨집

n, m = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(n)]

cities = []
chickens = []


# 도시와 치킨집을 따로 추출
for i in range(n):
    for j in range(n):
        if map[i][j] == 0:
            continue
        elif map[i][j] == 1:
            cities.append([i, j])
        elif map[i][j] == 2:
            chickens.append([i, j])

# print("cities", cities)
# print("chickens", chickens)

# 치킨거리 추출
distances = []
for chicken in chickens:
    for city in cities:
        tmp = abs(chicken[0] - city[0]) + abs(chicken[1] - city[1]) # 치킨거리
        distances.append([chicken, tmp])

# 치킨가게별 치킨거리 추출
chickenSum = 0
totalSum = []
for i in range(1, len(distances)):
    if distances[i-1][0] != distances[i][0]:
        totalSum.append([distances[i-1][0], chickenSum])
        chickenSum = 0
        continue
    chickenSum += distances[i-1][1]

chickenSum += distances[i][1]
totalSum.append([distances[i-1][0], chickenSum])

answer = int(n*n)
for i in range(len(totalSum)):
    if answer > totalSum[i][1]:
        answer = totalSum[i][1]

print(answer)
