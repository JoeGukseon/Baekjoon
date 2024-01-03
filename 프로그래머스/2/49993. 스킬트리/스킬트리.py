def solution(skill, skill_trees):
    answer = 0

    for skillTree in skill_trees:
        isOk = True
        curIdx = 0
        for sk in skillTree:
            if sk == skill[curIdx]:
                if curIdx < len(skill) - 1:
                    curIdx += 1
            elif sk not in skill:
                pass
            else:
                isOk = False
                break
        if isOk:
            answer += 1

    return answer