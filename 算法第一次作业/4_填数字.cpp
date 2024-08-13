//
// Created by 86166 on 2023/10/1.
//
#include "stdio.h"

int a[1000], max, rightMargin, leftMargin;

void mergeSort(int left, int right) {
    if (left > right || (left == right && a[left] != 0)) {
        return;
    }
    int mid = (left + right) / 2;
    if (a[mid] == 0) {
        if (max < right - left + 1) {
            max = right - left + 1;
            leftMargin = left;
            rightMargin = right;
        }
    } else {
        mergeSort(left, mid - 1);
        mergeSort(mid + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        rightMargin = 0;
        leftMargin = 0;
        max = 0;
        mergeSort(1, n);
        a[(rightMargin + leftMargin) / 2] = i;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}