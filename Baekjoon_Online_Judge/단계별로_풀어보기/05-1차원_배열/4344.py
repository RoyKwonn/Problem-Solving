C = int(input())
for _ in range(C):
    num = [int(x) for x in input().split()]
    n = num[0]
    scores = num[1:]
    mean = sum(scores) / n

    over = [s for s in scores if s > mean]

    print('%.3f%%' %round(len(over)/ n * 100, 3))