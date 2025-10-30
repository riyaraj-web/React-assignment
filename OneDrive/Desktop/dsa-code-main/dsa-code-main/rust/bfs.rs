use std::collections::VecDeque;

fn bfs(adj: &Vec<Vec<usize>>, start: usize) -> Vec<usize> {
    let n = adj.len();
    let mut visited = vec![false; n];
    let mut order = Vec::new();
    let mut q = VecDeque::new();
    visited[start] = true;
    q.push_back(start);
    while let Some(u) = q.pop_front() {
        order.push(u);
        for &v in &adj[u] {
            if !visited[v] {
                visited[v] = true;
                q.push_back(v);
            }
        }
    }
    order
}

fn main() {
    let adj = vec![
        vec![1, 2],
        vec![0, 3],
        vec![0, 3],
        vec![1, 2, 4],
        vec![3],
    ];
    let order = bfs(&adj, 0);
    for v in order {
        println!("{}", v);
    }
}
