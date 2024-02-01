#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HOUR 0
#define MIN 1
#define CAR_NUMBER_MAX 10000
#define INOUT 11
#define IN 1
#define OUT 0

// 차량 정보를 담는 구조체
typedef struct {
    int carNumber;
    int inOut; // 0: OUT, 1: IN
    int entryTime[2]; // [시, 분]
    int totalTime; // 누적 주차 시간 (분)
} CarInfo;

// 문자열을 숫자로 변환하는 함수
int toInteger(const char *str, int start, int n) {
    int num = 0;
    str += start;

    for (int i = n - 1, ten = 1; i >= 0; i--, ten *= 10) {
        num += (str[i] - '0') * ten;
    }

    return num;
}

// // 차량 정보 초기화 함수
// void initializeCarInfo(CarInfo *car, int num) {
//     car->carNumber = num;
//     car->inOut = -1;
//     car->entryTime[0] = car->entryTime[1] = car->totalTime = 0;
// }

// // 주차 요금 계산 함수
// int calculateCharge(int totalTime, int fees[]) {
//     if (totalTime <= fees[0]) {
//         return fees[1]; // 기본시간 이하일 경우 기본요금
//     } else {
//         double extraTime = (double)(totalTime - fees[0]) / fees[2];
//         int charge = fees[1] + (int)(extraTime + 0.9999) * fees[3]; // 소수점 아래가 있으면 올림
//         return charge;
//     }
// }

// fees_len은 배열 fees의 길이입니다.
// records_len은 배열 records의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    CarInfo *cars = (CarInfo *)malloc(CAR_NUMBER_MAX * sizeof(CarInfo));
    int size = 0; // 현재 차량 수
    int *answer = NULL;
    int answerIndex = 0;
    int maxCarNum = 0;

    // for (int i = 0; i < CAR_NUMBER_MAX; i++) {
    //     initializeCarInfo(&cars[i], i);
    // }

    for (int i = 0; i < records_len; i++) {
        int hour = toInteger(records[i], 0, 2);
        int minute = toInteger(records[i], 3, 2);
        int carNum = toInteger(records[i], 6, 4);
        char inAndOut = records[i][INOUT];

        CarInfo *currentCar = &cars[carNum];
        if (maxCarNum < carNum) maxCarNum = carNum; // 최대 번호 업데이트

        if (inAndOut == 'I') { // 입차 일 때
            currentCar->inOut = IN;
            currentCar->entryTime[HOUR] = hour;
            currentCar->entryTime[MIN] = minute;
            size++;
        } else { // 출차 일 때
            int timeDiff;

            if (currentCar->entryTime[HOUR] == hour) {
                timeDiff = minute - currentCar->entryTime[MIN];
            } else {
                timeDiff = (60 - currentCar->entryTime[MIN]) + (hour - (currentCar->entryTime[HOUR] + 1)) * 60 + minute;
            }

            currentCar->inOut = OUT;
            currentCar->totalTime += timeDiff;
        }
    }

    // 차량수만큼 동적할당
    answer = (int *)malloc(size * sizeof(int));

    for (int i = 0; i <= maxCarNum; i++) {
        if (cars[i].inOut == 1) { // 아직 입차한 차량이 있다면
            cars[i].totalTime += (24 - cars[i].entryTime[HOUR] - 1) * 60 + (59 - cars[i].entryTime[MIN]);
        }

        if (cars[i].totalTime > 0) { // 주차시간이 있는 차량만 고려
            if (cars[i].totalTime <= fees[0]) {
                answer[answerIndex++] = fees[1]; // 기본시간 이하일 경우 기본요금
            } else {
                double extraTime = (double)(cars[i].totalTime - fees[0]) / fees[2];
                if (extraTime > (int)extraTime) extraTime = (int) extraTime + 1;
                answer[answerIndex++] = fees[1] + extraTime * fees[3];
            }
        }
    }

    free(cars);

    return answer;
}