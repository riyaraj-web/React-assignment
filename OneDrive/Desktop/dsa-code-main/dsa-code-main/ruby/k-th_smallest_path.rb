# Ruby solution: K-th smallest on path using persistent segment tree + LCA
# Works for large n, q when Ruby recursion limits are respected.
# If recursion depth issues occur on very deep trees, you might need to convert DFS to iterative,
# or increase stack, but typical contest inputs are fine with 2e5 and a balanced tree.

# Read input helper
def read_ints
  STDIN.gets.split.map!(&:to_i)
end

# ---------- Input ----------
n, q = read_ints
a = [0] + read_ints # 1-indexed values; expects exactly n values

# adjacency
adj = Array.new(n+1) { [] }
(n-1).times do
  u,v = read_ints
  adj[u] << v
  adj[v] << u
end

# ---------- Coordinate Compression ----------
vals = a[1..-1].uniq.sort
compress = {}
vals.each_with_index { |v,i| compress[v] = i+1 } # 1..M
m = vals.length
comp = Array.new(n+1)
(1..n).each { |i| comp[i] = compress[a[i]] }

# ---------- LCA preparation ----------
LOG = (Math.log2(n).floor + 2)
parent = Array.new(LOG) { Array.new(n+1, 0) }
depth = Array.new(n+1, 0)

# ---------- Persistent segment tree structures ----------
# We'll store nodes as arrays with left index, right index, sum.
left = [0] # index 0 is null node
right = [0]
sumt = [0]
# helper to create node
def new_node(left_arr, right_arr, sumt_arr, l_child, r_child, s)
  left_arr << l_child
  right_arr << r_child
  sumt_arr << s
  left_arr.length - 1
end
# create a null root at index 0 (already present)

# update: returns new root index based on prev root, adding 1 at position pos
# recursion limits: careful with Ruby recursion for deep segments, but log M small (~20)
def update(prev, l, r, pos, left_arr, right_arr, sumt_arr)
  if l == r
    # create leaf with sum increased by 1
    return new_node(left_arr, right_arr, sumt_arr, 0, 0, sumt_arr[prev] + 1)
  end
  mid = (l + r) >> 1
  if pos <= mid
    new_left = update(left_arr[prev], l, mid, pos, left_arr, right_arr, sumt_arr)
    # right child same as prev's right
    prev_right = right_arr[prev]
    new_sum = sumt_arr[prev] + 1
    return new_node(left_arr, right_arr, sumt_arr, new_left, prev_right, new_sum)
  else
    prev_left = left_arr[prev]
    new_right = update(right_arr[prev], mid+1, r, pos, left_arr, right_arr, sumt_arr)
    new_sum = sumt_arr[prev] + 1
    return new_node(left_arr, right_arr, sumt_arr, prev_left, new_right, new_sum)
  end
end

# Query k-th using four versions: ru, rv, rw, rpw; l..r range
def query_kth(ru, rv, rw, rpw, l, r, k, left_arr, right_arr, sumt_arr)
  return -1 if k <= 0
  if l == r
    return l
  end
  mid = (l + r) >> 1
  # count in left children
  sum_left = sumt_arr[ left_arr[ru] ] + sumt_arr[ left_arr[rv] ] - sumt_arr[ left_arr[rw] ] - sumt_arr[ left_arr[rpw] ]
  if k <= sum_left
    query_kth(left_arr[ru], left_arr[rv], left_arr[rw], left_arr[rpw], l, mid, k, left_arr, right_arr, sumt_arr)
  else
    query_kth(right_arr[ru], right_arr[rv], right_arr[rw], right_arr[rpw], mid+1, r, k - sum_left, left_arr, right_arr, sumt_arr)
  end
end

# versions per node
version = Array.new(n+1, 0)

# DFS to build parent, depth, version
stack = []
visited = Array.new(n+1, false)
# iterative DFS: push [node, parent]
stack << [1, 0]
parent[0][1] = 0
depth[1] = 0
# We'll do an explicit stack with post-processing to update versions incrementally.
order = []  # DFS order for processing children after parent
while !stack.empty?
  u,p = stack.pop
  next if visited[u]
  visited[u] = true
  parent[0][u] = p
  depth[u] = (p==0 ? 0 : depth[p] + 1)
  order << [u,p]
  adj[u].each do |v|
    stack << [v,u] unless visited[v]
  end
end

# Build binary lifting table
(1...LOG).each do |j|
  (1..n).each do |i|
    parent[j][i] = parent[j-1][ parent[j-1][i] ] || 0
  end
end

# Build versions in order such that parent processed before children.
# The 'order' as built by iterative DFS might visit parent before children if stack LIFO works; 
# but to be safe, process increasing depth order so parent always processed earlier:
order.sort_by! { |(u,p)| depth[u] }
order.each do |u,p|
  if p == 0
    base = 0
  else
    base = version[p]
  end
  version[u] = update(base, 1, m, comp[u], left, right, sumt)
end

# LCA function using binary lifting
def lca(u, v, depth, parent, LOG)
  if depth[u] < depth[v]
    u, v = v, u
  end
  # lift u
  (LOG-1).downto(0) do |j|
    if depth[u] - (1<<j) >= depth[v]
      u = parent[j][u]
    end
  end
  return u if u == v
  (LOG-1).downto(0) do |j|
    if parent[j][u] != parent[j][v]
      u = parent[j][u]
      v = parent[j][v]
    end
  end
  return parent[0][u]
end

# ---------- Answer queries ----------
out_lines = []
q.times do
  typ, u, v, k = read_ints
  if typ == 1
    w = lca(u, v, depth, parent, LOG)
    pw = parent[0][w] || 0
    # versions: version[u], version[v], version[w], version[pw]
    idx = query_kth(version[u], version[v], version[w], (pw == 0 ? 0 : version[pw]), 1, m, k, left, right, sumt)
    # decompress
    out_lines << vals[idx-1].to_s
  else
    # Not implemented: updates if problem variant includes updates.
    out_lines << "0"
  end
end

puts out_lines.join("\n")
