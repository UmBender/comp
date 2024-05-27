import java.util.Scanner

object Reader {
    val scanner = Scanner(System.`in`)
}

fun readInt(): Int{
    return Reader.scanner.nextInt()
}

fun bs(arr: Array<Int>, target: Int): Int {
    var right: Int = arr.size - 1
    var left = 0
    while(left <= right) {
        val middle = left + (right - left)  / 2
        if(arr[middle] <= target && (middle == arr.size-1 || arr[middle+1]>target)) {
            return middle
        }
        if(arr[middle] > target) {
            right = middle - 1
        }else{
            left = middle + 1
        }

    }
    return -1
}

fun main() {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()
    val x: Array<Int> = Array(n){0}

    for(i in 0..<n) {
       x[i] = scanner.nextInt()
    }

    val days = scanner.nextInt()
    val m: Array<Int> = Array(days){0}
    for(i in 0..<days){
        m[i] = scanner.nextInt()
    }

    x.sort()
    for(i in m) {
        val result = bs(x,i)
        if(result == -1) {
            println(0)
        }else {
            println(result + 1)
        }
    }

}