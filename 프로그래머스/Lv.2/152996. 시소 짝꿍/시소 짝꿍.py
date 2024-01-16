def solution(weights):
    # 무게를 저장하는 딕셔너리
    weight_occurrences = {}

    # 시소 짝꿍의 총 개수를 저장할 변수
    total_couples = 0

    # 무게 리스트를 오름차순으로 정렬
    weights.sort()

    # 무게 리스트를 순회하며 시소 짝꿍 찾기
    for current_weight in weights:
        # 현재 무게에서의 토크 값들 계산
        weight_a = current_weight * 1.0   # 1
        weight_b = (current_weight * 2.0) / 3.0   # 2/3
        weight_c = (current_weight * 1.0) / 2.0   # 1/2
        weight_d = (current_weight * 3.0) / 4.0   # 3/4

        # 이미 나온 토크 값들이 저장된 딕셔너리에서 해당 토크가 나온 횟수를 가져와 누적
        total_couples += weight_occurrences.get(weight_a, 0)
        total_couples += weight_occurrences.get(weight_b, 0)
        total_couples += weight_occurrences.get(weight_c, 0)
        total_couples += weight_occurrences.get(weight_d, 0)

        # 현재 무게의 토크 값을 딕셔너리에 추가하고 등장 횟수를 1 증가
        weight_occurrences[weight_a] = weight_occurrences.get(weight_a, 0) + 1

    # 최종적으로 계산된 시소 짝꿍의 개수 반환
    return total_couples