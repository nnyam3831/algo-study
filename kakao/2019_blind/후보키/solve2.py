# n가지 요소를 pick 하는 경우 bitmask로 가능
# DFS로 할 경우 재귀가 너무 깊어지면 오버플로가 날수도있음


def solution(relation):
    n_row = len(relation)
    n_col = len(relation[0])
    answer = list()
    for i in range(1, 1 << n_col):
        tmp_set = set()
        for j in range(n_row):
            tmp = []
            for k in range(n_col):
                if i & (1 << k):
                    tmp.append(str(relation[j][k]))
            tmp_set.add(" ".join(tmp))

        if len(tmp_set) == len(relation):
            not_duplicate = True
            for num in answer:
                if num & i == num:
                    not_duplicate = False
                    break
            if not_duplicate:
                answer.append(i)

    return len(answer)


print(
    solution(
        [
            ["100", "ryan", "music", "2"],
            ["200", "apeach", "math", "2"],
            ["300", "tube", "computer", "3"],
            ["400", "con", "computer", "4"],
            ["500", "muzi", "music", "3"],
            ["600", "apeach", "music", "2"],
        ]
    )
)
print(
    solution(
        [
            ["100", "ryan", "music", "2", "s"],
            ["200", "apeach", "math", "2", "e"],
            ["300", "tube", "computer", "3", "x"],
            ["400", "con", "computer", "4", "w"],
            ["500", "muzi", "music", "3", "o"],
            ["600", "apeach", "music", "2", "w"],
        ]
    )
)
