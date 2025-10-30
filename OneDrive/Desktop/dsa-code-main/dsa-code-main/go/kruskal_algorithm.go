package main

import (
	"fmt"
	"sort"
)

// Structure to represent an edge
type Edge struct {
	src, dest, weight int
}

// Disjoint Set (Union-Find) structure
type DisjointSet struct {
	parent []int
	rank   []int
}

// Create a new disjoint set with n elements
func NewDisjointSet(n int) *DisjointSet {
	parent := make([]int, n)
	rank := make([]int, n)
	for i := range parent {
		parent[i] = i
	}
	return &DisjointSet{parent, rank}
}

// Find operation with path compression
func (ds *DisjointSet) Find(x int) int {
	if ds.parent[x] != x {
		ds.parent[x] = ds.Find(ds.parent[x])
	}
	return ds.parent[x]
}

// Union operation with union by rank
func (ds *DisjointSet) Union(x, y int) {
	rootX := ds.Find(x)
	rootY := ds.Find(y)

	if rootX != rootY {
		if ds.rank[rootX] < ds.rank[rootY] {
			ds.parent[rootX] = rootY
		} else if ds.rank[rootX] > ds.rank[rootY] {
			ds.parent[rootY] = rootX
		} else {
			ds.parent[rootY] = rootX
			ds.rank[rootX]++
		}
	}
}

// Kruskal’s Algorithm implementation
func KruskalMST(edges []Edge, vertices int) []Edge {
	// Step 1: Sort edges by weight
	sort.Slice(edges, func(i, j int) bool {
		return edges[i].weight < edges[j].weight
	})

	ds := NewDisjointSet(vertices)
	mst := []Edge{}

	// Step 2: Iterate through edges and select those that don’t form cycles
	for _, edge := range edges {
		rootSrc := ds.Find(edge.src)
		rootDest := ds.Find(edge.dest)

		if rootSrc != rootDest {
			mst = append(mst, edge)
			ds.Union(rootSrc, rootDest)
		}

		// Stop when MST has V-1 edges
		if len(mst) == vertices-1 {
			break
		}
	}

	return mst
}

func main() {
	var vertices, edgesCount int
	fmt.Print("Enter number of vertices: ")
	fmt.Scan(&vertices)

	fmt.Print("Enter number of edges: ")
	fmt.Scan(&edgesCount)

	edges := make([]Edge, edgesCount)

	fmt.Println("Enter edges in the format: src dest weight")
	for i := 0; i < edgesCount; i++ {
		fmt.Scan(&edges[i].src, &edges[i].dest, &edges[i].weight)
	}

	mst := KruskalMST(edges, vertices)

	fmt.Println("\nEdges in the Minimum Spanning Tree:")
	totalWeight := 0
	for _, e := range mst {
		fmt.Printf("%d -- %d  == %d\n", e.src, e.dest, e.weight)
		totalWeight += e.weight
	}

	fmt.Printf("Total weight of MST: %d\n", totalWeight)
}
