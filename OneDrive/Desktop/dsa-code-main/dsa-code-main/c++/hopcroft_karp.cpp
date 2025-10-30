// Hopcroft-Karp algorithm for maximum bipartite matching
#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
    int nL, nR; vector<vector<int>> adj; 
    vector<int> dist, pairU, pairV;
    HopcroftKarp(int nL, int nR): nL(nL), nR(nR), adj(nL+1), dist(nL+1), pairU(nL+1,0), pairV(nR+1,0){}
    void addEdge(int u,int v){ adj[u].push_back(v); }
    bool bfs(){
        queue<int>q;
        for(int u=1;u<=nL;u++){
            if(pairU[u]==0){ dist[u]=0; q.push(u);} else dist[u]=INT_MAX;
        }
        bool reachable=false;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: adj[u]){
                if(pairV[v]==0) reachable=true;
                else if(dist[pairV[v]]==INT_MAX){ dist[pairV[v]] = dist[u]+1; q.push(pairV[v]); }
            }
        }
        return reachable;
    }
    bool dfs(int u){
        for(int v: adj[u]){
            if(pairV[v]==0 || (dist[pairV[v]]==dist[u]+1 && dfs(pairV[v]))){
                pairU[u]=v; pairV[v]=u; return true;
            }
        }
        dist[u]=INT_MAX; return false;
    }
    int maxMatching(){
        int result=0;
        while(bfs()){
            for(int u=1;u<=nL;u++) if(pairU[u]==0) if(dfs(u)) result++;
        }
        return result;
    }
};

int main(){
    // Example bipartite graph: left size = 4, right size = 4
    HopcroftKarp hk(4,4);
    hk.addEdge(1,1); hk.addEdge(1,2);
    hk.addEdge(2,1);
    hk.addEdge(3,3);
    hk.addEdge(4,2); hk.addEdge(4,4);
    cout << "Maximum matching = " << hk.maxMatching() << '\n';
    return 0;
}
