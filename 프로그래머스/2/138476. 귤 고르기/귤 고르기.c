#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} KeyValuePair;

int compare(const void *a, const void *b) {
    return ((KeyValuePair *)b)->value - ((KeyValuePair *)a)->value;
}

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;

    KeyValuePair *fruitCount = (KeyValuePair *)malloc(tangerine_len * sizeof(KeyValuePair));
    int count = 0;
    for (int i = 0; i < tangerine_len; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (fruitCount[j].key == tangerine[i]) {
                fruitCount[j].value++;
                found = 1;
                break;
            }
        }
        if (!found) {
            fruitCount[count].key = tangerine[i];
            fruitCount[count].value = 1;
            count++;
        }
    }

    qsort(fruitCount, count, sizeof(KeyValuePair), compare);

    for (int i = 0; i < count; i++) {
        if (k <= 0) {
            break;
        }
        answer++;
        k -= fruitCount[i].value;
    }

    free(fruitCount);
    return answer;
}