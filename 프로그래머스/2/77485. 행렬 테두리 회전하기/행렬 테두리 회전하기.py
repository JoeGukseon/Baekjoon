def solution(rows, columns, queries):
    matrix = [[(i - 1) * columns + j for j in range(1, columns + 1)] for i in range(1, rows + 1)]
    result = []

    for query in queries:
        result.append(rotate(matrix, query[0], query[1], query[2], query[3]))

    return result

def rotate(matrix, x1, y1, x2, y2):
    temp = matrix[x1 - 1][y1 - 1]
    min_val = temp

    for i in range(y1, y2):
        matrix[x1 - 1][i], temp = temp, matrix[x1 - 1][i]
        min_val = min(min_val, temp)

    for i in range(x1, x2):
        matrix[i][y2 - 1], temp = temp, matrix[i][y2 - 1]
        min_val = min(min_val, temp)

    for i in range(y2 - 2, y1 - 2, -1):
        matrix[x2 - 1][i], temp = temp, matrix[x2 - 1][i]
        min_val = min(min_val, temp)

    for i in range(x2 - 2, x1 - 2, -1):
        matrix[i][y1 - 1], temp = temp, matrix[i][y1 - 1]
        min_val = min(min_val, temp)

    return min_val