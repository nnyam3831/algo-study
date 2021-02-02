def solution(info, query):
    answer = []
    table = {}

    def _dfs(index, current, data):
        if index >= 4:
            return [current]

        ret = []
        ret += _dfs(index + 1, current + data[index], data)
        ret += _dfs(index + 1, current + "-", data)
        return ret

    for data in info:
        user_info = data.split(" ")
        for possible in _dfs(0, "", user_info):
            if possible in table:
                table[possible].append(int(user_info[4]))
            else:
                table[possible] = [int(user_info[4])]

    for t in table:
        table[t] = list(sorted(table[t]))

    for q in query:
        query_info = q.replace(" and", "").split(" ")
        text = "".join(query_info[:-1])
        score = int(query_info[-1])
        if text not in table:
            answer.append(0)
            continue

        start, end = 0, len(table[text])
        while start < end:
            mid = (start + end) // 2
            if table[text][mid] < score:
                start = mid + 1
            else:
                end = mid
        answer.append(len(table[text]) - start)

    return answer


print(
    solution(
        [
            "java backend junior pizza 150",
            "python frontend senior chicken 210",
            "python frontend senior chicken 150",
            "cpp backend senior pizza 260",
            "java backend junior chicken 80",
            "python backend senior chicken 50",
        ],
        [
            "java and backend and junior and pizza 100",
            "python and frontend and senior and chicken 200",
            "cpp and - and senior and pizza 250",
            "- and backend and senior and - 150",
            "- and - and - and chicken 100",
            "- and - and - and - 150",
        ],
    )
)
