
    import java.util.*;
public class bellman_ford {


    static class Edge {
        int src, dest, weight;

        Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    int V, E;
    Edge[] edges;

    
    bellman_ford(int v, int e) {
        V = v;
        E = e;
        edges = new Edge[e];
    }

 
    void bellmanFord(int src) {
        int[] dist = new int[V];

       
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        
        for (int i = 1; i < V; ++i) {
            for (int j = 0; j < E; ++j) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int weight = edges[j].weight;

                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        
        for (int j = 0; j < E; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                System.out.println("Graph contains negative weight cycle!");
                return;
            }
        }

       
        printSolution(dist);
    }

    void printSolution(int[] dist) {
        System.out.println("Vertex Distance from Source:");
        for (int i = 0; i < V; ++i)
            System.out.println(i + "\t\t" + dist[i]);
    }

    
    public static void main(String[] args) {
        int V = 5;  
        int E = 8;  

        bellman_ford graph = new bellman_ford(V, E);

        graph.edges[0] = new Edge(0, 1, -1);
        graph.edges[1] = new Edge(0, 2, 4);
        graph.edges[2] = new Edge(1, 2, 3);
        graph.edges[3] = new Edge(1, 3, 2);
        graph.edges[4] = new Edge(1, 4, 2);
        graph.edges[5] = new Edge(3, 2, 5);
        graph.edges[6] = new Edge(3, 1, 1);
        graph.edges[7] = new Edge(4, 3, -3);

        graph.bellmanFord(0);
    }
}

