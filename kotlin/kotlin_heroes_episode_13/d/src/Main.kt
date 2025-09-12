import kotlin.math.*

private fun readInt() = readln().toLong()
private fun readInts() = readln().split(" ").map { it.toLong() }

fun solution() {
    val nk = readInts()
    val n = nk[0]
    val k = nk[1]
    var a = readInts().sorted().toLongArray()
    var all_cost = 0L
    var coins = 0L
    var mmax = a.last()
    var mmin = a.first()
    var was_equal = false
    if (mmax == mmin) {
        mmax += 1
        all_cost += 1L
        a[n.toInt() - 1] += 1L
        was_equal = true
    }
    for (i in 1..(n.toInt() - 2)) {
        var holder = a[i]
        if (holder == mmin) {
            holder += 1
            all_cost += 1
        }
        val delta = mmax - holder
        all_cost += delta
        coins += delta
    }

    all_cost += mmax - mmin
    if (all_cost > k) {
        if (was_equal) {
            println(0)
        } else {
            println(-1)
        }
        return
    }
    val restk: Long = k - all_cost
    val iters: Long = (restk) / n
    coins += max((iters ) * (n-1), 0L)
    println(coins)


}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t -= 1
    }
}