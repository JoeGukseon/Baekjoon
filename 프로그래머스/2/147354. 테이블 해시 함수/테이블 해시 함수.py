def solution(data, col, row_begin, row_end):
    data.sort(key=lambda x: (x[col - 1], -x[0]))

    hash_value = 0

    for i in range(row_begin - 1, row_end):
        si = sum(data[i][j] % (i + 1) for j in range(len(data[i])))
        hash_value ^= si

    return hash_value