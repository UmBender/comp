fun trig(height: Int): Int {
    val dup =  (1+height)*height + (height *(height-1))/2
    return dup
}



fun biggest(n: Int): Int {
    var left = 1
    var right = 100000

    while(left <= right) {
        val mid = left + (right - left)/2
        if(trig(mid)<= n && trig(mid+1) > n) {
            return trig(mid)
        }
        if (trig(mid) > n) {
            right = mid -1
        }else{
            left =mid + 1
        }
    }

    return -1

}

fun solution(n: Int): Int {
    var count = 0
    var k = n
    while(2 <= k){
        count +=1
        val s = biggest(k)
        k -= s
    }
    return count

}


fun main() {
    val t = readln().toInt()
    val n = Array(t){0}

    for(i in 0 ..< t){
        val ni  = readln().toInt()
        n[i] = ni
    }
    for(i in 0 ..< t){
        println(solution(n[i]))
    }
}