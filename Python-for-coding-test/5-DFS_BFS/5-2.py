# QUEUE
from collections import deque

# queue를 구현하기 위해 deque 라이브러리 사용
queue = deque()

# 3-7-1-4

queue.append(5)
queue.append(2)
queue.append(3)
queue.append(7)
queue.popleft()
queue.append(1)
queue.append(4)
queue.popleft()

print(queue) # 먼저 들어온 순서대로 출력
queue.reverse()
print(queue)
