# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def search_range(nums, target)
  len = nums.length - 1
  return [-1, -1] if len.negative?
  return [0, 0] if nums.first == target && len.zero?
  return [-1, -1] if len.zero?

  index = binary_search(nums, target, 0, len)

  return index if index == [-1, -1]

  left_index = right_index = index
  left = index - 1
  right = index + 1

  while nums[left] == target || nums[right] == target
    left_index = left if nums[left] == target && left >= 0
    right_index = right if nums[right] == target
    left -= 1
    right += 1
  end
  [left_index, right_index]
end

def binary_search(array, target, left, right)
  return [-1, -1] if left > right

  mid = left + (right - left) / 2

  if array[mid] == target
    mid
  elsif array[mid] > target
    binary_search(array, target, left, mid - 1)
  else
    binary_search(array, target, mid + 1, right)
  end
end