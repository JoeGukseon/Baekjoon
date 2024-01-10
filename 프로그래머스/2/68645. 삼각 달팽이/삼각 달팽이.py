def solution(n):
    arr = [[0] * n for _ in range(n)]

    num = 1
    row = -1
    col = 0

    arr[row + 1][col] = num

    for i in range(n, 0, -3):
        for j in range(i):
            row += 1
            arr[row][col] = num
            num += 1
        for j in range(i - 1):
            col += 1
            arr[row][col] = num
            num += 1
        for j in range(i - 2):
            row -= 1
            col -= 1
            arr[row][col] = num
            num += 1

    answer = [arr[i][j] for i in range(n) for j in range(n) if arr[i][j] != 0]

    return answer