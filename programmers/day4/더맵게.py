import heapq

heap = [1,3,3,4]
heapq.heapify(heap)
k=2

def solution(scoville, K):
    ans = 0
    k=K
    heap = scoville
    heapq.heapify(heap)
    while (1):
        if len(heap) == 1:
            if -heapq.heappop(heap) < k:
                return -1
            else:
                return ans
        else:
            nval = 0
            elem = heapq.heappop(heap)
            if (elem >= k):
                return ans
            nval += elem
            nval += 2 * heapq.heappop(heap)
            heapq.heappush(heap, nval)
            ans += 1

a = [1,2,3,4]
b = 3
print(solution(a,b))

