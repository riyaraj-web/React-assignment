fn dfs_util(u: usize, adj: &Vec<Vec<usize>>, visited: &mut Vec<bool>, order: &mut Vec<usize>) {
    visited[u] = true;
    order.push(u);
    for &v in &adj[u] {
        if !visited[v] {
            dfs_util(v, adj, visited, order);
        }
    }
}

fn dfs(adj: &Vec<Vec<usize>>, start: usize) -> Vec<usize> {
    let n = adj.len();
    let mut visited = vec![false; n];
    let mut order = Vec::new();
    dfs_util(start, adj, &mut visited, &mut order);
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
    let order = dfs(&adj, 0);
    for v in order {
        println!("{}", v);
    }
}
