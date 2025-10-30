package main

import (
	"fmt"
	"math"
)

func FloydWarshall(graph [][]int, vertices int) [][]int {
	// Create a copy of the graph to store shortest distances
	dist := make([][]int, vertices)
	for i := range graph {
		dist[i] = make([]int, vertices)
		for j := range graph[i] {
			dist[i][j] = graph[i][j]
		}
	}

	// Main Floyd–Warshall algorithm
	for k := 0; k < vertices; k++ {
		for i := 0; i < vertices; i++ {
			for j := 0; j < vertices; j++ {
				if dist[i][k] != math.MaxInt32 && dist[k][j] != math.MaxInt32 &&
					dist[i][k]+dist[k][j] < dist[i][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	return dist
}

func main() {
	var vertices int
	fmt.Print("Enter number of vertices: ")
	fmt.Scan(&vertices)

	graph := make([][]int, vertices)
	fmt.Println("Enter adjacency matrix (use 99999 for infinity):")

	for i := 0; i < vertices; i++ {
		graph[i] = make([]int, vertices)
		for j := 0; j < vertices; j++ {
			fmt.Scan(&graph[i][j])
			if graph[i][j] == 99999 {
				graph[i][j] = math.MaxInt32 // represent infinity
			}
		}
	}

	dist := FloydWarshall(graph, vertices)

	fmt.Println("\nShortest distances between every pair of vertices:")
	for i := 0; i < vertices; i++ {
		for j := 0; j < vertices; j++ {
			if dist[i][j] == math.MaxInt32 {
				fmt.Print("INF ")
			} else {
				fmt.Printf("%3d ", dist[i][j])
			}
		}
		fmt.Println()
	}
}
