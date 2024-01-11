import heapq

def solution(operations):
    min_heap = []
    max_heap = []

    for operation in operations:
        op, num = operation.split()
        num = int(num)

        if op == "I":
            heapq.heappush(min_heap, num)
            heapq.heappush(max_heap, -num)
        elif op == "D" and num == 1:
            if max_heap:
                min_heap.remove(-heapq.heappop(max_heap))
        elif op == "D" and num == -1:
            if min_heap:
                max_heap.remove(-heapq.heappop(min_heap))

    common_values = list(set(min_heap) & set(-x for x in max_heap))

    if not common_values:
        return [0, 0]

    common_values.sort(reverse=True)
    return [common_values[0], common_values[-1]]