//
// Created by 86166 on 2023/10/1.
//
#include "stdio.h"

int a[100][100];
int re[10000];
int k, n;

void merge(int left, int mid, int right) {
    // leftMargin ~ midMargin - 1   midMargin ~ rightMargin - 1
    int leftMargin = left * n, midMargin = mid * n + n, rightMargin = right * n+n;
    int tmp[rightMargin - leftMargin];
    for (int i = leftMargin; i < rightMargin; i++) {
        tmp[i - leftMargin] = re[i]; // 复制一份
    }
    int i = leftMargin, j = midMargin, k1 = 0;
    while (i < midMargin && j < rightMargin) {
        if (tmp[i - leftMargin] > tmp[j - leftMargin]) {
            re[leftMargin + k1] = tmp[j - leftMargin];
            k1++;
            j++;
        } else {
            re[leftMargin + k1] = tmp[i - leftMargin];
            i++;
            k1++;
        }
    }
    while (i < midMargin) {
        re[leftMargin + k1] = tmp[i - leftMargin];
        k1++;
        i++;
    }
    while(j < rightMargin) {
        re[leftMargin + k1] = tmp[j - leftMargin];
        k1++;
        j++;
    }
}

void mergeSort(int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            re[i * k + j] = a[i][j];
        }
    }
    mergeSort(0, k - 1);
    for (int i = 0; i < n*k; i++) {
        printf("%d ", re[i]);
    }
}

