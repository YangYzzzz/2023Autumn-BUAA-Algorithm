//
// Created by 86166 on 2023/10/1.
//
#include "stdio.h"

int a[1000], flag[1000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // 0~n 填进 0~n-1
    // 排序 再扫一遍
    for (int i = 0; i < n; i++) {
        flag[a[i]] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (flag[i] == 0) {
            printf("%d", i);
        }
    }
}