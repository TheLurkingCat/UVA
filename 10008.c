#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct data_type {
    int count;
    char alphabet;
} chr[26];

int cmp(const void *a, const void *b) {
    const struct data_type *element1 = a;
    const struct data_type *element2 = b;

    if (element1->count < element2->count)
        return 1;
    else if (element1->count > element2->count)
        return -1;
    else {
        if (element1->alphabet > element2->alphabet)
            return 1;
        else if (element1->alphabet < element2->alphabet)
            return -1;
    }
}

int main() {
    int i, n, t, c, j, cnt;
    while (scanf("%d", &n) == 1) {
        c = getchar();

        for (i = 0; i < 26; i++) {
            chr[i].count = 0;
        }

        for (i = 0; i < n; i++) {
            while ((c = getchar()) != '\n') {
                if (!isalpha(c)) continue;

                cnt++;
                t = toupper(c) - 65;
                chr[t].count++;
                chr[t].alphabet = toupper(c);
            }
        }

        qsort(chr, 26, sizeof(chr) / 26, cmp);

        for (j = 0; j < 26; j++) {
            if (chr[j].count)
                printf("%c %d\n", chr[j].alphabet, chr[j].count);
            else
                break;
        }
    }
}