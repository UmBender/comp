private fun readInt() = readln().toLong()
private fun readInts() = readln().split(" ").map { it.toLong() }

fun solution() {
    val nm = readInts()
    val n = nm[0]
    val m = nm[1]

    val a = readInts().toLongArray()
    val b = readInts().toLongArray()
    val elements1 = arrayListOf<Long>()
    val elements2 = arrayListOf<Long>()
    var ni = 0
    var mi = 0
    while (ni < n && mi < m) {
        if (a[ni] == b[mi]) {
            ni += 1
            mi += 1
            continue
        }
        if (a[ni] < b[mi]) {
            elements1.add(a[ni])
            ni += 1
        } else {
            elements2.add(b[mi])
            mi += 1
        }

    }
    while (ni < n) {
        elements1.add(a[ni])
        ni += 1
    }
    while (mi < m) {
        elements2.add(b[mi])
        mi += 1
    }
    var result: Int
    if (elements1.size <= elements2.size) {
        result = elements1.size * 2
    } else {
        result = elements2.size * 2 + 1
    }
    println(result + 1)


}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t -= 1
    }

}