#include <stdio.h>
#include <string.h>

int main(void) {
    char s[100001], t[100001], res[100001];
    
    if (scanf("%100000s%100000s", s, t) != 2) return 0;

    size_t len = strlen(s);
    for (size_t i = 0; i < len; ++i) {
       
        res[i] = ((s[i] - '0') ^ (t[i] - '0')) + '0';
    }
    res[len] = '\0';
    printf("%s\n", res);
    return 0;
}
