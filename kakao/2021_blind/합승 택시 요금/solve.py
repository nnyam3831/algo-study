def solution(n, s, a, b, fares):
    INF = 1000000000
    d = [[0 if i == j else INF for j in range(n + 1)] for i in range(n + 1)]
    for fare in fares:
        [f, t, value] = fare
        d[f][t] = value
        d[t][f] = value

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                d[i][j] = min(d[i][k] + d[k][j], d[i][j])

    answer = INF
    for k in range(1, n + 1):
        answer = min(answer, d[s][k] + d[k][a] + d[k][b])

    return answer


print(
    solution(
        6,
        4,
        6,
        2,
        [
            [4, 1, 10],
            [3, 5, 24],
            [5, 6, 2],
            [3, 1, 41],
            [5, 1, 24],
            [4, 6, 50],
            [2, 4, 66],
            [2, 3, 22],
            [1, 6, 25],
        ],
    )
)
print(solution(7, 3, 4, 1, [[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]]))
print(
    solution(
        6,
        4,
        5,
        6,
        [
            [2, 6, 6],
            [6, 3, 7],
            [4, 6, 7],
            [6, 5, 11],
            [2, 5, 12],
            [5, 3, 20],
            [2, 4, 8],
            [4, 3, 9],
        ],
    )
)
