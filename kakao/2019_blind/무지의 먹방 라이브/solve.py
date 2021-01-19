from queue import PriorityQueue


def solution(food_times, k):
    if sum(food_times) <= k:
        return -1

    answer, length = 0, len(food_times)
    q = PriorityQueue()
    for i in range(length):
        q.put((food_times[i], i + 1))
    accum, prev = 0, 0

    while accum + (q.queue[0][0] - prev) * length <= k:
        now = q.get()[0]
        accum += (now - prev) * length
        length -= 1
        prev = now

    result = sorted(q.queue, key=lambda x: x[1])
    answer = result[(k - accum) % length][1]
    return answer