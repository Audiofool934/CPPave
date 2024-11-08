import heapq

k, n, m = map(int, input().split())
U = list(map(int, input().split()))
V = list(map(int, input().split()))

# 创建优先队列
heap1 = [(U[i], i) for i in range(n)]
heap2 = [(V[i], i) for i in range(m)]
heapq.heapify(heap1)
heapq.heapify(heap2)

max_time = 0
for _ in range(k):
    # 从第一步的优先队列中取出一个机器
    time1, i = heapq.heappop(heap1)
    # 从第二步的优先队列中取出一个机器
    time2, j = heapq.heappop(heap2)
    # 计算处理材料所需的总时间
    total_time = time1 + time2
    max_time = max(max_time, total_time)
    # 将机器放回队列
    heapq.heappush(heap1, (time1 + U[i], i))
    heapq.heappush(heap2, (time2 + V[j], j))

print(max_time)