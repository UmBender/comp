import itertools


def check(word):
    for i in range(0, len(word)//2):
        if not word[i] == word[len(word) - 1 - i]:
            return False
    return True


def check_has_palindrome(word, size):
    for i in range(0, len(word) - size+1):
        if (check(word[i:i+size])):
            return True
    return False


[n, k] = input().split()
n, k = int(n), int(k)
val = input()
# val = "aab"
# k = 2
perm = set(itertools.permutations(val))
counter = len(perm)
# print(perm)
for i in perm:
    if check_has_palindrome(i, k):
        counter -= 1
print(counter)
