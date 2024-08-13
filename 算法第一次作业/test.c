#include "stdio.h"

char re[1000000];

void fun(int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int mid = (l + r) / 2;
    re[mid] = '1';
    fun(l, mid - 1);
    fun(mid + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    fun(2, n-1);
    re[1] = '1';
    re[n] = '1';
    for (int i = 1; i <= n; i++) {
        if (re[i] == '1') {
            printf("1");
        } else {
            printf("0");
        }
    }
    return 0;
}