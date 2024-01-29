def solution(k, dungeons):
    visited = [False] * len(dungeons)
    return dfs(0, k, dungeons, visited)

def dfs(depth, k, dungeons, visited):
        answer = 0
        for i in range(len(dungeons)):
            if not visited[i] and dungeons[i][0] <= k:
                visited[i] = True

                answer = max(answer, dfs(depth + 1, k - dungeons[i][1], dungeons, visited))

                visited[i] = False

        return max(answer, depth)