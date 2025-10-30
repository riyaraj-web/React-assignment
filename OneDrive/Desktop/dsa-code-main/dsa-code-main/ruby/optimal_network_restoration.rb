# -------------------------------
# Priority Queue (Min Heap)
# -------------------------------
class MinHeap
  def initialize
    @heap = []
  end

  def push(item)
    @heap << item
    sift_up(@heap.size - 1)
  end

  def pop
    return nil if @heap.empty?
    swap(0, @heap.size - 1)
    min = @heap.pop
    sift_down(0)
    min
  end

  def empty?
    @heap.empty?
  end

  private

  def sift_up(i)
    parent = (i - 1) / 2
    return if i <= 0 || @heap[parent][0] <= @heap[i][0]
    swap(i, parent)
    sift_up(parent)
  end

  def sift_down(i)
    left = 2 * i + 1
    right = 2 * i + 2
    smallest = i
    smallest = left if left < @heap.size && @heap[left][0] < @heap[smallest][0]
    smallest = right if right < @heap.size && @heap[right][0] < @heap[smallest][0]
    if smallest != i
      swap(i, smallest)
      sift_down(smallest)
    end
  end

  def swap(i, j)
    @heap[i], @heap[j] = @heap[j], @heap[i]
  end
end

# -------------------------------
# Network Restoration Solver
# -------------------------------
class NetworkRestoration
  def initialize(edges, budget)
    @graph = Hash.new { |h, k| h[k] = [] }
    edges.each do |u, v, cost, time|
      @graph[u] << [v, cost, time]
      @graph[v] << [u, cost, time]
    end
    @budget = budget
  end

  def restore
    pq = MinHeap.new
    pq.push([0, 0, 0, 0]) # [total_cost, total_time, current_node, connected_count]
    visited = {}
    best = [0, 0, 0] # [nodes, cost, time]

    until pq.empty?
      cost, time, node, count = pq.pop
      next if cost > @budget || visited[[node, cost]]
      visited[[node, cost]] = true

      best = [count, cost, time] if count > best[0]

      @graph[node].each do |nbr, c, t|
        new_cost = cost + c
        new_time = time + t
        next if new_cost > @budget
        pq.push([new_cost, new_time, nbr, count + 1])
      end
    end

    best
  end
end

# -------------------------------
# Example Usage
# -------------------------------
edges = [
  [0, 1, 5, 2],
  [0, 2, 10, 3],
  [1, 3, 4, 1],
  [2, 3, 6, 2],
  [3, 4, 3, 2]
]
budget = 14

solver = NetworkRestoration.new(edges, budget)
nodes, total_cost, total_time = solver.restore
puts "Max servers restored: #{nodes}"
puts "Total repair cost: #{total_cost}"
puts "Total repair time: #{total_time}"