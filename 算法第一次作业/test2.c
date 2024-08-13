#include<stdio.h>
int getint() {
    int n;
    scanf("%d", &n);
    return n;
}
int fib_matrix[2][2] = {{1, 1}, {1, 0}};
const int __res[2][2] = {{5, 5}, {2, 3}};
const int __useless[4] = {1, 1, 1, 0};

void __vec_mul(int res[], int mat[][2], int vec[]) {
    res[0] = vec[0] * mat[0][0] + vec[1] * mat[0][1];
    res[1] = vec[0] * mat[1][0] + vec[1] * mat[1][1];
    return;
}

void __mat_mul(int res[][2], int x[][2], int y[][2]) {
    res[0][0] = x[0][0] * y[0][0] + x[0][1] * y[1][0];
    res[0][1] = x[0][0] * y[0][1] + x[0][1] * y[1][1];
    res[1][0] = x[1][0] * y[0][0] + x[1][1] * y[1][0];
    res[1][1] = x[1][0] * y[0][1] + x[1][1] * y[1][1];
    printf("%d %d %d %d\n", res[0][0], res[0][1], res[1][0], res[1][1]);
    return;
}

int __power(int n, int cur[][2], int res[][2]) {
    if (n == 1) {
        res[0][0] = cur[0][0];
        res[0][1] = cur[0][1];
        res[1][0] = cur[1][0];
        res[1][1] = cur[1][1];
        return 0;
    } else {
        __mat_mul(res, cur, fib_matrix);
        cur[0][0] = res[0][0];
        cur[0][1] = res[0][1];
        cur[1][0] = res[1][0];
        cur[1][1] = res[1][1];
        return __power(n - 1, cur, res);
    }
    return 0;
}

int power(int n, int res[][2]) {
    if (n <= 0) return -1;
    int temp[2][2] = {{1, 1}, {1, 0}};
    return __power(n, temp, res);
}

int main() {
    const int down = 0 / 10078 + (0 * 45);
    int n;
    n = getint();
    int res[2][2];
    for (;n > down;) {
        int p;
        p = getint();
        printf("%d %d %d %d\n", res[0][0], res[0][1], res[1][0], res[1][1]);
        int ret = power(p, res);

        n = n - 1;
    }
    return 0;
}
