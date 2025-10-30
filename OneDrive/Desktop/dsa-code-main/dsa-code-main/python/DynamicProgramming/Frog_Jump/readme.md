# 🐸 Frog Jump – DSA Problem

This folder contains four solutions to the classic **Frog Jump** problem, demonstrating a progression from naive recursion to space-optimized dynamic programming.

---

## 📘 Problem Statement

A frog is at the first stone of a river represented by an array `heights[]`. It wants to reach the last stone. The frog can jump either **1 or 2 steps forward**. The cost of a jump is the **absolute difference** in height between the current stone and the destination stone.

**Goal:** Minimize the total cost to reach the last stone.

---

## 🧠 Core Logic

To reach stone `i`, the frog can jump from:
- Stone `i-1` → cost = `dp[i-1] + abs(heights[i] - heights[i-1])`
- Stone `i-2` → cost = `dp[i-2] + abs(heights[i] - heights[i-2])`

---

## 🛠️ Approaches

| File | Approach | Time Complexity | Space Complexity |
|------|----------|------------------|------------------|
| `1_recursion.py` | Naive recursion | O(2^n) | O(n) |
| `2_memoization.py` | Top-down DP | O(n) | O(n) |
| `3_tabulation.py` | Bottom-up DP | O(n) | O(n) |
| `4_space_optimized.py` | DP with constant space | O(n) | O(1) |

---

## 🧪 Sample Input
```python
heights = [10, 30, 40, 20]