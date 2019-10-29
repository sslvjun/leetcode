#define MAX(a, b)  ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char * s){
    int n = strlen(s);
    int ans = 0;
    int index[128] = {0};
    int i, j;
    
    for (j = 0, i = 0; j < n; j++) {
        i = MAX(index[s[j]], i);
        ans = MAX(ans, j - i + 1);
        index[s[j]] = j + 1;
    }
    
    return ans;
}
