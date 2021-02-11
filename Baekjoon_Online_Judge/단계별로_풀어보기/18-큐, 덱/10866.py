import sys

N = int(sys.stdin.readline())
deque = []

for _ in range(N):
    inp = sys.stdin.readline()[:-1]

    if inp[:10] == 'push_front':
        deque.insert(0, inp.split()[1])
    elif inp[:9] == 'push_back':
        deque.append(inp.split()[1])
    elif inp == 'pop_front':
        print(deque.pop(0) if deque else -1)
    elif inp == 'pop_back':
        print(deque.pop() if deque else -1)
    elif inp == 'size':
        print(len(deque))
    elif inp == 'empty':
        print(0 if deque else 1)
    elif inp == 'front':
        print(deque[0] if deque else -1)
    elif inp == 'back':
        print(deque[-1] if deque else -1)