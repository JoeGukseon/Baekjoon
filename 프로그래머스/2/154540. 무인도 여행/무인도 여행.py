from queue import Queue

def solution(maps):
    directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

    visited = [[False for _ in range(len(maps[0]))] for _ in range(len(maps))]
    result = []

    map_array = [list(row) for row in maps]

    for y in range(len(maps)):
        for x in range(len(maps[y])):
            if not visited[y][x] and maps[y][x] != 'X':
                queue = Queue()
                queue.put((x, y))
                visited[y][x] = True
                total_sum = 0

                while not queue.empty():
                    pos = queue.get()
                    cur_x, cur_y = pos[0], pos[1]

                    total_sum += int(map_array[cur_y][cur_x])

                    for d in directions:
                        new_x, new_y = cur_x + d[0], cur_y + d[1]

                        if 0 <= new_y < len(map_array) and 0 <= new_x < len(map_array[0]) and not visited[new_y][new_x] and map_array[new_y][new_x] != 'X':
                            queue.put((new_x, new_y))
                            visited[new_y][new_x] = True

                result.append(total_sum)

    if not result:
        return [-1]

    return sorted(result)