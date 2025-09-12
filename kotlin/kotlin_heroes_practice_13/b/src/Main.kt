private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


object Items {
    val elements = mutableListOf<Long>(1)
    val mmax = 1000
    init {
        var counter = 1
        var number: Long = 2
        while(counter < mmax){
            if((number % 3L!= 0L) && "$number"["$number".length - 1] != '3') {
                elements.add(number)
                counter++
            }
            number++
        }
    }

}

fun solution() {
    var k = readInt()
    k-=1

    println("${Items.elements[k]}")
}

fun main() {
    var t = readInt()
    while(t > 0){
        solution()
        t--
    }

}