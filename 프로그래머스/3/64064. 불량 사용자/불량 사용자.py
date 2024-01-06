def solution(user_id, banned_id):
    result_set = set()

    def is_match(user, banned):
        if len(user) != len(banned):
            return False
        for u, b in zip(user, banned):
            if b != '*' and b != u:
                return False
        return True

    def dfs(visited, depth):
        if depth == len(banned_id):
            result_set.add(tuple(visited))
            return

        for i in range(len(user_id)):
            if not visited[i] and is_match(user_id[i], banned_id[depth]):
                visited[i] = True
                dfs(visited, depth + 1)
                visited[i] = False

    dfs([False] * len(user_id), 0)
    
    return len(result_set)