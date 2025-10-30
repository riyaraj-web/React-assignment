import java.util.Scanner

fun binarySearch(a: IntArray, x: Int): Int {
    var lo = 0; var hi = a.lastIndex
    while (lo <= hi) {
        val mid = (lo + hi) ushr 1
        if (a[mid] == x) return mid
        if (a[mid] < x) lo = mid + 1 else hi = mid - 1
    }
    return -1
}
fun main() {
    val sc = Scanner(System.`in`)
    // input: n, then n sorted ints, then q queries followed by q targets
    val n = sc.nextInt()
    val a = IntArray(n) { sc.nextInt() }
    val q = sc.nextInt()
    repeat(q) {
        val x = sc.nextInt()
        println(binarySearch(a, x))
    }
}
