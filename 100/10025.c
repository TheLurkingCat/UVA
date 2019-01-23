#include <stdio.h>

int main() {
    int k, n, cases, sum;
    scanf("%d", &cases);

    while (cases--) {
        n = sum = 0;
        scanf("%d", &k);

        if (k == 0) {
            printf("3\n");
            if (cases) printf("\n");
            continue;
        }

        k = k > 0 ? k : -k;

        while (sum < k) sum += (++n);
        if ((sum - k) & 1)
            n += n & 1 ? 2 : 1;

        printf("%d\n", n);

        if (cases) printf("\n");
    }
    return 0;
}