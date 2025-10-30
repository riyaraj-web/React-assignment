import java.util.Scanner
import java.util.ArrayDeque

class Graph(private val n: Int) {
    private val g = Array(n) { mutableListOf<Int>() }
    fun add(u: Int, v: Int) { g[u].add(v); g[v].add(u) }

    fun bfs(s: Int): List<Int> {
        val vis = BooleanArray(n)
        val q: ArrayDeque<Int> = ArrayDeque()
        val ord = mutableListOf<Int>()
        vis[s] = true; q.add(s)
        while (q.isNotEmpty()) {
            val u = q.removeFirst(); ord += u
            for (v in g[u]) if (!vis[v]) { vis[v] = true; q.add(v) }
        }
        return ord
    }
    fun dfs(s: Int): List<Int> {
        val vis = BooleanArray(n); val ord = mutableListOf<Int>()
        fun go(u: Int) {
            vis[u] = true; ord += u
            for (v in g[u]) if (!vis[v]) go(v)
        }
        go(s); return ord
    }
}

fun main() {
    val sc = Scanner(System.`in`)
    // input: n m, then m edges (0-indexed u v), then start
    val n = sc.nextInt()
    val m = sc.nextInt()
    val gr = Graph(n)
    repeat(m) { gr.add(sc.nextInt(), sc.nextInt()) }
    val start = sc.nextInt()
    println("BFS: " + gr.bfs(start).joinToString(" "))
    println("DFS: " + gr.dfs(start).joinToString(" "))
}
