#find the longest substring without repeating characters
package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
    lastIndex := make(map[rune]int)
    start, maxLen := 0, 0

    for i, ch := range s {
        if idx, ok := lastIndex[ch]; ok && idx >= start {
            start = idx + 1
        }
        lastIndex[ch] = i
        if i-start+1 > maxLen {
            maxLen = i - start + 1
        }
    }
    return maxLen
}

func main() {
    s := "abcabcbb"
    fmt.Println("Longest substring length:", lengthOfLongestSubstring(s))
}