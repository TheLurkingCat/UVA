#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, n, t, k;

    scanf("%d", &n);

    while (n--) {
        char a[25] = {0}, b[25] = {0};

        i = 0;

        scanf("%s", a);
        strcpy(b, a);

        k = strlen(a);
        for (t = 0; t <= k; t++) {
            b[k - t - 1] = a[t];
        }

        do {
            sprintf(a, "%lld", atoll(a) + atoll(b));
            k = strlen(a);
            for (t = 0; t <= k; t++) {
                b[k - t - 1] = a[t];
            }
            i++;
        } while (strcmp(a, b) != 0);

        printf("%d %s\n", i, a);
    }
    return 0;
}
