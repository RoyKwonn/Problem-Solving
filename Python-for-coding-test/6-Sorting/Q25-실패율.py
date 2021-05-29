# 실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

# N = 전체 스테이지의 개수
# 배열은 각 사용자들이 멈춰있는 스테이지 번호

# 실패율이 높은 스ㅔ이지부터 내림차순으로 스테이지 번호가 답겨있는 배열을 리턴


def solution(N, stages):
    answer = []
    length = len(stages)


    for i in range(1, N + 1):
        count = stages.count(i)  # i가 들어있는 갯수

        if length == 0:  # 이 조건도 꼭 넣어줘야한다.
            fail = 0
        else:
            fail = count / length

        answer.append((i, fail))
        length -= count

    answer = sorted(answer, key=lambda t: t[1], reverse=True)

    answer = [i[0] for i in answer]
    return answer