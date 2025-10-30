// A* search on a grid (4-neighbour) with Manhattan heuristic
#include <bits/stdc++.h>
using namespace std;

struct Node{int r,c; int g,h;};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R=5,C=7;
    vector<string> grid = {
        ".......",
        "..#....",
        "..#..#.",
        "...#..#",
        "......."
    };
    pair<int,int> start={0,0}, goal={4,6};
    auto heuristic=[&](int r,int c){ return abs(r-goal.first)+abs(c-goal.second); };
    vector<vector<int>> g(R, vector<int>(C, INT_MAX));
    using State = tuple<int,int,int,int>; // f,g,r,c
    priority_queue<State, vector<State>, greater<State>> pq;
    g[start.first][start.second]=0;
    pq.emplace(heuristic(start.first,start.second), 0, start.first, start.second);
    vector<int> dr={-1,1,0,0}, dc={0,0,-1,1};
    bool found=false;
    while(!pq.empty()){
        auto [f, curg, r, c] = pq.top(); pq.pop();
        if(make_pair(r,c)==goal){ cout<<"Path found with cost="<<curg<<"\n"; found=true; break; }
        if(curg!=g[r][c]) continue;
        for(int k=0;k<4;k++){
            int nr=r+dr[k], nc=c+dc[k];
            if(nr<0||nr>=R||nc<0||nc>=C) continue;
            if(grid[nr][nc]=='#') continue;
            int ng = curg+1;
            if(ng<g[nr][nc]){ g[nr][nc]=ng; pq.emplace(ng+heuristic(nr,nc), ng, nr, nc); }
        }
    }
    if(!found) cout<<"No path found\n";
    return 0;
}
