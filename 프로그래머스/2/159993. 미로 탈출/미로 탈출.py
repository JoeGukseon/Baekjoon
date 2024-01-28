from collections import deque

def solution(maps):
    rows, cols = len(maps), len(maps[0])

    start, lever, exit = None, None, None
    for i in range(rows):
        for j in range(cols):
            current = maps[i][j]

            if current == 'S':
                start = (i, j)
            elif current == 'L':
                lever = (i, j)
            elif current == 'E':
                exit = (i, j)

    lever_distance = bfs(maps, start, lever)

    if lever_distance == -1:
        return -1

    exit_distance = bfs(maps, lever, exit)

    if exit_distance == -1:
        return -1

    return lever_distance + exit_distance

def bfs(maps, start, target):
    dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
    rows, cols = len(maps), len(maps[0])

    visited = set()
    queue = deque([(start, 0)])
    visited.add(start)

    while queue:
        current, time = queue.popleft()

        if current == target:
            return time

        for d in range(4):
            ni, nj = current[0] + dx[d], current[1] + dy[d]

            if 0 <= ni < rows and 0 <= nj < cols and maps[ni][nj] != 'X' and (ni, nj) not in visited:
                queue.append(((ni, nj), time + 1))
                visited.add((ni, nj))

    return -1