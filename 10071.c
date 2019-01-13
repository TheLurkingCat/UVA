#include <stdio.h>

int main() {
    int v, t;
    while (scanf("%d %d", &v, &t) == 2)
        printf("%d\n", 2 * v * t);
    return 0;
}