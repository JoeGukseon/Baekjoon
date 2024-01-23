from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0

    bridge = deque([0] * bridge_length)
    bridge_cur_weight = 0
    idx = 0

    while bridge:
        answer += 1
        bridge_cur_weight -= bridge.popleft()

        if idx < len(truck_weights):
            if bridge_cur_weight + truck_weights[idx] <= weight:
                bridge.append(truck_weights[idx])
                bridge_cur_weight += truck_weights[idx]
                idx += 1
            else:
                bridge.append(0)

    return answer