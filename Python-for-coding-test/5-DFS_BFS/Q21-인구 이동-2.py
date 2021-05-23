import sys
input = sys.stdin.readline

n, l, r = map(int, input().split())
board = [list(map(int, input().split())) for y in range(n)]

# 람다함수로 만들기
is_rangeout = lambda y, x: y < 0 or x < 0 or y >= n or x >= n
dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def is_moveable(from_yx, to_yx):
    fy, fx = from_yx
    ty, tx = to_yx
    return l <= abs(board[fy][fx] - board[ty][tx]) <= r


def move_people():
    visited = [[False] * n for _ in range(n)]

    def get_area_sum(y, x, settable):
        visited[y][x] = True
        settable.append((y, x))
        ret = board[y][x]  # sum

        for dy, dx in dirs:
            ny, nx = y + dy, x + dx
            if is_rangeout(ny, nx) or visited[ny][nx]:
                continue
            if not is_moveable((y, x), (ny, nx)):
                continue
            ret += get_area_sum(ny, nx, settable)
        return ret

    def set_area(v, settable):
        for y, x in settable:
            board[y][x] = v

    flag = False
    for y in range(n):
        for x in range(n):
            if visited[y][x]:
                continue
            settable = []
            area_sum = get_area_sum(y, x, settable)
            if len(settable) <= 1:
                continue

            set_area(area_sum // len(settable), settable)
            flag = True

    return flag


for count in range(1, 2001):  # 인구 이동이 발생하는 횟수 2,000번 보다 작거나 같은 입력값만 주어진다.
    if not move_people():
        print(count - 1)
        break