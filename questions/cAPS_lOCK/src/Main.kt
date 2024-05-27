import java.util.*

fun fil(word: String): Boolean {
    if(word[0] in 'A'..'Z'){
        return false
    }
    for(i in 1..<word.length) {
        if(word[i] !in 'A'..'Z') {
            return false
        }

    }
    return true
}

fun main() {
    val scanner = Scanner(System.`in`)
    val palavra = scanner.nextLine()
    when {
        palavra == palavra.uppercase() -> {
            println(palavra.lowercase())
        }
        fil(palavra) -> {
            println(palavra.uppercase()[0].toString() + palavra.lowercase().subSequence(1,palavra.length))
        }
        else -> println(palavra)
    }
}