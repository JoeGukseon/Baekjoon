#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double key;
    int value;
} Entry;

typedef struct {
    Entry *entries;
    size_t size;
} HashMap;

HashMap* createHashMap(size_t initialSize) {
    HashMap *map = (HashMap*)malloc(sizeof(HashMap));
    map->entries = (Entry*)malloc(sizeof(Entry) * initialSize);
    map->size = initialSize;
    for (size_t i = 0; i < initialSize; i++) {
        map->entries[i].key = -1;
        map->entries[i].value = 0;
    }
    return map;
}

void put(HashMap *map, double key, int value) {
    size_t index = (size_t)key % map->size;

    while (map->entries[index].key != -1 && map->entries[index].key != key) {
        index = (index + 1) % map->size;
    }

    map->entries[index].key = key;
    map->entries[index].value = value;
}

int getOrDefault(HashMap *map, double key, int defaultValue) {
    size_t index = (size_t)key % map->size;

    while (map->entries[index].key != -1 && map->entries[index].key != key) {
        index = (index + 1) % map->size;
    }

    return map->entries[index].key == key ? map->entries[index].value : defaultValue;
}

void freeHashMap(HashMap *map) {
    free(map->entries);
    free(map);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long long solution(int weights[], size_t weights_len) {
    // 무게를 저장하는 배열
    HashMap *weightOccurrences = createHashMap(1000);

    long long totalCouples = 0;

    // 무게 배열을 오름차순으로 정렬
    qsort(weights, weights_len, sizeof(int), compare);

    // 무게 배열을 순회하며 시소 짝꿍 찾기
    for (int i = 0; i < weights_len; i++) {
        int currentWeight = weights[i];
        // 현재 무게에서의 토크 값들 계산
        double weightA = (double)currentWeight;         // 1
        double weightB = (double)currentWeight * 2 / 3; // 2/3
        double weightC = (double)currentWeight / 2;     // 1/2
        double weightD = (double)currentWeight * 3 / 4; // 3/4

        // 이진 탐색을 통해 해당 토크의 맵 내 위치 찾기
        totalCouples += getOrDefault(weightOccurrences, weightA, 0);
        totalCouples += getOrDefault(weightOccurrences, weightB, 0);
        totalCouples += getOrDefault(weightOccurrences, weightC, 0);
        totalCouples += getOrDefault(weightOccurrences, weightD, 0);

        // 현재 무게의 토크 값을 맵에 추가하고 등장 횟수를 1 증가
        put(weightOccurrences, weightA, getOrDefault(weightOccurrences, weightA, 0) + 1);

    }

    freeHashMap(weightOccurrences);
    
    // 최종적으로 계산된 시소 짝꿍의 개수 반환
    return totalCouples;
}