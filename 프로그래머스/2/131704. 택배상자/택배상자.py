def solution(order):
    aux = []
    idx = 1
    cnt = 0
    while idx < len(order) + 1:
        aux.append(idx)
        while aux and aux[-1] == order[cnt]:
            cnt += 1
            aux.pop()
        idx += 1

    return cnt