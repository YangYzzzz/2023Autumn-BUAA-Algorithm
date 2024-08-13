//
// Created by 86166 on 2023/10/1.
//
#include "stdio.h"
int re = 0, re1 = 0;
void fun(int l, int r) {
    if (l > r) {
        return;
    }
    if (l == r && (l == 1 || l == 2)) {
        re += l;
        return;
    }
    for (int i = l; i <= r; i++) {
        if (i % 3 != 0) {
            re += i;
        }
    }
    int l_new = l % 3 != 0 ? l / 3 + 1 : l / 3;
    int r_new = r / 3;
    fun(l_new, r_new);
}

int fun2(int i) {
    while (i % 3 == 0) {
        i /= 3;
    }
    return i;
}
void fun1(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (i % 3 != 0) {
            re1 += i;
        } else {
            re1 += fun2(i);
        }
    }
}
int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    fun(l, r);
    fun1(l, r);
    printf("%ld %ld", long(re), long(re1));
}