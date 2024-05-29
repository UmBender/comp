fun main() {
    val n = readln().toInt()
    var arr = Array(n){Pair(0,0)}
    for(i in 0 until n) {
        val k = readln().split(" ").map{it.toInt()}
        arr[i] = Pair(k[0], k[1])
    }
    val arr1 =arr.sortedWith(compareBy({it.first}, {it.second}))
    var stat = false
    for(i in 1 until n) {
        if(arr1[i].second < arr1[i-1].second) {
            stat = true
            break
        }
    }
    if(stat) {
        println("Happy Alex")
    }else{
        println("Poor Alex")
    }


}
