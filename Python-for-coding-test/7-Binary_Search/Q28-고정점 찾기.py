#Fixed Point
import sys

def FixedPoint_search(array, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == mid:
            return mid
        elif array[mid] > mid:
            end = mid - 1
        else:
            start = mid + 1
    return -1

N = int(input())
array = list(map(int, sys.stdin.readline().rstrip().split()))

result = FixedPoint_search(array, 0, N)
print(result)