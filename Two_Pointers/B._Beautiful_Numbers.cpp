/*
Author: JorgeSLime
Problem: B. Beautiful Numbers
Contest: Codeforces Round 604 (Div. 2)
Judge: Codeforces
URL: https://codeforces.com/problemset/problem/1265/B
Memory Limit: 256
Time Limit: 1000
Start: vie 03 may 2024 17:00:44
*/
//THINK ONCE, CODE TWICE
#include <bits/stdc++.h>
using namespace std;

#define sz(x)     ((int)x.size())
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define pb              push_back
#define eb           emplace_back
#define LN                   '\n'

template<typename T> using V=vector<T>;
using ll=long long;
template <class T> constexpr T INF = 0;
template <> constexpr int INF<int> = 1'000'000'000;
template <> constexpr ll INF<ll> = ll(INF<int>) * INF<int> * 2;
template <> constexpr unsigned long long INF<unsigned long long> = INF<ll>;
template <> constexpr __int128 INF<__int128> = __int128(INF<ll>) * INF<ll>;
template <> constexpr double INF<double> = INF<ll>;
template <> constexpr long double INF<long double> = INF<ll>;
void solve(){
    int n; cin>>n; 
    V<int> v(n),p(n,0);
    for(int i=0;i<n;i++){
        int x; cin>>x; 
        p[x-1]=i;
    }
    int L=INF<int>,R=-INF<int>;
    string ans="";
    for(int i=0;i<n;i++){
        L=min(L,p[i]);
        R=max(R,p[i]);
        ans+= (R-L==i)?'1':'0';
    }
    cout<<ans<<LN;
}
auto main()->int32_t{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    ll t=1; 
    cin>>t;
    for(;t--;) solve();
    return 0;
}
