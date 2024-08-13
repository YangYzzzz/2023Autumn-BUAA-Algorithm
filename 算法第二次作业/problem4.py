k = int(input())
n = int(input())
a = [0]
for i in range(1, n + 1):
    a.append(int(input()))

dp = [[0 for i in range(100)] for j in range(100)]
sum = 0
for i in range(1, n + 1):
    sum += a[i]
    dp[1][i] = sum % 10

for i in range(2, k+1):
    for j in range(1, n+1):
        if i > j:
            dp[i][j] = -10000
        else:
            tmp = 0
            for m in range(1, j+1):
                tmp += a[j-m+1]
                dp[i][j] = max(dp[i][j], dp[i-1][j-m] + tmp % 10)

print(dp[k][n])
