def solution(relation):
    answer = 0
    rows, cols = len(relation), len(relation[0])
    used = []

    def _comb(number, index, buffer, targets):
        if len(buffer) == number:
            targets.append(buffer)
            return

        for i in range(index, cols):
            _comb(number, i + 1, buffer + [i], targets)

    for col in range(1, cols + 1):
        targets = []
        _comb(col, 0, [], targets)
        for target in targets:
            state = ""
            for elem in target:
                state += str(elem)

            skip = False
            for elem in used:
                flag = True
                for c in elem:
                    if not c in state:
                        flag = False
                        break
                if flag:
                    skip = True
            if len(used) != 0 and skip:
                continue

            # check uniqueness
            table = {}
            is_possible = True
            for row in relation:
                uid = ""
                for idx in target:
                    uid += row[idx]
                if uid in table:
                    is_possible = False
                    break

                table[uid] = True

            if is_possible:
                used.append(state)
                answer += 1

    return answer


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
