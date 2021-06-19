# O(log N)으로 알고리즘을 작성하지 않으면 시간초과가 된다.

import sys

# 이진 탐색 소스코드 구현 (반복문)
def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        # 찾은 경우 중간점 인덱스 반환
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return -1

N, x = map(int, sys.stdin.readline().rstrip().split())
array = list(map(int, sys.stdin.readline().rstrip().split()))


mid = binary_search(array, x, 0, N-1)
cnt = 1

if mid == -1:
    print(-1)
else:
    for i in range(mid-1, -1, -1):
        if(array[i] != x):
            print('no', end=' ')
        else:
            print('yes', end=' ')
            cnt += 1


    for i in range(mid+1, N):
        if (array[i] != x):
            print('no', end=' ')
        else:
            print('yes', end=' ')
            cnt += 1

    print()
    print(cnt)

