/*
* Author: JorgeSLime     
* Problem: B. Interesting drink
* Contest: Codeforces Round 367 (Div. 2)
* Judge: Codeforces
* URL: https://codeforces.com/contest/706/problem/B
* Memory Limit: 256
* Time Limit: 2000
* Start: sáb 13 abr 2024 23:33:15
* */
//THINK ONCE, CODE TWICE
#include <bits/stdc++.h>
using namespace std;
 
#define sz(x)     ((int)x.size())
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define pb      		push_back
#define eb           emplace_back
#define LN                   '\n'
 
using ll=int64_t;
template<typename T> using V=vector<T>;
template <class T, class F>
T find_first(T l, T r, F&& f) {
    --l,++r;
    while (r - l > 1) {
        T m =l+(r-l)/2;
        if (f(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}
int bs(const V<int>& a, int x) {
    auto f = [&](int i)->bool{
        return a[i] <= x;    //lower -> a[i]<x  | upper-> a[i]<=x
    };
    int n = (int)a.size();
    int pos = find_first(0,n-1,f);
    //if (pos==n||a[pos]!=x) return n;
    return pos;
}
void solve(){
    int n; cin>>n; 
    V<int> v(n);
    for(auto &i:v) cin>>i; 
    sort(all(v)); 
    int q; cin>>q;
    while(q--){
        int x; cin>>x; 
        cout<<(bs(v,x))<<LN;
    }
    
}
auto main()->int32_t{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    ll t=1; 
    //cin>>t;
    for(;t--;) solve();
    return 0;
}
