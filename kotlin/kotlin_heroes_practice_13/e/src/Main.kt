import kotlin.math.max
import kotlin.math.min

private fun readStr() = readln()
private fun readStrs() = readln().split(" ")
private fun readInt() = readln().toInt()
private fun readInts() = readln().split(" ").map { it.toInt() }


class SegTree(base: IntArray) {
    val size = base.size

    val tree = IntArray(size * 4)

    init {
        build(1, 0, size - 1, base)

    }

    fun build(pos: Int, tl: Int, tr: Int, base: IntArray) {
        if (tl == tr) {
            tree[pos] = base[tl]
            return
        }

        val tm = (tl + tr) / 2
        build(pos * 2, tl, tm, base)
        build(pos * 2 + 1, tm + 1, tr, base)
        tree[pos] = tree[pos * 2] and tree[pos * 2 + 1]
    }

    fun query(left: Int, right: Int): Int {
        return query(1, 0, size - 1, left, right)
    }

    fun query(pos: Int, tl: Int, tr: Int, left: Int, right: Int): Int {
        if (tl > right || tr < left) {
            return Int.MAX_VALUE
        }
        if (tl == left && tr == right) {
            return tree[pos]
        }

        val tm = (tl + tr) / 2

        val resultleft = query(pos * 2, tl, tm, left, min(tm, right))
        val resultright = query(pos * 2 + 1, tm + 1, tr, max(left, tm + 1), right)

        return resultleft and resultright
    }
}

fun solution() {
    val n = readInt()
    val a = readInts()
    val q = readInt()
    val segtree = SegTree(a.toIntArray())
    var results = mutableListOf<Int>()
    for (qq in 1..q) {
        val leftk = readInts()
        val real_left = leftk[0] - 1
        var left = leftk[0] - 1
        val k = leftk[1]
        var right = segtree.size - 1
        var partial = -2
        while (left <= right) {
            val middle = (left + right) / 2
            val value = segtree.query(real_left, middle)
            if (value >= k) {
                partial = middle
                left = middle + 1
            } else {
                right = middle - 1
            }

        }
        results.add(partial + 1)
    }
    println(results.joinToString(" "))
}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t--
    }

}