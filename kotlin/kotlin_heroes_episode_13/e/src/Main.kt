import kotlin.math.*

private fun readInt() = readln().toLong()
private fun readInts() = readln().split(" ").map { it.toLong() }
const val MOD: Long = 998244353

fun zerozero(num: Long): Long {
    var result = 1L
    for (i in 1..num) {
        result *= 2
        result %= MOD
    }
    return result
}

fun one(num: Long): Long {
    var result = 1L
    for (i in 1..num) {
        result *= 2
        result %= MOD
    }
    return result
}

fun interreg(word: String, counter: ArrayList<Long>, power: LongArray): Long {
    var acc = 0L
    for (i in 2..<word.length) {
        if (word[i] == '0') {
            val next = counter.last() - counter[i]
            acc += power[next.toInt()]
            acc %= MOD
            break
        }
        if (word[i] == '1') {
            continue
        }
        if (word[i] == '?') {
            val next = counter.last() - counter[i]
            acc += power[next.toInt()]
            acc %= MOD
        }
    }
    return acc
}

fun solution() {
    var s = readln()
    val power = LongArray(s.length + 1)
    power[0] = 1
    for (i in 1..s.length) {
        power[i] = (2* power[i - 1]) % MOD
    }

    var zeros = 0
    while (zeros < s.length && s[zeros] == '0') {
        zeros += 1
    }
    var counter = 0L
    var poss_counter = arrayListOf<Long>()
    for (i in s) {
        if (i == '?') {
            counter += 1
        }
        poss_counter.add(counter)
    }
    var result = 0L
    when (s.slice(0..1)) {
        "00" -> {
            result = 1
            for (i in 1..counter) {
                result *= 2
                result %= MOD
            }
        }

        "01" -> {
            result = interreg(s, poss_counter, power)
        }

        "0?" -> {
            result = 1
            for (i in 1..<counter) {
                result *= 2
                result %= MOD
            }
            result += interreg(s, poss_counter, power)
            result %= MOD
        }

        "10" -> {
            result = 1
            for (i in 1..counter) {
                result *= 2
                result %= MOD
            }
        }

        "11" -> {
            result = 1
            for (i in 1..counter) {
                result *= 2
                result %= MOD
            }
        }

        "1?" -> {
            result = 1
            for (i in 1..counter) {
                result *= 2
                result %= MOD
            }
        }

        "?0" -> {
            result = 1
            for (i in 1..counter) {
                result *= 2
                result %= MOD
            }
        }

        "?1" -> {
            result = 1
            for (i in 1..<counter) {
                result *= 2
                result %= MOD
            }
            result += interreg(s, poss_counter, power)
            result %= MOD
        }

        "??" -> {
            result = 1
            // 1?
            for (i in 1..<counter) {
                result *= 2
                result %= MOD
            }
            var partial = 1L
            // 00
            for (i in 2..<counter) {
                partial *= 2
                partial %= MOD
            }
            result += partial
            result %= MOD
            result += interreg(s, poss_counter, power)
            result %= MOD

        }

    }
    println(result)
}

fun main() {
    var t = readInt()
    while (t > 0) {
        solution()
        t -= 1
    }

}