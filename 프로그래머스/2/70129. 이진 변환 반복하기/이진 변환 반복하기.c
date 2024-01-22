#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void decimalToBinary(int decimal, char* binary) {
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
    
    binary[index] = '\0';
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));
    answer[0] = 0;
    answer[1] = 0;

    while (strcmp(s, "1") != 0) {
        answer[0]++;
        int count = 0;

        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') {
                count++;
            }
        }

        answer[1] += count;

        printf("zCnt = %d\n", answer[1]);

        char* temp = (char*)malloc((strlen(s) - count + 1) * sizeof(char));
        count = 0;

        for (int i = 0; i < strlen(s); i++) {
            if (s[i] != '0') {
                temp[count++] = s[i];
            }
        }

        temp[count] = '\0';

        decimalToBinary(strlen(temp), (char*)s);


        free(temp);
    }

    return answer;
}