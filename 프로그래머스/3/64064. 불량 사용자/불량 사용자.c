#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_ID_LEN 8
#define MAX_BANNED_ID_LEN 8

int isMatch(char *user, char *banned) {
    int len = strlen(user);
    if (len != strlen(banned)) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (banned[i] != '*' && banned[i] != user[i]) {
            return 0;
        }
    }
    return 1;
}

void dfs(char user_id[][MAX_USER_ID_LEN], char banned_id[][MAX_BANNED_ID_LEN],
         int *visited, int depth, int user_count, int banned_count, int *result_set) {
    if (depth == banned_count) {
        int combination[user_count];
        for (int i = 0; i < user_count; i++) {
            combination[i] = visited[i];
        }

        for (int i = 0; i < user_count; i++) {
            if (combination[i]) {
                printf("%s ", user_id[i]);
            }
        }
        printf("\n");
        (*result_set)++;
        return;
    }

    for (int i = 0; i < user_count; i++) {
        if (!visited[i] && isMatch(user_id[i], banned_id[depth])) {
            visited[i] = 1;
            dfs(user_id, banned_id, visited, depth + 1, user_count, banned_count, result_set);
            visited[i] = 0;
        }
    }
}

int solution(char user_id[][MAX_USER_ID_LEN], char banned_id[][MAX_BANNED_ID_LEN],
             int user_count, int banned_count) {
    int result_set = 0;
    int visited[MAX_USER_ID_LEN] = {0};

    dfs(user_id, banned_id, visited, 0, user_count, banned_count, &result_set);

    return result_set;
}

int main() {
    char user_id[][MAX_USER_ID_LEN] = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    char banned_id[][MAX_BANNED_ID_LEN] = {"fr*d*", "abc1**"};
    int user_count = 5;
    int banned_count = 2;

    int result = solution(user_id, banned_id, user_count, banned_count);
    printf("Result: %d\n", result);

    return 0;
}
