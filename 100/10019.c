#include <stdio.h>
#include <stdlib.h>

int main() {
    char t[5];
    int i, n;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", t);
        printf("%d %d\n", __builtin_popcount(strtol(t, NULL, 10)), __builtin_popcount(strtol(t, NULL, 16)));
    }

    return 0;
}