#define MAX(a, b)       ((a) > (b) ? (a) : (b))

int expandAroundCenter(char *s, int left, int right)
{
    int len = strlen(s);
    int L = left, R = right;
    
    while (L >= 0 && R < len && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

char * longestPalindrome(char * s){
    int start = 0, end = 0;
    int len, i;
    char *result = NULL;
    
    if (s == NULL)
        return NULL;
    
    len = strlen(s);
    result = (char *)malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, len + 1);
    
    for (i=0; i<len; i++) {
        int len1, len2, len;
        
        len1 = expandAroundCenter(s, i, i);
        len2 = expandAroundCenter(s, i, i + 1);
        len = MAX(len1, len2);
        
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    
    strncpy(result, s + start, end - start + 1);
    
    return result;
}
