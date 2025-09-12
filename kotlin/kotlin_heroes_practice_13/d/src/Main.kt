private fun readStr() = readln()
private fun readStrs() = readStr().split(" ")
private fun readInt() = readStr().toInt()
private fun readInts() = readStr().split(" ").map { it.toInt() }

fun solution() {
    val n = readInt()
    val word: String = readStr()
    val counter = IntArray('z' - 'a' + 1)
    for (i in word) {
        counter[i - 'a']++
    }
    counter.sortDescending()
    var counter_o = 0
    for (i in 1..<counter.size) {
        counter_o += counter[i]
    }
    var mmax = 0
    if (counter_o >= counter[0]) {
        mmax = counter_o + counter[0]
        if (mmax % 2 == 1) {
            mmax--
        }
    } else {
        mmax = counter_o * 2
    }
    println(n - mmax)
}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t--
    }

}