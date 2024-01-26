from functools import cmp_to_key

def solution(numbers):
    zero = all(n == 0 for n in numbers)
    if zero:
        return "0"

    def custom_compare(a, b):
        return (int(b + a) - int(a + b))
    
    arr_str = sorted(map(str, numbers), key=cmp_to_key(custom_compare))
    result = ''.join(arr_str)

    return result