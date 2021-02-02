def formatter(log):
    [hh, mm, ss] = map(int, log.split(":"))
    total = 3600 * hh + 60 * mm + ss
    return total


def reFormatter(n):
    hh, remainder = str(n // 3600), n % 3600
    mm, ss = str(remainder // 60), str(remainder % 60)

    def _addOffset(num):
        while len(num) < 2:
            num = "0" + num
        return num

    return _addOffset(hh) + ":" + _addOffset(mm) + ":" + _addOffset(ss)


def solution(play_time, adv_time, logs):
    play_time_sec = formatter(play_time)
    adv_time_sec = formatter(adv_time)
    total_time = [0 for _ in range(play_time_sec + 1)]
    for log in logs:
        [start, end] = map(formatter, log.split("-"))
        total_time[start] = total_time[start] + 1
        total_time[end] = total_time[end] - 1

    for i in range(1, play_time_sec):
        total_time[i] = total_time[i] + total_time[i - 1]

    for i in range(1, play_time_sec):
        total_time[i] = total_time[i] + total_time[i - 1]

    max_time = 0
    answer = 0
    for i in range(adv_time_sec - 1, play_time_sec):
        if i >= adv_time_sec:
            value = total_time[i] - total_time[i - adv_time_sec]
            if value > max_time:
                answer = i - adv_time_sec + 1
            max_time = max(max_time, value)
        else:
            max_time = max(max_time, total_time[i])

    return reFormatter(answer)


print(
    solution(
        "02:03:55",
        "00:14:15",
        [
            "01:20:15-01:45:14",
            "00:40:31-01:00:00",
            "00:25:50-00:48:29",
            "01:30:59-01:53:29",
            "01:37:44-02:02:30",
        ],
    )
)

print(
    solution(
        "99:59:59",
        "25:00:00",
        [
            "69:59:59-89:59:59",
            "01:00:00-21:00:00",
            "79:59:59-99:59:59",
            "11:00:00-31:00:00",
        ],
    )
)

print(
    solution(
        "50:00:00",
        "50:00:00",
        ["15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"],
    )
)
