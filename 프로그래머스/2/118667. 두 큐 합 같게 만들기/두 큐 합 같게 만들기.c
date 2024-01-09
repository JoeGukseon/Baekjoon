#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *array;
    int front;
    int rear;
} Queue;

void initQueue(Queue *q, int size) {
    q->array = (int *)malloc(sizeof(int) * size * 2);
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return (q->front == q->rear);
}

void enqueue(Queue *q, int element) {
    q->array[q->rear++] = element;
}

int dequeue(Queue *q) {
    return q->array[q->front++];
}

void freeQueue(Queue *q) {
    free(q->array);
}

int max(Queue *q) {
    int max = INT_MIN;
    for (int i = q->front; i < q->rear; i++) {
        max = (q->array[i] > max) ? q->array[i] : max;
    }
    return max;
}

// queue1_len은 배열 queue1의 길이입니다.
// queue2_len은 배열 queue2의 길이입니다.
int solution(int queue1[], size_t queue1_len, int queue2[], size_t queue2_len) {
    Queue q1, q2;
    initQueue(&q1, queue1_len);
    initQueue(&q2, queue2_len);

    long long sumQ1 = 0, sumQ2 = 0;

    for (int i = 0; i < queue1_len; i++) {
        enqueue(&q1, queue1[i]);
        sumQ1 += queue1[i];
    }
    for (int i = 0; i < queue2_len; i++) {
        enqueue(&q2, queue2[i]);
        sumQ2 += queue2[i];
    }

    long long totalSum = sumQ1 + sumQ2;
    long long targetSum = totalSum / 2;

    if (totalSum % 2 != 0) {
        return -1;
    }

    long long currentSum = sumQ1;

    int operationsCount = 0;

    if (max(&q1) > targetSum || max(&q2) > targetSum) {
        return -1;
    }

    while (!isEmpty(&q1) && !isEmpty(&q2)) {
        if (currentSum > targetSum) {
            currentSum -= dequeue(&q1);
            operationsCount++;
        } else if (currentSum < targetSum) {
            int element = dequeue(&q2);
            enqueue(&q1, element);
            currentSum += element;
            operationsCount++;
        } else if (currentSum == targetSum) {
            return operationsCount;
        }
    }

    freeQueue(&q1);
    freeQueue(&q2);

    return -1;
}