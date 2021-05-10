# N개의 음식
# 각 음식에는 1부터 N까지 번호가 붙어있으며

# 1. 무지는 1번 음식부터 먹기 시작하며, 회전판은 번호가 증가하는 순서대로 음식을 무지 앞으로 가져다 놓습니다.
# 2. 마지막 번호의 음식을 섭취한 후에는 회전판에 의해 다시 1번 음식이 무지 앞으로 옵니다.
# 3. 무지는 음식 하나를 1초 동안 섭취한 후 남은 음식은 그대로 두고, 다음 음식을 섭취합니다. 다음 음식이란, 아직 남은 음식 중 다음으로 섭취해야 할 가장 가까운 번호의 음식을 말합니다.
# 4. 회전판이 다음 음식을 무지 앞으로 가져오는 데 걸리는 시간은 없다고 가정합니다.

# food_times : 각 음식을 모두 먹는 데 필요한 시간이 음식의 번호 순서대로 들어 있는 배열
# k : 방송이 중단된 시간을 나타냅니다.
# 만약 더 섭취해야 할 음식이 없다면 -1을 반환하면 됩니다.


# import heapq
#
# def solution(food_times, k):
#     # 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
#     if sum(food_times) <= k:
#         return -1
#
#     # 시간이 작은 음식부터 빼야 하므로 우선순위 큐를 이용
#     q = []
#     for i in range(len(food_times)):
#         # (음식 시간, 음식 번호) 형태로 우선순위 큐에 삽입
#         heapq.heappush(q, (food_times[i], i + 1))
#
#     sum_value = 0 # 먹기 위해 사용한 시간
#     previous = 0 # 직전에 다 먹은 음식 시간
#     length = len(food_times) # 남은 음식의 개수
#
#     # sum_value + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
#     while sum_value + ((q[0][0] - previous) * length) <= k:
#         now = heapq.heappop(q)[0]
#         sum_value += (now - previous) * length
#         length -= 1 # 다 먹은 음식 제외
#         previous = now # 이전 음식 시간 재설정
#
#     # 남은 음식 중에서 몇 번째 음식인지 확인하여 출력
#     result = sorted(q, key=lambda x: x[1]) # 음식의 번호 기준으로 정렬
#     return result[(k - sum_value) % length][1]


# 최소 힙 풀이
import heapq


def solution(food_times, k):
    n = len(food_times)  # 전체길이
    pq = []  # 힙큐 넣을 곳
    for i in range(n):  # 힙큐 넣어줌 ( 음식양, 번호 )
        heapq.heappush(pq, (food_times[i], i + 1))

    pre_food = 0  # 가장 밑바닥
    min_food = pq[0][0]  # 현재 음식중 가장 작은 녀석

    # 사이클 돌면서 k에서 시간을 계속 빼준다.
    while True:
        # 사이클 돌았을 때 k 가 음수가 되면 빼주지 말고 나오자

        # 현재 가장 작은 음식의 초를 모든 food_times에 빼주면 반복 횟수를 줄일 수 있다.
        if k - (min_food - pre_food) * n < 0:
            break

        # 아니라면 k 빼주고
        k -= (min_food - pre_food) * n

        # 힙큐에서도 가장 작은시간인 음식(0으로 바뀐 값)을 빼준다.
        heapq.heappop(pq)
        pre_food = min_food  # 바닥은 방금 그 음식의 양이다.
        n -= 1  # 전체 길이도 하나 빼준다.

        # 만약 다 먹었는데도 k가 남아있다면
        # 음식이 부족한 상태이므로
        if not pq:
            return -1

        # 이것을 나중에 해주는 이유는 위에서 비어있을 경우 인덱스 에러가 나기 때문
        min_food = pq[0][0]

    # 전체 길이보다 남은 초가 더 많을 수 있으므로
    # 초를 길이로 나눈 나머지가 답이다.
    idx = k % n

    # 다시 번호 순으로 정렬 해주고
    pq.sort(key=lambda x: x[1])
    answer = pq[idx][1]  # 번호를 반환해준다
    return answer