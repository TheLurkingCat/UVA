#include <stdio.h>

#define min(x, y) (x) > (y) ? (y) : (x)
int main() {
    int t;
    char c;
    scanf("%d", &t);
    getchar();
    while (t--) {
        int count[26] = {};
        while ((c = getchar()) != '\n')
            count[c - 65]++;
        int ans;
        ans = min(100, count[12]);
        ans = min(ans, count[0] / 3);
        ans = min(ans, count[17] / 2);
        ans = min(ans, count[6]);
        ans = min(ans, count[19]);
        ans = min(ans, count[8]);
        printf("%d\n", ans);
    }
    return 0;
}
