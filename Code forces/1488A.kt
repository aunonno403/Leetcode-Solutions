fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        
        if (x > y) {
            println(y)
            return@repeat
        }
        
        var ans = 0
        var div = y / x
        
        while (div > 0) {
            ans += div % 10
            div /= 10
        }
        
        if (y % x != 0) {
            ans += y % x
        }
        
        println(ans)
    }
}