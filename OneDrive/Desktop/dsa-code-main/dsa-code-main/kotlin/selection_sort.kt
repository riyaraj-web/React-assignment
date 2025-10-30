fun selectionSort(arr: IntArray) {
    val n = arr.size
    for (i in 0 until n - 1) {
        // Find the minimum element in unsorted array
        var minIndex = i
        for (j in i + 1 until n) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j
            }
        }
        // Swap the found minimum element with the first element
        val temp = arr[i]
        arr[i] = arr[minIndex]
        arr[minIndex] = temp
    }
}

fun main() {
    print("Enter number of elements: ")
    val n = readln().toInt()

    val arr = IntArray(n)
    println("Enter elements:")
    for (i in 0 until n) {
        arr[i] = readln().toInt()
    }

    println("Original array: ${arr.joinToString(" ")}")
    selectionSort(arr)
    println("Sorted array:   ${arr.joinToString(" ")}")
}
