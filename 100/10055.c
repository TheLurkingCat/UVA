#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

int main() {
    long long n, m;
    while (scanf("%lld %lld", &n, &m) == 2) {
        printf("%lld\n", abs(m - n));
    }
    return 0;
}