def solution(n, stations, w):
    answer = 0
    idx = 0

    i = 1
    while i <= n:
        if idx < len(stations) and i >= stations[idx] - w:
            i = stations[idx] + w + 1
            idx += 1
        else:
            answer += 1
            i += 2 * w + 1  

    return answer