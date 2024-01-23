#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void initQueue(Queue *q, int initialCapacity) {
    q->array = (int*)malloc(initialCapacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = initialCapacity;
}

void destroyQueue(Queue *q) {
    free(q->array);
}

void enqueue(Queue *q, int item) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->array = (int*)realloc(q->array, q->capacity * sizeof(int));
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size++;
}

int dequeue(Queue *q) {
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    if (q->size <= q->capacity / 4 && q->capacity > 4) {
        q->capacity /= 2;
        q->array = (int*)realloc(q->array, q->capacity * sizeof(int));
    }

    return item;
}

int solution(int bridge_length, int weight, int truck_weights[], int truck_count) {
    int answer = 0;
    int idx = 0;
    int sum = 0;

    Queue q;
    initQueue(&q, bridge_length);

    while (1) {
        if (idx == truck_count) {
            answer += bridge_length;
            break;
        }

        answer++;
        int tmp = truck_weights[idx];

        if (q.size == bridge_length) {
            sum -= dequeue(&q);
        }

        if (sum + tmp <= weight) {
            sum += tmp;
            enqueue(&q, tmp);
            idx++;
        } else {
            enqueue(&q, 0);
        }
    }

    destroyQueue(&q);
    return answer;
}

int main() {
    // 테스트 케이스 1
    int bridge_length1 = 2;
    int weight1 = 10;
    int truck_weights1[] = {7, 4, 5, 6};
    int truck_count1 = sizeof(truck_weights1) / sizeof(truck_weights1[0]);

    int result1 = solution(bridge_length1, weight1, truck_weights1, truck_count1);
    printf("Test Case 1: %d\n", result1);

    // 테스트 케이스 2
    int bridge_length2 = 100;
    int weight2 = 100;
    int truck_weights2[] = {10};
    int truck_count2 = sizeof(truck_weights2) / sizeof(truck_weights2[0]);

    int result2 = solution(bridge_length2, weight2, truck_weights2, truck_count2);
    printf("Test Case 2: %d\n", result2);

    // 테스트 케이스 3
    int bridge_length3 = 100;
    int weight3 = 100;
    int truck_weights3[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int truck_count3 = sizeof(truck_weights3) / sizeof(truck_weights3[0]);

    int result3 = solution(bridge_length3, weight3, truck_weights3, truck_count3);
    printf("Test Case 3: %d\n", result3);

    return 0;
}
