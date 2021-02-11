N, _ = [int(x) for x in input().split()]
indices = [int(x) for x in input().split()]
queue = list(range(1, N+1))

ret = 0
for i in indices:
    idx = queue.index(i)
    if len(queue) - idx < idx:
        ret += len(queue) - idx
    else:
        ret += idx
    queue = queue[idx+1:] + queue[:idx]
print(ret)