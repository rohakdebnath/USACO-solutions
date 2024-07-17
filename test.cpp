#include <stdio.h>
#include <stdlib.h>

#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main() {
    int arr[5][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    int *ptr = (int*)&arr[0];
    int (*ptr1)[3] = (int (*)[3])arr[0];

    combi
    printf("%d %d\n", *(ptr + 8), *(*(ptr1 + 1) + 2));
    return 0;
}
        