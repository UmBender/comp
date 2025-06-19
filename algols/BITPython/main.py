class BIT:
    def __init__(self, base_arr: [int]):
        self.values_arr = [0 for i in range(len(base_arr))]
        self.tree_arr = [0 for i in range(len(base_arr) + 1)]
        for i in range(len(base_arr)):
            self.update(i, base_arr[i])

    def update(self, pos: int, value: int) -> None:
        delta: int = value - self.values_arr[pos]
        self.values_arr[pos] = value
        pos += 1
        while pos < len(self.tree_arr):
            self.tree_arr[pos] += delta
            pos += -pos & pos

    def _internal_qury(self, right: int) -> int:
        acc: int = 0
        right += 1
        while right > 0:
            acc += self.tree_arr[right]
            right -= -right & right
        return acc

    def query(self, left: int, right: int) -> int:
        return self._internal_qury(right) - self._internal_qury(left - 1)


def __main__():
    [n, q] = [i for i in map(int, input().split(" "))]
    base_array = [i for i in map(int, input().split(" "))]
    bit = BIT(base_array)
    while q > 0:
        [opt, ak, bu] = [i for i in map(int, input().split(" "))]
        if opt == 1:
            k = ak
            u = bu
            bit.update(k - 1, u)
        else:
            a = ak - 1
            b = bu - 1
            output = bit.query(a, b)
            print(output)
        q -= 1


if __name__ == "__main__":
    __main__()
