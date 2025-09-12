private fun readInt() = readln().toLong()
private fun readInts() = readln().split(" ").map { it.toLong() }

// 9 8 32 10
fun main() {
    val n = readInt()
    val operation = arrayListOf<String>()
    val elements = ArrayDeque<Long>()
    for (i in 1..n) {
        if (elements.isEmpty()) {
            operation.add("pushback a[${i - 1}]")
            operation.add("min")
            elements.add(i)
            for(j in (i+1)..n){
                operation.add("pushback a[${j - 1}]")
                operation.add("min")
                elements.add(j)
            }
        } else {
            elements.removeFirst()
            operation.add("popfront")
            while (elements.isNotEmpty()) {
                operation.add("min")
                operation.add("popback")
                elements.removeLast()
            }
        }

    }
    println(operation.size)
    for (i in operation) {
        println(i)
    }


}