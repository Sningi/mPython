from heapq import *
from random import shuffle
data = range(0, 10)
# print(data)
shuffle(data)
heap = []
for n in data:
    heappush(heap, n)
print(heap)
print(heappop(heap))
print(heappop(heap))
