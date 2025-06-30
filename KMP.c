#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void compute_prefix(char *pat, int *prefix, int m) {
    int len = 0;
    prefix[0] = 0;
    for (int i = 1; i < m; i++) {
        while (len > 0 && pat[len] != pat[i])
            len = prefix[len - 1];
        if (pat[len] == pat[i])
            len++;
        prefix[i] = len;
    }
}
void kmp_search(char *txt, char *pat) {
    int n = strlen(txt);
    int m = strlen(pat);
    int *prefix = (int*)malloc(m * sizeof(int));
    compute_prefix(pat, prefix, m);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && txt[i] != pat[j])
            j = prefix[j - 1];
        if (txt[i] == pat[j])
            j++;
        if (j == m) {
            printf("Pattern found at index %d\n", i - m + 1);
            j = prefix[j - 1];
        }
    }
    free(prefix);
}
int main() {
    char txt[] = "AABAACAAADAABAABAABA";
    char pat[] = "AABA";
    kmp_search(txt, pat);
    return 0;
}