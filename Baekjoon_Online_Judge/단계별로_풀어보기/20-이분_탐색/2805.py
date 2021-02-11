N,M = [int(x) for x in input().split()]
trees = [int(x) for x in input().split()]

def search(target):
    start,end=0, max(trees)
    ans = 0
    while start <= end:
        mid = (start+end)//2

        s = 0
        for t in trees:
            if t-mid >0:
                s += t - mid
        if s < target :
            end = mid -1
        if s >= target:
            ans = mid
            start = mid + 1

    return ans

print(search(M))