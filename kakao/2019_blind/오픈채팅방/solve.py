def solution(record):
    answer = []
    id_table = {}
    temp = []
    for info in record:
        infos = info.split()
        if len(infos) == 2:
            com, uid = infos
        else:
            com, uid, nickname = infos

        if com == "Enter":
            log = [str(uid), "님이 들어왔습니다."]
            id_table[uid] = nickname
            temp.append(log)

        if com == "Leave":
            log = [str(uid), "님이 나갔습니다."]
            temp.append(log)

        if com == "Change":
            id_table[uid] = nickname

    for info in temp:
        info[0] = id_table[info[0]]
        answer.append("".join(info))

    return answer


print(
    solution(
        [
            "Enter uid1234 Muzi",
            "Enter uid4567 Prodo",
            "Leave uid1234",
            "Enter uid1234 Prodo",
            "Change uid4567 Ryan",
        ]
    )
)
