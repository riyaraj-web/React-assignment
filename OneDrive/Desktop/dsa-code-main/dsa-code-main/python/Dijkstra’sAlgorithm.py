import heapq

def dijkstra(graph, start):
    pq = [(0, start)]  # (distance, node)
    dist = {node: float('inf') for node in graph}
    dist[start] = 0

    while pq:
        cur_dist, node = heapq.heappop(pq)
        if cur_dist > dist[node]:
            continue
        for nei, weight in graph[node]:
            new_dist = cur_dist + weight
            if new_dist < dist[nei]:
                dist[nei] = new_dist
                heapq.heappush(pq, (new_dist, nei))
    return dist


# Example usage:
graph = {
    'A': [('B', 2), ('C', 5)],
    'B': [('C', 1), ('D', 4)],
    'C': [('D', 1)],
    'D': []
}
print("Shortest Distances:", dijkstra(graph, 'A'))