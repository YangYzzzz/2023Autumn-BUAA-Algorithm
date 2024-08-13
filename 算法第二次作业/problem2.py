k = int(input())
n = int(input())
# 最大值为k 长度为n

# 用1初始化
dp = [[1 for j in range(100)] for l in range(100)]

for i in range(2, n + 1):
    for j in range(2, k + 1):
        # 从 1 到 j
        now = 0
        for m in range(1, j + 1):
            if j % m == 0:
                now += dp[i-1][m]
        print("i {}, j {}, dp[i][j] {}".format(i, j, now))
        dp[i][j] = now
re = 0
for i in range(1, k+1):
    re += dp[n][i]
print(re)
