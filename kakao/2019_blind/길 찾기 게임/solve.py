import sys

sys.setrecursionlimit(10 ** 6)


def solution(nodeinfo):
    answer = [[]]
    nodeinfo = [[nodeinfo[i][0], nodeinfo[i][1], i + 1] for i in range(len(nodeinfo))]
    sorted_info = sorted(nodeinfo, key=lambda x: (-x[1], x[0]))
    index_info = [None for _ in range(len(sorted_info) + 1)]
    for x, y, num in sorted_info:
        index_info[num] = [x, y]
    children = [[None, None] for _ in range(len(sorted_info) + 1)]
    root = None
    for x, y, num in sorted_info:
        if not root:
            root = num
            continue

        head = root
        while True:
            if x < index_info[head][0]:
                if not children[head][0]:
                    children[head][0] = num
                    break
                head = children[head][0]
            else:
                if not children[head][1]:
                    children[head][1] = num
                    break
                head = children[head][1]

    def _preOrder(node):
        ret = [node]
        if children[node][0]:
            ret += _preOrder(children[node][0])
        if children[node][1]:
            ret += _preOrder(children[node][1])
        return ret

    def _postOrder(node):
        ret = []
        if children[node][0]:
            ret += _postOrder(children[node][0])
        if children[node][1]:
            ret += _postOrder(children[node][1])
        return ret + [node]

    pre = _preOrder(root)
    post = _postOrder(root)

    return [pre, post]


solution([[5, 3], [11, 5], [13, 3], [3, 5], [6, 1], [1, 3], [8, 6], [7, 2], [2, 2]])
