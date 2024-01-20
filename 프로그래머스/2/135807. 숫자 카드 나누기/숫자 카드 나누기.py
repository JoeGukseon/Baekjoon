def solution(arrayA, arrayB):
    gcdA = arrayA[0]
    gcdB = arrayB[0]

    for num in arrayA[1:]:
        gcdA = calculate_gcd(num, gcdA)

    for num in arrayB[1:]:
        gcdB = calculate_gcd(num, gcdB)

    for num in arrayB:
        if num % gcdA == 0:
            gcdA = 0
            break

    for num in arrayA:
        if num % gcdB == 0:
            gcdB = 0
            break
            
    return max(gcdA, gcdB)

def calculate_gcd(a, b):
    while b:
        a, b = b, a % b
    return a