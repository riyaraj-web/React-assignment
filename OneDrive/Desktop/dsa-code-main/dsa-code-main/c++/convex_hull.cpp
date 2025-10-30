// Convex Hull - Monotone chain (Andrew) algorithm for 2D points
#include <bits/stdc++.h>
using namespace std;

struct P{ long long x,y; };
long long cross(const P &O, const P &A, const P &B){ return (A.x-O.x)*(B.y-O.y) - (A.y-O.y)*(B.x-O.x); }

int main(){
    vector<P> pts = {{0,0},{1,1},{1,0},{0,1},{2,2},{2,0}};
    sort(pts.begin(), pts.end(), [](const P&a,const P&b){ return a.x<b.x || (a.x==b.x && a.y<b.y); });
    int n=pts.size(); if(n<=1){ cout<<n<<"\n"; return 0; }
    vector<P> H(2*n);
    int k=0;
    // lower hull
    for(int i=0;i<n;i++){
        while(k>=2 && cross(H[k-2], H[k-1], pts[i])<=0) k--;
        H[k++]=pts[i];
    }
    // upper hull
    for(int i=n-2, t=k+1; i>=0; i--){
        while(k>=t && cross(H[k-2], H[k-1], pts[i])<=0) k--;
        H[k++]=pts[i];
    }
    H.resize(k-1);
    cout<<"Convex hull points:"<<"\n";
    for(auto &p: H) cout<<p.x<<" "<<p.y<<"\n";
    return 0;
}
