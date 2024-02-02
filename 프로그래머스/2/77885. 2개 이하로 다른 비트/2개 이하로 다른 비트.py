def solution(numbers):
    answer = []
    for num in numbers:
        if num % 2 == 0:
            answer.append(num + 1)
        else:
            binary = bin(num)[2:]
            last_index_of_01 = binary.rfind("01")
            if last_index_of_01 >= 0:
                binary = binary[:last_index_of_01] + '10' + binary[last_index_of_01 + 2:]
            else:
                binary = '10' + binary[1:]
            answer.append(int(binary, 2))
    return answer