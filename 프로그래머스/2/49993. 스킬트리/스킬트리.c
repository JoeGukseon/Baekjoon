#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0;

    for (size_t i = 0; i < skill_trees_len; i++) {
        bool isOk = true;
        int curIdx = 0;

        for (size_t j = 0; skill_trees[i][j] != '\0'; j++) {
            char sk = skill_trees[i][j];

            if (sk == skill[curIdx]) {
                if (curIdx < strlen(skill) - 1) {
                    curIdx++;
                }
            } else if (strchr(skill, sk) == NULL) {
            } else {
                isOk = false;
                break;
            }
        }

        if (isOk) {
            answer++;
        }
    }

    return answer;
}