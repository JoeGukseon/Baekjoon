#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Set {
    int* elements;
    int size;
};

struct Set createSet() {
    struct Set set;
    set.elements = NULL;
    set.size = 0;
    return set;
}

bool contains(struct Set* set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return true;
        }
    }
    return false;
}

void add(struct Set* set, int element) {
    if (!contains(set, element)) {
        set->size++;
        set->elements = (int*)realloc(set->elements, set->size * sizeof(int));
        set->elements[set->size - 1] = element;
    }
}

void freeSet(struct Set* set) {
    free(set->elements);
}

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    struct Set frontSet = createSet();
    struct Set backSet = createSet();
    int* frontCnt = (int*)malloc(topping_len * sizeof(int));
    int* backCnt = (int*)malloc(topping_len * sizeof(int));

    for (int i = 0; i < topping_len; i++) {
        add(&frontSet, topping[i]);
        add(&backSet, topping[topping_len - i - 1]);
        backCnt[topping_len - 1 - i] = backSet.size;
        frontCnt[i] = frontSet.size;
    }

    for (int i = 0; i < topping_len - 1; i++) {
        if (frontCnt[i] == backCnt[i + 1]) {
            answer++;
        }
    }

    freeSet(&frontSet);
    freeSet(&backSet);
    free(frontCnt);
    free(backCnt);

    return answer;
}