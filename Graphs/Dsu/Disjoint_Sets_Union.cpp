/*
* Author: JorgeSLime     
* Problem: A. Disjoint Sets Union
* Contest: Topic 10 - DSU
* Judge: Codeforces
* URL: https://codeforces.com/group/OyefIGO3t4/contest/447295/problem/A
* Memory Limit: 256
* Time Limit: 1000
* Start: lun 17 jun 2024 16:45:14
* */
//THINK ONCE, CODE TWICE   "写之前要思考"
#include "bits/stdc++.h"
using namespace std;

#define sz(x)       (int)x.size()
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define eb           emplace_back
#define LN                   '\n'

using i32=int32_t;
using i64=int64_t;
template<typename T> using V=vector<T>;
struct unionFind {
  V<int> p;
  unionFind(int n) : p(n, -1) {} //init 
  int findParent(int v) {
    if (p[v] == -1) return v;
    return p[v] = findParent(p[v]);
  }
  bool join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};
auto solve()->void{
    i32 n,m; cin>>n>>m; 
    unionFind dsu(n);
    while(m--){
        string x; cin>>x; 
        if(x=="union"){
            i32 u,v; cin>>u>>v; 
            u--,v--;
            dsu.join(u,v); 
        }
        if(x=="get"){
            i32 u,v; cin>>u>>v; 
            u--,v--;
            cout<<(dsu.findParent(u)==dsu.findParent(v)?"YES":"NO")<<LN;
        }
    }
}
auto main()->signed{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    i32 t=1; 
    //cin>>t;
    for(;t--;) solve();
    return 0;
}
