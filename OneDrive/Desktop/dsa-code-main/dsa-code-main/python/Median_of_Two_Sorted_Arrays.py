class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        
        left, right = 0, m
        
        while left <= right:
            partition1 = (left + right) // 2
            
            partition2 = (m + n + 1) // 2 - partition1
            
            max_left1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
            max_left2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
            
            min_right1 = float('inf') if partition1 == m else nums1[partition1]
            min_right2 = float('inf') if partition2 == n else nums2[partition2]
            
            if max_left1 <= min_right2 and max_left2 <= min_right1:
                if (m + n) % 2 == 0:
                    return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0
                else:
                    return max(max_left1, max_left2)
            
            elif max_left1 > min_right2:
                right = partition1 - 1
            else:
                left = partition1 + 1
        
        raise ValueError("Input arrays are not sorted")

    def findMedianSortedArrays_bruteforce(self, nums1, nums2):
        merged = []
        i = j = 0
        
        while i < len(nums1) and j < len(nums2):
            if nums1[i] <= nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1
        
        while i < len(nums1):
            merged.append(nums1[i])
            i += 1
        
        while j < len(nums2):
            merged.append(nums2[j])
            j += 1
        
        n = len(merged)
        if n % 2 == 0:
            return (merged[n // 2 - 1] + merged[n // 2]) / 2.0
        else:
            return merged[n // 2]


def test_solution():
    solution = Solution()
    
    test_cases = [
        ([1, 3], [2], 2.0),
        ([1, 2], [3, 4], 2.5),
        ([0, 0], [0, 0], 0.0),
        ([], [1], 1.0),
        ([2], [], 2.0),
        ([1, 3, 8], [7, 9, 10, 11], 8.0),
        ([1, 2, 3, 4], [5, 6, 7, 8], 4.5),
        ([1], [2, 3, 4, 5, 6], 3.5)
    ]
    
    print("Testing Median of Two Sorted Arrays:")
    print("=" * 50)
    
    for i, (nums1, nums2, expected) in enumerate(test_cases, 1):
        result = solution.findMedianSortedArrays(nums1, nums2)
        status = "✓" if abs(result - expected) < 1e-5 else "✗"
        
        print(f"Test {i}: {status}")
        print(f"  Input: nums1 = {nums1}, nums2 = {nums2}")
        print(f"  Expected: {expected}")
        print(f"  Got: {result}")
        print()
    
    print("\nVerifying with brute force approach:")
    print("-" * 40)
    
    for i, (nums1, nums2, expected) in enumerate(test_cases[:5], 1):
        optimal_result = solution.findMedianSortedArrays(nums1, nums2)
        brute_result = solution.findMedianSortedArrays_bruteforce(nums1, nums2)
        
        match = abs(optimal_result - brute_result) < 1e-5
        status = "✓" if match else "✗"
        
        print(f"Test {i}: {status} Optimal: {optimal_result}, Brute: {brute_result}")


if __name__ == "__main__":
    test_solution()