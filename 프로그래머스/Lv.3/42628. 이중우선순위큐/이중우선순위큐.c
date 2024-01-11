#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
} Element;

int compareMin(const void* a, const void* b) {
    return ((Element*)a)->value - ((Element*)b)->value;
}

int compareMax(const void* a, const void* b) {
    return ((Element*)b)->value - ((Element*)a)->value;
}

int* solution(char** operations, int operationsSize, int* returnSize) {
    Element* minHeap = NULL;
    Element* maxHeap = NULL;
    int minHeapSize = 0;
    int maxHeapSize = 0;

    for (int i = 0; i < operationsSize; i++) {
        char op;
        int num;
        sscanf(operations[i], "%c %d", &op, &num);

        if (op == 'I') {
            minHeap = (Element*)realloc(minHeap, (minHeapSize + 1) * sizeof(Element));
            minHeap[minHeapSize].value = num;

            maxHeap = (Element*)realloc(maxHeap, (maxHeapSize + 1) * sizeof(Element));
            maxHeap[maxHeapSize].value = -num;

            minHeapSize++;
            maxHeapSize++;
        } else if (op == 'D' && num == 1) {
            if (maxHeapSize > 0) {
                maxHeapSize--;
                minHeapSize--;
                maxHeap[0] = maxHeap[maxHeapSize];
                minHeap[0] = minHeap[minHeapSize];
                qsort(maxHeap, maxHeapSize, sizeof(Element), compareMax);
                qsort(minHeap, minHeapSize, sizeof(Element), compareMin);
            }
        } else if (op == 'D' && num == -1) {
            if (minHeapSize > 0) {
                maxHeapSize--;
                minHeapSize--;
                maxHeap[0] = maxHeap[maxHeapSize];
                minHeap[0] = minHeap[minHeapSize];
                qsort(maxHeap, maxHeapSize, sizeof(Element), compareMax);
                qsort(minHeap, minHeapSize, sizeof(Element), compareMin);
            }
        }
    }

    int commonValuesSize = 0;
    int* commonValues = NULL;

    for (int i = 0; i < minHeapSize; i++) {
        for (int j = 0; j < maxHeapSize; j++) {
            if (minHeap[i].value == -maxHeap[j].value) {
                commonValues = (int*)realloc(commonValues, (commonValuesSize + 1) * sizeof(int));
                commonValues[commonValuesSize++] = minHeap[i].value;
            }
        }
    }

    if (commonValuesSize == 0) {
        *returnSize = 2;
        int* result = (int*)malloc(2 * sizeof(int));
        result[0] = 0;
        result[1] = 0;
        free(minHeap);
        free(maxHeap);
        return result;
    }

    qsort(commonValues, commonValuesSize, sizeof(int), compareMax);

    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = commonValues[0];
    result[1] = commonValues[commonValuesSize - 1];

    free(minHeap);
    free(maxHeap);
    free(commonValues);

    return result;
}

int main() {
    char* operations1[] = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    char* operations2[] = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};

    int returnSize1, returnSize2;
    int* result1 = solution(operations1, sizeof(operations1) / sizeof(operations1[0]), &returnSize1);
    int* result2 = solution(operations2, sizeof(operations2) / sizeof(operations2[0]), &returnSize2);

    printf("[%d, %d]\n", result1[0], result1[1]);
    printf("[%d, %d]\n", result2[0], result2[1]);

    free(result1);
    free(result2);

    return 0;
}
