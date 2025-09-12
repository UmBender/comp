private fun readInt() = readln().toLong()
private fun readInts() = readln().split(" ").map { it.toLong() }


fun solution() {
    val n = readInt()
    val a = readInts().toLongArray()
    var minimal: Long = 1000000000
    val notused = arrayListOf<Long>()
    var pos:Long = 1
    for (i in a) {
        if (i >= minimal) {
            notused.add(pos)
        }
        if (i < minimal) {
            minimal = i
        }
        pos +=1
    }
    println(notused.size)
    println(notused.joinToString(" "))

}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t -= 1
    }

}