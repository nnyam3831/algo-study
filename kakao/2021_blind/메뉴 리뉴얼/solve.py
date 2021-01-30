def solution(orders, course):
    table = {}

    def _dfs(index, text, current):
        if index >= len(text):
            return

        combination = current + text[index]
        if current + text[index] in table:
            table[combination] += 1
        else:
            table[combination] = 1
        _dfs(index + 1, text, current)
        _dfs(index + 1, text, combination)

    for order in orders:
        _dfs(0, "".join(sorted(order)), "")

    targets = [None for _ in range(10 + 1)]
    for key, value in table.items():
        length = len(key)
        if not targets[length]:
            targets[length] = [value, key]
        else:
            if targets[length][0] < value:
                targets[length] = [value, key]
            elif targets[length][0] == value:
                targets[length].append(key)
    answer = []
    for n in course:
        if targets[n] and targets[n][0] >= 2:
            answer += targets[n][1:]
    answer = list(sorted(answer))
    return answer