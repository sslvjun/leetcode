#include "common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generatePossibleNextMoves(char * s, int* returnSize){
    int len = strlen(s);
    int i, cnt = 0;
    
    char **result = (char **)malloc(len * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }
    
    memset(result, 0, len * sizeof(char *));
    
    for (i=0; i<len -1; i++) {
        if (s[i] == '+' && s[i + 1] == '+') {
            result[cnt] = (char *) malloc(len + 1);
            if (result[cnt] == NULL) {
                continue;
            }
            
            memset(result[cnt], 0, len + 1);
            strcpy(result[cnt], s);
            result[cnt][i] = '-';
            result[cnt][i + 1] = '-';
            cnt++;
        }
    }
    
    *returnSize = cnt;
    return result;
}
