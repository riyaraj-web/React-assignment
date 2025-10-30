// Fenwick Tree (Binary Indexed Tree) - point update, prefix sum
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<long long> f;
    Fenwick(int n=0){init(n);}    
    void init(int n_){n=n_; f.assign(n+1,0);}    
    void add(int i,long long delta){ for(; i<=n; i+=i&-i) f[i]+=delta; }
    long long sum(int i){ long long s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
    long long range_sum(int l,int r){ if(r<l) return 0; return sum(r)-sum(l-1); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Example: maintain an array of size 10
    Fenwick bit(10);
    bit.add(1,5);
    bit.add(3,2);
    bit.add(7,10);
    cout << "prefix sum up to 7 = " << bit.sum(7) << '\n';
    cout << "range sum 2..7 = " << bit.range_sum(2,7) << '\n';
    return 0;
}
