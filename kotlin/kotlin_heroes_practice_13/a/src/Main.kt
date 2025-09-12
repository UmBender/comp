private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun solution() {
    val n = readInt()
    val a = readInts()
    val counter = mutableMapOf<Int,Int>()
    a.forEach { counter[it] = (counter[it] ?: 0) + 1 }
    var target = -1
    for ((i,j) in counter) {
        if(j == 1) {
            target = i
        }

    }
    var position = 0
    for(i in 0..<n){
        if(a[i] == target) {
            position = i
        }
    }
    println("${position + 1}")

}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t--
    }

}