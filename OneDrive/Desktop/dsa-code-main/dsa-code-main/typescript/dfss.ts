function topologicalSort(nodes: string[], edges: [string,string][]): string[] {
    const graph = new Map<string,string[]>();
    nodes.forEach(n => graph.set(n, []));
    edges.forEach(([u,v]) => graph.get(u)!.push(v));

    const visited = new Set<string>();
    const stack: string[] = [];

    function dfs(node: string) {
        visited.add(node);
        for(const nei of graph.get(node)!) {
            if(!visited.has(nei)) dfs(nei);
        }
        stack.push(node);
    }

    for(const node of nodes) {
        if(!visited.has(node)) dfs(node);
    }

    return stack.reverse();
}

// Usage
console.log(topologicalSort(['A','B','C','D'], [['A','B'],['B','C'],['A','C'],['C','D']]));
// ['A','B','C','D']
