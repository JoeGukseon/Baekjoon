from collections import deque

def solution(queue1, queue2):
    answer = -1
    total_sum = sum(queue1) + sum(queue2)
    target_sum = total_sum / 2

    if total_sum % 2 != 0:
        return -1

    current_q1 = deque(queue1)
    current_q2 = deque(queue2)
    current_sum = sum(current_q1)
    
    operations_count = 0
    
    if max(current_q1) > target_sum or max(current_q2) > target_sum:
        return -1
    
    while current_q1 and current_q2:
        if current_sum > target_sum:
            current_sum -= current_q1.popleft()
            operations_count += 1   
        elif current_sum < target_sum:
            element = current_q2.popleft()
            current_q1.append(element)
            current_sum += element
            operations_count += 1 
        elif current_sum == target_sum:
            return operations_count
    
    return answer