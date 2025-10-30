fun countingSort(arr: IntArray): IntArray {
    if (arr.isEmpty()) return arr

    // Step 1: Find the maximum element to determine range
    val max = arr.maxOrNull() ?: return arr

    // Step 2: Create a count array
    val count = IntArray(max + 1)

    // Step 3: Count the occurrences of each number
    for (num in arr) {
        count[num]++
    }

    // Step 4: Reconstruct the sorted array
    var index = 0
    for (i in count.indices) {
        repeat(count[i]) {
            arr[index++] = i
        }
    }

    return arr
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
    val sorted = countingSort(arr)
    println("Sorted array:   ${sorted.joinToString(" ")}")
}
