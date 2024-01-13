def is_prime(n):
    if n <= 1:
        return False
    elif n == 2:
        return True
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
    
def solution(n, k):
    answer = 0
    s = ""

    while n > 0:
        s = str(n % k) + s
        n //= k

    i = 0
    while i < len(s):
        if s[i] == '0':
            i += 1
            continue

        j = i + 1
        while j < len(s) and s[j] != '0':
            j += 1

        number = int(s[i:j])
        if is_prime(number):
            answer += 1

        i = j

    return answer