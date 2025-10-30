package main

import (
    "fmt"
)

// merge combines two sorted slices into one sorted slice
func merge(left, right []int) []int {
    result := []int{}
    i, j := 0, 0

    // Compare elements from both slices and pick the smaller one
    for i < len(left) && j < len(right) {
        if left[i] < right[j] {
            result = append(result, left[i])
            i++
        } else {
            result = append(result, right[j])
            j++
        }
    }

    // Add any remaining elements
    result = append(result, left[i:]...)
    result = append(result, right[j:]...)

    return result
}

// mergeSort recursively splits and sorts the array
func mergeSort(arr []int) []int {
    if len(arr) <= 1 {
        return arr
    }

    mid := len(arr) / 2
    left := mergeSort(arr[:mid])
    right := mergeSort(arr[mid:])

    return merge(left, right)
}

func main() {
    var n int
    fmt.Print("Enter number of elements: ")
    fmt.Scan(&n)

    arr := make([]int, n)
    fmt.Println("Enter elements:")
    for i := 0; i < n; i++ {
        fmt.Scan(&arr[i])
    }

    sorted := mergeSort(arr)

    fmt.Println("Sorted array:")
    fmt.Println(sorted)
}
