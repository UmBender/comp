def main():
    MOD = 1000000000 + 7
    [n, k] = [int(i) for i in input().split()]
    p = [int(i) for i in input().split()]
    dp = [0] * (k + 1)
    dp[0] = 1
    for i in p:
        for rj in range(0, k + 1):
            j = k - rj
            if j + i <= k:
                dp[j + i] += dp[j]
                dp[j + i] =  dp[j + i] % MOD
    print(dp[k])

main()

