from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # Step 1: Sort balloons based on their end position
        points.sort(key=lambda x: x[1])
        
        # Step 2: Initialize first arrow position and counter
        end = points[0][1]
        arrows = 1

        # Step 3: Traverse through all balloons
        for start, finish in points:
            if start > end:
                # Need a new arrow if this balloon starts after last arrow's reach
                arrows += 1
                end = finish

        return arrows


if __name__ == "__main__":
    # Example test case
    points = [[10, 16], [2, 8], [1, 6], [7, 12]]
    
    solution = Solution()
    result = solution.findMinArrowShots(points)
    
    print("Minimum number of arrows needed:", result)
