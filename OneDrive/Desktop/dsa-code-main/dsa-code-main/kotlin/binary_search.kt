fun binarySearch(arr: IntArray, target: Int): Int {
    var left = 0
    var right = arr.size - 1

    while (left <= right) {
        val mid = left + (right - left) / 2

        when {
            arr[mid] == target -> return mid        // Element found
            arr[mid] < target -> left = mid + 1     // Search right half
            else -> right = mid - 1                 // Search left half
        }
    }

    return -1 // Element not found
}

fun main() {
    print("Enter number of elements: ")
    val n = readln().toInt()

    val arr = IntArray(n)
    println("Enter elements in sorted order:")
    for (i in 0 until n) {
        arr[i] = readln().toInt()
    }

    print("Enter element to search: ")
    val target = readln().toInt()

    val result = binarySearch(arr, target)

    if (result != -1)
        println("Element found at index $result")
    else
        println("Element not found in array")
}
