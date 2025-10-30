import heapq

def dijkstra(graph, start_node):
    # Initialize distances: all to infinity, start_node to 0
    distances = {node: float('inf') for node in graph}
    distances[start_node] = 0
    
    # Priority queue: stores (distance, node)
    priority_queue = [(0, start_node)]
    
    # Stores the path (parent node)
    predecessors = {node: None for node in graph}
    
    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        
        # Ignore if we found a shorter path to current_node already
        if current_distance > distances[current_node]:
            continue
            
        # Explore neighbors
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            
            # If a shorter path is found
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                predecessors[neighbor] = current_node
                heapq.heappush(priority_queue, (distance, neighbor))
                
    return distances, predecessors

# Example Usage: 
# graph = {node: {neighbor: weight, ...}, ...}
example_graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'C': 2, 'D': 5},
    'C': {'D': 1},
    'D': {}
}

shortest_distances, paths = dijkstra(example_graph, 'A')

# print(f"Shortest Distances: {shortest_distances}")
# print(f"Predecessors: {paths}")