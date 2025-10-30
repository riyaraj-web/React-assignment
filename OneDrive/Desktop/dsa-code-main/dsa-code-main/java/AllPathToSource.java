import java.util.ArrayList;
import java.util.List;

public class AllPathToSource {
    public static List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> paths = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        helper(graph,0,path,paths);
        return paths;
    }
    public static void helper(int[][] graph,int node,List<Integer> path,List<List<Integer>> paths){
        if(node == graph.length-1){
            paths.add(new ArrayList<>(path));
            return;
        }
        for(int i=0;i<graph[node].length;i++){
            path.add(graph[node][i]);
            helper(graph,graph[node][i],path,paths);
            path.remove(path.size()-1);
        }
    }
    public static void main(String[] args){
        int[][] graph = {{1,2},{3},{3},{}};
        System.out.println(allPathsSourceTarget(graph));
    }
}
