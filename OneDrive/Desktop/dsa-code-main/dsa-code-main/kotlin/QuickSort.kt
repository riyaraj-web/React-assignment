import java.util.Scanner

fun quickSort(a: IntArray, l: Int = 0, r: Int = a.lastIndex) {
    if (l >= r) return
    var i = l
    var j = r
    val pivot = a[(l + r) ushr 1]
    while (i <= j) {
        while (a[i] < pivot) i++
        while (a[j] > pivot) j--
        if (i <= j) { val t = a[i]; a[i] = a[j]; a[j] = t; i++; j-- }
    }
    quickSort(a, l, j)
    quickSort(a, i, r)
}

fun main() {
    val sc = Scanner(System.`in`)
    // input: n then n integers
    val n = sc.nextInt()
    val arr = IntArray(n) { sc.nextInt() }
    quickSort(arr)
    println(arr.joinToString(" "))
}
