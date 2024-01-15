def solution(storey):
    total_magic_stones = 0

    while storey != 0:
        last_digit = storey % 10

        if last_digit > 5:
            total_magic_stones += (10 - last_digit)
            storey += 10
        elif last_digit < 5:
            total_magic_stones += last_digit
        else:
            next_digit = (storey // 10) % 10
            if next_digit > 4:
                storey += 10
            total_magic_stones += last_digit

        storey //= 10

    return total_magic_stones