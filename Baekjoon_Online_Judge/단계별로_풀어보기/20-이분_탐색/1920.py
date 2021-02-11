while True:
    n, *heights = list(map(int, input().split()))
    if n == 0:
        break

    heights.insert(0, 0)
    heights.append(0)
    checked = [0]
    area = 0

    for i in range(1, n + 2):
        while checked and (heights[checked[-1]] > heights[i]):
            cur_height = checked.pop()
            area = max(area, (i - 1 - checked[-1]) * heights[cur_height])
        checked.append(i)
    print(area)