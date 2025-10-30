# Whispering Graph Problem
# ------------------------
# Each node whispers its clarity to neighbors.
# The clarity halves each round, and all whispers accumulate.

def whispering_graph(n, edges, clarities, k)
  # Build adjacency list
  graph = Array.new(n) { [] }
  edges.each do |u, v|
    graph[u] << v
    graph[v] << u
  end

  current = clarities.map(&:to_i)

  k.times do
    new_clarities = Array.new(n, 0)

    n.times do |i|
      whisper_strength = current[i] / 2
      next if whisper_strength == 0  # Optimization — no point whispering 0s

      graph[i].each do |neighbor|
        new_clarities[neighbor] += whisper_strength
      end
    end

    # Accumulate new whispers into current clarity
    n.times { |i| current[i] += new_clarities[i] }
  end

  # Return index of node with highest clarity (smallest index in tie)
  max_value = current.max
  current.index(max_value)
end


# -------------------------
# ✅ Example Usage
# -------------------------
if __FILE__ == $0
  n = 5
  edges = [[0,1],[1,2],[1,3],[3,4]]
  clarities = [10, 5, 2, 8, 1]
  k = 2

  puts whispering_graph(n, edges, clarities, k)  # => 1
end