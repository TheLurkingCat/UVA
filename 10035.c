#include <stdio.h>
int main() {
    int n, m, count, j;
    while (scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
        count = j = 0;

        if (n == 0 && m == 0)
            break;

        while (n != 0 || m != 0) {
            if (n % 10 + m % 10 + j > 9)
                j = 1, count++;
            else
                j = 0;
            n /= 10;
            m /= 10;
        }

        if (count == 0) {
            printf("No carry operation.\n");
        } else if (count == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", count);
        }
    }
}