n = int(input())
m = int(input())
store = [0]
dp = [[0 for i in range(20)] for j in range(10)]
for i in range(n):
    store.append(int(input()))

for i in range(1, m+1):
    if store[1] >= i:
        dp[1][i] = 1
    else:
        dp[1][i] = 0
for i in range(1, n+1):
    dp[i][0] = 1

print(dp)
for i in range(2, n+1):
    for j in range(m+1):
        # 前i种 挑j枝
        if j - store[i] < 0:
            tmp = j
        else:
            tmp = store[i]
        for k in range(tmp+1):
            dp[i][j] += dp[i-1][j-k]

print(dp[n][m])
# n种 每种store[i]枝 挑m枝 求方案数 dp[i][j] 前i种 一共挑j枝的方案数