def solution(N, stages):
    answer = []
    fail = [0 for _ in range(N + 2)]
    challenge = [0 for _ in range(N + 2)]
    for stage in stages:
        for i in range(stage + 1):
            challenge[i] += 1
        fail[stage] += 1

    temp = []
    for i in range(1, N + 1):
        if challenge[i] == 0:
            score = 0
        else:
            score = fail[i] / challenge[i]
        temp.append([score, i])
    answer = [elem[1] for elem in list(sorted(temp, key=lambda x: (-x[0], x[1])))]
    return answer


print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
print(solution(4, [4, 4, 4, 4, 4]))
