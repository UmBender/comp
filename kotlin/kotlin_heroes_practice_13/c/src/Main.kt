private fun readStr() = readln()
private fun readStrs() = readStr().split(" ")
private fun readInt() = readStr().toInt()
private fun readInts() = readStr().split(" ").map { it.toInt() }


fun solution() {
    var a = readStr()
    val lower = mutableListOf<Int>()
    val upper = mutableListOf<Int>()
    for (i in 0..<a.length) {
        if (a[i].isUpperCase()) {
            if (a[i] == 'B') {
                if (!upper.isEmpty()) {
                    upper.removeLast()
                }
            } else {
                upper.add(i)
            }
        } else {
            if (a[i] == 'b') {
                if (!lower.isEmpty()) {
                    lower.removeLast()
                }
            } else {
                lower.add(i)
            }
        }
    }
    var result = mutableListOf<Char>()
    var i = 0
    var j = 0
    while (i < upper.size && j < lower.size) {
        if (upper[i] < lower[j]) {
            result.add(a[upper[i]])
            i++
        } else {
            result.add(a[lower[j]])
            j++

        }

    }
    while (i < upper.size) {
        result.add(a[upper[i]])
        i++

    }

    while (j < lower.size) {
        result.add(a[lower[j]])
        j++
    }
    println(result.toCharArray().joinToString(separator = ""))
}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t--
    }

}