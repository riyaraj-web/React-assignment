# Problem Statement

# Given an unsorted array of integers nums and an integer k, find the k-th largest element in the array.
# The k-th largest element is the element that would appear in position len(nums) - k if the array were sorted in descending order. 

#Approach:
#We use a min-heap of size k to efficiently keep track of the k largest elements seen so far.

# Steps:

# ->Build a min-heap with the first k elements of the array.
# -> For each remaining element in nums[k:]:
# ->If the element is greater than the smallest in the heap (heap[0]),
# ->remove the smallest (heappop) and insert the new element (heappush).
# ->After processing all elements, the smallest element in the heap (heap[0]) is the k-th largest element.

import heapq

def KthLargest(nums, k):
    
    heap = nums[:k]
    heapq.heapify(heap)  #converts list to min-heap
   
    for num in nums[k:]:
        if num > heap[0]:  
            heapq.heappushpop(heap, num)

    #at last root element is the kth-largest element
    return heap[0]


nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
k = 4
result = KthLargest(nums, k)
print(f"The {k}th largest element is:", result)
