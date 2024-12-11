import sys

sys.set_int_max_str_digits(0)


def get_base() -> list[list[int]]:
    return [[0, 1], [1, 1]]


def mult(first: list[list[int]], second: list[list[int]]) -> list[list[int]]:
    arr = [[0, 0], [0, 0]]
    for i in range(0, 2):
        for j in range(0, 2):
            for k in range(0, 2):
                arr[i][j] += first[i][k] * second[k][j]
    return arr


def exp_fib(n: int) -> list[list[int]]:
    if n == 1:
        return get_base()

    value = exp_fib(n // 2)
    value = mult(value, value)
    if n % 2 == 1:
        value = mult(value, get_base())
    return value


def fib(n: int) -> int:
    if n == 0:
        return 0
    if n == 1:
        return 1

    value = exp_fib(n)

    return value[1][1]


def fib_linear(n: int) -> int:
    if n == 0:
        return 0
    if n == 1:
        return 1

    a, b = 0, 1

    for _ in range(1, n):
        a, b = b, a + b

    return b


def main():
    print(fib(10_000_000))
    print(fib_linear(10_000_000))


if __name__ == "__main__":
    main()
