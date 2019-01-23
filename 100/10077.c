#include <stdio.h>

struct fraction {
    int numerator;
    int denominator;
};

int main() {
    int numerator, denominator;
    while (scanf("%d %d", &numerator, &denominator) != -1 && (numerator != 1 || denominator != 1)) {
        struct fraction L = {0, 1}, M = {1, 1}, R = {1, 0};
        long double now = (long double)numerator / denominator;
        while (1) {
            long double right = (long double)M.numerator / M.denominator;
            if (now < right) {
                printf("L");
                R = M;
                M.numerator += L.numerator;
                M.denominator += L.denominator;
            } else if (now > right) {
                printf("R");
                L = M;
                M.numerator += R.numerator;
                M.denominator += R.denominator;
            } else {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}