n = int(input())
alist = [0]
blist = [0]
clist = [0]
dp = [[0 for i in range(10)] for j in range(10)]
path = [[0 for k in range(10)] for m in range(10)]
for i in range(n):
    alist.append(int(input()))
    blist.append(int(input()))
    clist.append(int(input()))
for i in range(n+1):
    if i == 0:
        continue
    dp[0][i] = max(dp[1][i-1] + alist[i], dp[2][i-1] + alist[i])
    if dp[1][i-1] + alist[i] > dp[2][i-1] + alist[i]:
        path[0][i] = 1
    else:
        path[0][i] = 2
    dp[1][i] = max(dp[0][i-1] + blist[i], dp[2][i-1] + blist[i])
    if dp[0][i-1] + blist[i] > dp[2][i-1] + blist[i]:
        path[1][i] = 0
    else:
        path[1][i] = 2
    dp[2][i] = max(dp[0][i-1] + clist[i], dp[1][i-1] + clist[i])
    if dp[0][i-1] + clist[i] > dp[1][i-1] + clist[i]:
        path[2][i] = 0
    else:
        path[2][i] = 1
re = max(dp[0][n], dp[1][n], dp[2][n])
if dp[0][n] > dp[1][n] and dp[0][n] > dp[2][n]:
    pos = 0
elif dp[1][n] > dp[2][n]:
    pos = 1
else:
    pos = 2
while n > 0:
    print(pos)
    pos = path[pos][n]
    n -= 1
print(re)