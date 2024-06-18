/*
* Author: JorgeSLime     
* Problem: B. Disjoint Sets Union 2
* Contest: Topic 10 - DSU
* Judge: Codeforces
* URL: https://codeforces.com/group/OyefIGO3t4/contest/447295/problem/B
* Memory Limit: 256
* Time Limit: 1000
* Start: lun 17 jun 2024 19:07:24
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
//simple print 
template <class Head, class... Tail>
inline void print(Head &&head, Tail &&...tail) {
    cout << head;
    if constexpr (sizeof...(tail) == 0) cout << '\n';
    else {cout << ' ';print(std::forward<Tail>(tail)...);}
}
//print Vector
template<typename T> inline void print(vector<T>&v){for(int i=0;i<(int)v.size();i++) cout<<v[i]<<" \n"[i==(int)v.size()-1];}
template<typename T> inline void print(vector<T>&v,int n){for(int i=0;i<n;i++) cout<<v[i]<<" \n"[i==(int)v.size()-1];}
template<typename T> inline void print(T v[],int n){for(int i=0;i<n;i++) cout<<v[i]<<" \n"[i==n-1];}
struct unionFind {
    V<int> p,mn,mx,tam;
    unionFind(int n) : p(n), mn(n), mx(n,1){
        iota(all(p),0);
        iota(all(mn),0);
        iota(all(mx),0);
    } //init 
    int findParent(int v) {
        if (p[v] == v) return v;
        return p[v] = findParent(p[v]);
    }
    bool join(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a !=b){
            
        }
        return false;
    }
    unordered_set<int> get() {
        unordered_set<int> c;
        for (int v : xd) {
            c.emplace(findParent(v));
        }
        return c;
    }
};
auto solve()->void{
    i32 n,q; cin>>n>>q;
    unionFind dsu(n);
    while(q--){
        string x; cin>>x; 
        if(x=="union"){
            i32 u,v; cin>>u>>v; 
            u--,v--;
            dsu.join(u,v);
        }
        if(x=="get"){ //min, max, num of elements
            i32 v; cin>>v;
            dsu.findParent(v);
            auto vis=dsu.get();
            for(auto &&i:vis){
                cout<<i+1<<" ";
            }
            cout<<LN;
            //dsu.xd.clear();
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
