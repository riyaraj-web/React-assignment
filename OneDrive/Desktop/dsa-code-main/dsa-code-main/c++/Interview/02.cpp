#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
    // Initialize two pointers: 'left' at the start and 'right' at the end.
    int left = 0;
    int right = height.size() - 1;
    
    // Initialize the maximum area found so far.
    int max_area = 0;
    
    // The loop continues as long as the two pointers haven't met.
    while (left < right) {
        // Calculate the current height (limiting factor) and width.
        int current_height = std::min(height[left], height[right]);
        int current_width = right - left;
        
        // Calculate the area for the current container.
        int current_area = current_height * current_width;
        
        // Update the maximum area found.
        max_area = std::max(max_area, current_area);
        
        // Key optimization: Move the shorter pointer inwards.
        // The idea is that moving the taller pointer won't increase the height 
        // (which is limited by the shorter pointer) but will decrease the width.
        // Moving the shorter pointer gives a chance to find a taller line 
        // that could potentially form a larger area.
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}