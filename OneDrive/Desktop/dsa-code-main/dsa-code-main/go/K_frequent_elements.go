#given an integer array nums and integer k, return the k most frequent elements.
package main

import (
    "container/heap"
    "fmt"
)

type Pair struct {
    num, freq int
}
type MinHeap []Pair

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].freq < h[j].freq }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) { *h = append(*h, x.(Pair)) }
func (h *MinHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[:n-1]
    return x
}

func topKFrequent(nums []int, k int) []int {
    freqMap := make(map[int]int)
    for _, n := range nums {
        freqMap[n]++
    }

    h := &MinHeap{}
    heap.Init(h)

    for num, freq := range freqMap {
        heap.Push(h, Pair{num, freq})
        if h.Len() > k {
            heap.Pop(h)
        }
    }

    res := []int{}
    for h.Len() > 0 {
        res = append(res, heap.Pop(h).(Pair).num)
    }

    return res
}

func main() {
    nums := []int{1, 1, 1, 2, 2, 3}
    fmt.Println("Top 2 frequent elements:", topKFrequent(nums, 2))
}