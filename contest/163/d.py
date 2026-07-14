
def main():
    [n, k] = [int(i) for i in input().split()]
    dp0 = [-1] * (k + 1)
    dp1 = [-1] * (k + 1)

    dp0[0] = 0

    for _ in range(n):
        [v, w] = [int(i) for i in input().split()]

        next_dp0 = [-1] * (k + 1)
        next_dp1 = [-1] * (k + 1)

        for j in range(k + 1):
            if dp0[j] != -1 or dp1[j] != -1:
                next_dp0[j] = max(dp0[j], dp1[j])

            if j >= w and dp0[j - w] != -1:
                next_dp1[j] = dp0[j - w] + v

        dp0 = next_dp0
        dp1 = next_dp1

    print(max(max(dp0), max(dp1)))

main()
