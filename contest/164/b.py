[n, k] = list(map(int, input().split()))
a = list(map(int, input().split()))
result = [1 if i <= k else 0 for i in a]
print(sum(result))
