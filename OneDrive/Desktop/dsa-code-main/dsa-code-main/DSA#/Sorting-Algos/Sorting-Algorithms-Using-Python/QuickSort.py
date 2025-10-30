def quicksort(arr):
    """
    Sorts a list using the Quick Sort algorithm.
    """
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]  # Choosing the first element as the pivot
        less = [x for x in arr[1:] if x < pivot]
        greater = [x for x in arr[1:] if x >= pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

# Example usage:
if __name__ == "__main__":
    unsorted_list = [10, 7, 8, 9, 1, 5, 2, 6, 3, 4]
    print("Unsorted list:", unsorted_list)
    sorted_list = quicksort(unsorted_list)
    print("Sorted list:", sorted_list)

    unsorted_list_2 = [64, 34, 25, 12, 22, 11, 90]
    print("Unsorted list 2:", unsorted_list_2)
    sorted_list_2 = quicksort(unsorted_list_2)
    print("Sorted list 2:", sorted_list_2)